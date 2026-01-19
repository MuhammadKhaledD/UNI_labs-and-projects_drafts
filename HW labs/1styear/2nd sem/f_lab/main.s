; This code is written for STM32F407VG
; Important Note: Backlight should have 5V (in hardware)
; Special Toggle Button in EasyMX

; Pin Connection 
;
;   +--------- TFT ---------+
;   |      D0   =  PE0      |
;   |      D1   =  PE1      |
;   |      D2   =  PE2      |
;   |      D3   =  PE3      |
;   |      D4   =  PE4      |
;   |      D5   =  PE5      |
;   |      D6   =  PE6      |
;   |      D7   =  PE7      |
;   |-----------------------|
;   |      RST  =  PE8      |
;   |      BCK  =  PE9      |
;   |      RD   =  PE10     |
;   |      WR   =  PE11     |
;   |      RS   =  PE12     |
;   |      CS   =  PE15     |
;   +-----------------------+

    AREA RESET, CODE, READONLY

    EXPORT __main

;Colors
Red     	EQU 0xF800  ; 11111 000000 00000
Green   	EQU 0x2d20  ; 00000 111111 00000
Blue    	EQU 0x001F  ; 00000 000000 11111
Yellow  	EQU 0xFFE0  ; 11111 111111 00000
White   	EQU 0xFFFF  ; 11111 111111 11111
Black   	EQU 0x0000  ; 00000 000000 00000 
BabyBlue    EQU 0x8ef9
Pink		EQU 0xfe59
Mario		EQU 0xc241

; Define register base addresses
RCC_BASE        EQU     0x40023800
GPIOA_BASE      EQU     0x40020000
GPIOB_BASE      EQU     0x40020400

; Define register offsets
RCC_AHB1ENR     EQU     0x30
GPIO_MODER      EQU     0x00
GPIO_OTYPER     EQU     0x04
GPIO_OSPEEDR    EQU     0x08
GPIO_PUPDR      EQU     0x0C
GPIO_IDR        EQU     0x10
GPIO_ODR        EQU     0x14

; Control Pins on Port E
TFT_RST         EQU     (1 << 8)
TFT_RD          EQU     (1 << 10)
TFT_WR          EQU     (1 << 11)
TFT_DC          EQU     (1 << 12)
TFT_CS          EQU     (1 << 15)

DELAY_INTERVAL  EQU     0x90000 

__main FUNCTION
    ; Enable clocks for GPIOE
    LDR R0, =RCC_BASE + RCC_AHB1ENR
    LDR R1, [R0]
    ORR R1, R1, #0x1F
    STR R1, [R0]

    ; Configure GPIOE as General Purpose Output Mode
    LDR R0, =GPIOA_BASE + GPIO_MODER
    LDR R1, =0x55555555  
    STR R1, [R0]

    ; Configure output speed for GPIOE (High Speed)
    LDR R0, =GPIOA_BASE + GPIO_OSPEEDR
    LDR R1, =0xFFFFFFFF  
    STR R1, [R0]
	
		; Configure GPIOB as General Purpose INput Mode
    LDR R0, =GPIOB_BASE + GPIO_MODER
    LDR R1, =0x00000000 
    STR R1, [R0]

    ; Initialize TFT
    BL TFT_Init
Start
    ; Fill screen with color
	push {R0}
	MOV R0, #Black
	BL TFT_FillScreen
	pop {R0}
	BL TFT_FillbottomGreen
	BL TFT_FillTopGreen
	MOV R5, #100
	MOV R6, #40
	MOV R1 , #Pink
	BL TFT_DrawSquare
MAIN_LOOP	
	;BL GET_state return in R7 1 for pushed and 0 for 
	ADD R9, R9, #1
	BL GET_state
	BL TFT_ReDrawSquare

	LDR R0, =DELAY_INTERVAL
	BL delay
	BL Draw_score
	B MAIN_LOOP

