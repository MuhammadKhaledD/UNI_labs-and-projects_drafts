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

    AREA MY_ARRAY_DATA, DATA, READWRITE


	IMPORT TFT_DrawObsticle_Top_1
	IMPORT TFT_WriteData
	IMPORT TFT_WriteCommand
	IMPORT TFT_ReDrawObsticle_Top_1
	IMPORT TFT_DrawObsticle_Down_1
	IMPORT TFT_ReDrawObsticle_Down_1
	IMPORT TFT_DrawSquare
    EXPORT __main
	
myArray SPACE 40
;    DCD 200      ; index 0
;    DCD 40       ; index 1
;    DCD 210      ; index 2
;    DCD 50       ; index 3
;    DCD 180      ; index 4
;    DCD 0        ; index 5
;    DCD 240      ; index 6
;    DCD 60       ; index 7
;    DCD 190      ; index 8
;    DCD 30       ; index 9

    AREA RESET, CODE, READONLY
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
		LDR R0, =myArray       ; R0 points to base of myArray

        ; Now write values to the array
        LDR R1, =200
        STR R1, [R0], #4

        LDR R1, =40
        STR R1, [R0], #4

        LDR R1, =210
        STR R1, [R0], #4

        LDR R1, =50
        STR R1, [R0], #4

        LDR R1, =180
        STR R1, [R0], #4

        LDR R1, =0
        STR R1, [R0], #4

        LDR R1, =240
        STR R1, [R0], #4

        LDR R1, =60
        STR R1, [R0], #4

        LDR R1, =190
        STR R1, [R0], #4

        LDR R1, =30
        STR R1, [R0], #4
	
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

    ; Fill screen with color
	push {R0}
	MOV R0, #Black
	BL TFT_FillScreen
	pop {R0}
	;BL TFT_FillbottomGreen
	;BL TFT_FillTopGreen
	
	MOV R5, #100 ;Y of squqre
	MOV R6, #40   ;X of squqre
	MOV R1 , #Pink
	BL TFT_DrawSquare
Restart	
	LDR R2, =myArray
START
	MOV R1 , #Mario
	LDR R7, [R2]  ;Y OF OBSTACLE
	ADD R2, R2, #4
	;MOV R7, #200
	MOV R8, #365  ;X of obstacle
	BL TFT_DrawObsticle_Top_1
	LDR R9, [R2]
	ADD R2, R2, #4
	;MOV R9, #40
	MOV R10, #365	
	BL TFT_DrawObsticle_Down_1
	
MAIN_LOOP	
		;BL GET_state return in R7 1 for pushed and 0 for nonpushed
	BL GET_state
	BL TFT_ReDrawSquare
	BL TFT_ReDrawObsticle_Top_1
	BL TFT_ReDrawObsticle_Down_1
	BL delay
	CMP R8, #-45
	BNE MAIN_LOOP
	
	PUSH{R1}
	LDR R1, =myArray
	ADD R1, R1, #40
	CMP R2, R1
	POP{R1}
	BNE START
	B Restart

    B .

; *************************************************************
; TFT Write Command (R0 = command)
; *************************************************************




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
	
	CMP R11, #0   ; Compare the contents of R0 with VALUE
    BEQ down    ; If R0 == VALUE, branch to LabelName
	
	CMP R11, #1   ; Compare the contents of R0 with VALUE
    BEQ up
	



down
	MOV R1,#Black
	BL TFT_DrawSquare
	MOV R1,#Pink
	
	add R5, #-10 
	
	CMP R5, #10
	BEQ Blink
	
	BL TFT_DrawSquare
	B end_get_states
up
	MOV R1,#Black
	BL TFT_DrawSquare
	MOV R1,#Pink
	
	add R5, #10
	
	CMP R5, #230
	BEQ Blink
	
	BL TFT_DrawSquare
	B end_get_state
	
end_get_states
    pop{LR}
    BX LR






	; *************************************************************
; GET STATE  (0->Nochange,1->Up 2->Down 3->Left 4->Right) In R7
; *************************************************************
GET_state
    PUSH {LR}
    ; Default state (no change)
    MOV R11, #0

    ; Read GPIOB input
    LDR R0, =GPIOB_BASE + GPIO_IDR
    LDR R1, [R0]

    ; Check PB0 (bit 0)
    TST R1, #(1 << 5)
    BNE button0_pressed
	
    ; No button pressed
    B end_get_state

button0_pressed
    MOV R11, #1
    B end_get_state

end_get_state
    POP {PC}
    BX LR
	
	
	
	
delay
    PUSH {R0, LR}
    LDR R0, =DELAY_INTERVAL
delay_loop
    SUBS R0, R0, #1
    BNE delay_loop
    POP {R0, LR}
    BX LR


Blink
	MOV R1,#Black
	BL TFT_DrawSquare
	BL delay
	MOV R1,#Pink
	BL TFT_DrawSquare
	BL delay
	BL Blink
	


    ENDFUNC
	ALIGN
    END