ENDG
	MOV R1 , #Black
	BL TFT_DrawSquare
	
	LDR R0, =DELAY_INTERVAL
	BL delay
	
	MOV R1 , #Pink
	BL TFT_DrawSquare
	
	B ENDG
		
    B .

; *************************************************************
; TFT Write Command (R0 = command)
; *************************************************************
TFT_WriteCommand
    PUSH {R1-R2, LR}

    ; Set CS low
    LDR R1, =GPIOA_BASE + GPIO_ODR
    LDR R2, [R1]
    BIC R2, R2, #TFT_CS
    STR R2, [R1]

    ; Set DC (RS) low for command
    BIC R2, R2, #TFT_DC
    STR R2, [R1]

    ; Set RD high (not used in write operation)
    ORR R2, R2, #TFT_RD
    STR R2, [R1]

    ; Send command (R0 contains command)
    BIC R2, R2, #0xFF   ; Clear data bits PE0-PE7
    AND R0, R0, #0xFF   ; Ensure only 8 bits
    ORR R2, R2, R0      ; Combine with control bits
    STR R2, [R1]

    ; Generate WR pulse (low > high)
    BIC R2, R2, #TFT_WR
    STR R2, [R1]
    ORR R2, R2, #TFT_WR
    STR R2, [R1]

    ; Set CS high
    ORR R2, R2, #TFT_CS
    STR R2, [R1]

    POP {R1-R2, LR}
    BX LR

; *************************************************************
; TFT Write Data (R0 = data)
; *************************************************************
TFT_WriteData
    PUSH {R1-R2, LR}

    ; Set CS low
    LDR R1, =GPIOA_BASE + GPIO_ODR
    LDR R2, [R1]
    BIC R2, R2, #TFT_CS
    STR R2, [R1]

    ; Set DC (RS) high for data
    ORR R2, R2, #TFT_DC
    STR R2, [R1]

    ; Set RD high (not used in write operation)
    ORR R2, R2, #TFT_RD
    STR R2, [R1]

    ; Send data (R0 contains data)
    BIC R2, R2, #0xFF   ; Clear data bits PE0-PE7
    AND R0, R0, #0xFF   ; Ensure only 8 bits
    ORR R2, R2, R0      ; Combine with control bits
    STR R2, [R1]

    ; Generate WR pulse
    BIC R2, R2, #TFT_WR
    STR R2, [R1]
    ORR R2, R2, #TFT_WR
    STR R2, [R1]

    ; Set CS high
    ORR R2, R2, #TFT_CS
    STR R2, [R1]

    POP {R1-R2, LR}
    BX LR

; *************************************************************
; TFT Initialization
; *************************************************************
TFT_Init
    PUSH {R0-R2, LR}

    ; Reset sequence
    LDR R1, =GPIOA_BASE + GPIO_ODR
    LDR R2, [R1]
    
    ; Reset low
    BIC R2, R2, #TFT_RST
    STR R2, [R1]
    BL delay
    
    ; Reset high
    ORR R2, R2, #TFT_RST
    STR R2, [R1]
    BL delay
    
    ; Set Pixel Format (16-bit)
    MOV R0, #0x3A
    BL TFT_WriteCommand
    MOV R0, #0x55
    BL TFT_WriteData

    ; Sleep Out
    MOV R0, #0x11
    BL TFT_WriteCommand
    BL delay
	
	 ;memory accsess
	MOV R0, #0x36       ; MADCTL command
	BL TFT_WriteCommand
	MOV R0, #0x48       ; Parameter value (see explanation below)
	BL TFT_WriteData

    
    ; Display ON
    MOV R0, #0x29
    BL TFT_WriteCommand

    POP {R0-R2, LR}
    BX LR


; *************************************************************
; TFT Fill Screen (R0 = 16-bit color)
; *************************************************************
TFT_FillScreen
    PUSH {R1-R5, LR}

    ; Save color
    MOV R5, R0

    ; Set Column Address (0-239)
    MOV R0, #0x2A
    BL TFT_WriteCommand
    MOV R0, #0x00
    BL TFT_WriteData
    MOV R0, #0x00
    BL TFT_WriteData
    MOV R0, #0x00
    BL TFT_WriteData
    MOV R0, #0xEF      ; 239
    BL TFT_WriteData

    ; Set Page Address (0-319)
    MOV R0, #0x2B
    BL TFT_WriteCommand
    MOV R0, #0x00
    BL TFT_WriteData
    MOV R0, #0x00
    BL TFT_WriteData
    MOV R0, #0x01      ; High byte of 0x013F (319)
    BL TFT_WriteData
    MOV R0, #0x3F      ; Low byte of 0x013F (319)
    BL TFT_WriteData

    ; Memory Write
    MOV R0, #0x2C
    BL TFT_WriteCommand

    ; Prepare color bytes
    MOV R1, R5, LSR #8     ; High byte
    AND R2, R5, #0xFF      ; Low byte

    ; Fill screen with color (320x240 = 76800 pixels)
    LDR R3, =76800
FillLoop
    ; Write high byte
    MOV R0, R1
    BL TFT_WriteData
    
    ; Write low byte
    MOV R0, R2
    BL TFT_WriteData
    
    SUBS R3, R3, #1
    BNE FillLoop

    POP {R1-R5, LR}
    BX LR

	
	
	; *************************************************************
; Fill Top Third (Red)
; *************************************************************

TFT_FillTopGreen
    PUSH {R1-R5, LR}
    MOV R5, #Mario

    ; Set Column (0–239)
    MOV R0, #0x2A
    BL TFT_WriteCommand
    MOV R0, #0x00  ; Start XH
    BL TFT_WriteData
    MOV R0, #0xA0  ; Start XL
    BL TFT_WriteData
    MOV R0, #0x00  ; End XH
    BL TFT_WriteData
    MOV R0, #0xEF  ; End XL (80)
    BL TFT_WriteData

    ; Set Page (0–319)
    MOV R0, #0x2B
    BL TFT_WriteCommand
    MOV R0, #0x00  ; Start YH
    BL TFT_WriteData
    MOV R0, #0x00  ; Start YL
    BL TFT_WriteData
    MOV R0, #0x01  ; End YH
    BL TFT_WriteData
    MOV R0, #0x3F  
    BL TFT_WriteData

    ; Start Memory Write
    MOV R0, #0x2C
    BL TFT_WriteCommand

    MOV R1, R5, LSR #8
    AND R2, R5, #0xFF
    LDR R3, =25600  ; 240 x 80

FillGT
    MOV R0, R1
    BL TFT_WriteData
    MOV R0, R2
    BL TFT_WriteData
    SUBS R3, R3, #1
    BNE FillGT

    POP {R1-R5, LR}
    BX LR


TFT_FillbottomGreen
    PUSH {R1-R5, LR}
    MOV R5, #Mario

    ; Set Column (0–239)
    MOV R0, #0x2A
    BL TFT_WriteCommand
    MOV R0, #0x00  ; Start XH
    BL TFT_WriteData
    MOV R0, #0x00  ; Start XL
    BL TFT_WriteData
    MOV R0, #0x00  ; End XH
    BL TFT_WriteData
    MOV R0, #0x27 ; End XL (80)
    BL TFT_WriteData

    ; Set Page (0–319)
    MOV R0, #0x2B
    BL TFT_WriteCommand
    MOV R0, #0x00  ; Start YH
    BL TFT_WriteData
    MOV R0, #0x00  ; Start YL
    BL TFT_WriteData
    MOV R0, #0x01  ; End YH
    BL TFT_WriteData
    MOV R0, #0x3F  
    BL TFT_WriteData

    ; Start Memory Write
    MOV R0, #0x2C
    BL TFT_WriteCommand

    MOV R1, R5, LSR #8
    AND R2, R5, #0xFF
    LDR R3, =12800  ; 240 x 80

FillGB
    MOV R0, R1
    BL TFT_WriteData
    MOV R0, R2
    BL TFT_WriteData
    SUBS R3, R3, #1
    BNE FillGB

    POP {R1-R5, LR}
    BX LR
	
	; *************************************************************
; Draw Square Center at (y=R5, x=R6 ,Color=R1)
; *************************************************************

; *************************************************************
; ReDraw Square Centered at (x=R5, y=R6 ,ColorBackground=R1, ColorSquare=R2,Direction=R7 (0->Nochange,1->Up 2->Down 3->Left 4->right))
; *************************************************************
TFT_ReDrawSquare
	PUSH{LR}
	
	CMP R7, #0   ; Compare the contents of R0 with VALUE
    BEQ down    ; If R0 == VALUE, branch to LabelName
	
	CMP R7, #1   ; Compare the contents of R0 with VALUE
    BEQ up

down
	MOV R1,#Black
	BL TFT_DrawSquare
	MOV R1,#Pink
	
	add R5, #-10 
	
	CMP R5, #50
	BEQ ENDG
	
	BL TFT_DrawSquare
	B end_get_states
up
	MOV R1,#Black
	BL TFT_DrawSquare
	MOV R1,#Pink
	
	add R5, #10
	
	CMP R5, #150
	BEQ ENDG
	
	BL TFT_DrawSquare
	B end_get_state
	
end_get_states
    pop{LR}
    BX LR


TFT_DrawSquare
    PUSH {LR}
    ;TODO
	MOV R8, R5
    SUB R8, R8, #10      ; x_start
    ADD R10, R5, #10     ; x_end

    MOV R9, R6
    SUB R9, R9, #10      ; y_start
    ADD R11, R6, #10     ; y_end

    ; Set Column Address
    MOV R0, #0x2A
    BL TFT_WriteCommand
    MOV R0, R8, LSR #8
    BL TFT_WriteData
    MOV R0, R8
    BL TFT_WriteData
    MOV R0, R10, LSR #8
    BL TFT_WriteData
    MOV R0, R10
    BL TFT_WriteData

    ; Set Page Address
    MOV R0, #0x2B
    BL TFT_WriteCommand
    MOV R0, R9, LSR #8
    BL TFT_WriteData
    MOV R0, R9
    BL TFT_WriteData
    MOV R0, R11, LSR #8
    BL TFT_WriteData
    MOV R0, R11
    BL TFT_WriteData

    ; Memory Write
    MOV R0, #0x2C
    BL TFT_WriteCommand

    ; Prepare color bytes
    MOV R2, R1, LSR #8  ; High byte
    AND R3, R1, #0xFF   ; Low byte

    ; Write pixels (width = 20, height = 20)
    MOV R4, #400
DrawSquare_Loop
    MOV R0, R2
    BL TFT_WriteData
    MOV R0, R3
    BL TFT_WriteData
    SUBS R4, R4, #1
    BNE DrawSquare_Loop
	

	
	POP {LR}
    BX LR
	
; *************************************************************
; GET STATE  (0->Nochange,1->Up) In R7
; *************************************************************
GET_state
    PUSH {LR}
    ; Default state (no change)
    MOV R7, #0

    ; Read GPIOB input
    LDR R0, =GPIOB_BASE + GPIO_IDR
    LDR R1, [R0]

    ; Check PB0 (bit 0)
    TST R1, #(1 << 5)
    BNE button0_pressed
	
    ; No button pressed
    B end_get_state

button0_pressed
    MOV R7, #1
    B end_get_state

end_get_state
    POP {LR}
    BX LR
	
Draw_score
	PUSH {LR}
	
	; logic for write score
	
	POP {LR}
    BX LR
delay
    PUSH {LR}
    SUBS R0, R0, #1
    BNE delay
    POP {LR}
    BX LR
	

    ENDFUNC
    END