; Pin Connection
; D0-7  =   PA0-7     Data BUS      Put your command or data on this bus
; RD    =   PA8       Read pin      Read from touch screen input
; WR    =   PA9       Write pin     Write data/command to display
; RS/DC    =   PA10      Command pin   Choose command or data to write
; CS    =   PA11      Chip Select   Enable the TFT (active low)
; RST   =   PA12      Reset         Reset the TFT (active low)
; 4 Keys  =   PB0-3     4 Keys
 
 
		AREA TFT, CODE, READONLY


DELAY_INTERVAL   EQU  0x186004

; Define register base addresses
RCC_BASE        EQU     0x40021000
GPIOA_BASE      EQU     0x40010800
GPIOB_BASE      EQU     0x40010C00

; Define register offsets
RCC_APB2ENR     EQU     0x18
GPIO_CRL        EQU     0x00
GPIO_CRH        EQU     0x04
GPIO_IDR        EQU     0x08
GPIO_ODR        EQU     0x0C

; Control Pins on Port A
TFT_RD          EQU     (1 << 8)     ; Read  (PA8)
TFT_WR          EQU     (1 << 9)     ; Write (PA9)
TFT_DC          EQU     (1 << 10)    ; Data/Command (PA10)
TFT_CS          EQU     (1 << 11)    ; Chip Select (PA11)
TFT_RST         EQU     (1 << 12)    ; Reset (PA12)

; Key Pins (PB0-PB3)
KEY1_PIN        EQU     (1 << 0)     ; Key 1 (PB0)
KEY2_PIN        EQU     (1 << 1)     ; Key 2 (PB1)
KEY3_PIN        EQU     (1 << 2)     ; Key 3 (PB2)
KEY4_PIN        EQU     (1 << 3)     ; Key 4 (PB3)
	
	

	EXPORT GPIO_Init
	EXPORT TFT_WriteCommand
	EXPORT TFT_WriteData	
	EXPORT TFT_Init	
	EXPORT TFT_FillScreen
	EXPORT Read_Keys
	EXPORT Delay
	EXPORT PING_PONG_READ_KEYS	
		
; *************************************************************
; GPIO Initialization (for TFT)
; *************************************************************
GPIO_Init
    ; Enable Clock for GPIOA and GPIOB
    LDR R1, =RCC_BASE + RCC_APB2ENR
    LDR R2, [R1]
    ORR R2, R2, #(0x1 << 2)   ; Enable GPIOA clock
    ORR R2, R2, #(0x1 << 3)   ; Enable GPIOB clock
    STR R2, [R1]

    ; Set TFT control pins (PA8, PA9, PA10, PA11, PA12) as output
    LDR R1, =GPIOA_BASE + GPIO_CRH
    LDR R2, [R1]
    ORR R2, R2, #(0x3 << (4 * 8))  ; Set PA8 (RD) as output
    ORR R2, R2, #(0x3 << (4 * 9))  ; Set PA9 (WR) as output
    ORR R2, R2, #(0x3 << (4 * 10)) ; Set PA10 (DC) as output
    ORR R2, R2, #(0x3 << (4 * 11)) ; Set PA11 (CS) as output
    ORR R2, R2, #(0x3 << (4 * 12)) ; Set PA12 (RST) as output
    STR R2, [R1]

	; Set Data Bus (PA0-PA7) as output
    LDR R1, =GPIOA_BASE + GPIO_CRL
    LDR R2, [R1]
    ORR R2, R2, #(0x3 << (4 * 0))  ; Set PA0 as output
    ORR R2, R2, #(0x3 << (4 * 1))  ; Set PA1 as output
    ORR R2, R2, #(0x3 << (4 * 2))  ; Set PA2 as output
    ORR R2, R2, #(0x3 << (4 * 3))  ; Set PA3 as output
    ORR R2, R2, #(0x3 << (4 * 4))  ; Set PA4 as output
    ORR R2, R2, #(0x3 << (4 * 5))  ; Set PA5 as output
    ORR R2, R2, #(0x3 << (4 * 6))  ; Set PA6 as output
    ORR R2, R2, #(0x3 << (4 * 7))  ; Set PA7 as output
    STR R2, [R1]
	
	 ; Set Key Pins (PB0-PB3) as inputs with pull-down resistors
    LDR R1, =GPIOB_BASE + GPIO_CRL
    LDR R2, [R1]
    BIC R2, R2, #(0xF << (4 * 0))  ; Clear configuration for PB0
    ORR R2, R2, #(0x4 << (4 * 0))  ; Set PB0 as input with pull-down
    BIC R2, R2, #(0xF << (4 * 1))  ; Clear configuration for PB1
    ORR R2, R2, #(0x4 << (4 * 1))  ; Set PB1 as input with pull-down
    BIC R2, R2, #(0xF << (4 * 2))  ; Clear configuration for PB2
    ORR R2, R2, #(0x4 << (4 * 2))  ; Set PB2 as input with pull-down
    BIC R2, R2, #(0xF << (4 * 3))  ; Clear configuration for PB3
    ORR R2, R2, #(0x4 << (4 * 3))  ; Set PB3 as input with pull-down
    STR R2, [R1]

	
    BX LR

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
    BIC R2, R2, #0xFF   ; Clear data bits PA0-PA7
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
    BIC R2, R2, #0xFF   ; Clear data bits PA0-PA7
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
    
    ; Reset low (PA12)
    BIC R2, R2, #TFT_RST
    STR R2, [R1]
    BL Delay     ; Delay after reset low
    
    ; Reset high (PA12)
    ORR R2, R2, #TFT_RST
    STR R2, [R1]
    BL Delay     ; Delay after reset high
    
    ; Set Pixel Format (16-bit)
    MOV R0, #0x3A
    BL TFT_WriteCommand
    MOV R0, #0x55
    BL TFT_WriteData

    ; Sleep Out
    MOV R0, #0x11
    BL TFT_WriteCommand
    BL Delay     ; Delay after Sleep Out
    
    ; Enable Color Inversion
    MOV R0, #0x21      ; Command for Color Inversion ON
    BL TFT_WriteCommand

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
    MOV R0, #0xEF      ; 239 (high byte)
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

    ; Memory Write (to start drawing)
    MOV R0, #0x2C
    BL TFT_WriteCommand

    ; Prepare color bytes
    MOV R1, R5, LSR #8     ; High byte (16-bit color)
    AND R2, R5, #0xFF      ; Low byte (16-bit color)

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
; Delay Functions
; *************************************************************
Delay
    PUSH {R0, LR}              ; Save registers
    LDR R0, =DELAY_INTERVAL    ; Load delay interval value into R0
delay_loop
    SUBS R0, R0, #1            ; Decrement R0 and update flags
    BNE delay_loop             ; If R0 is not zero, repeat the loop
    POP {R0, LR}               ; Restore registers
    BX LR                      ; Return from function


; *************************************************************
; Read Key Inputs (Returns in R0: 0=none, 1=key1, 2=key2, 3=key3, 4=key4)
; *************************************************************
Read_Keys
    PUSH {R1, LR}              ; Save registers
    
    LDR R1, =GPIOB_BASE + GPIO_IDR  ; Load GPIOB input data register address
    LDR R2, [R1]               ; Read the value from GPIOB input data register

    ; Check each key pin (PB0-PB3)
    TST R2, #KEY1_PIN          ; Test key1 (PB0) bit
    BEQ CheckKey2              ; If key1 is not pressed, check key2
    MOV R0, #1                 ; If key1 is pressed, return 1
    BX LR                      ; Return

CheckKey2
    TST R2, #KEY2_PIN          ; Test key2 (PB1) bit
    BEQ CheckKey3              ; If key2 is not pressed, check key3
    MOV R0, #2                 ; If key2 is pressed, return 2
    BX LR                      ; Return

CheckKey3
    TST R2, #KEY3_PIN          ; Test key3 (PB2) bit
    BEQ CheckKey4              ; If key3 is not pressed, check key4
    MOV R0, #3                 ; If key3 is pressed, return 3
    BX LR                      ; Return

CheckKey4
    TST R2, #KEY4_PIN          ; Test key4 (PB3) bit
    BEQ NoKeyPressed           ; If key4 is not pressed, no key is pressed
    MOV R0, #4                 ; If key4 is pressed, return 4
    BX LR                      ; Return

NoKeyPressed
    MOV R0, #0                 ; Return 0 if no key is pressed
    POP {R1, LR}               ; Restore registers
    BX LR                      ; Return
	
PING_PONG_READ_KEYS
    PUSH {R2, LR}              ; Save registers
    
    LDR R1, =GPIOB_BASE + GPIO_IDR  ; Load GPIOB input data register address
    LDR R2, [R1]               ; Read the value from GPIOB input data register

    ; Check each key pin (PB0-PB3)
    TST R2, #KEY1_PIN          ; Test key1 (PB0) bit
    BEQ PING_PONG_CheckKey2              ; If key1 is not pressed, check key2
    MOV R0, #1                 ; If key1 is pressed, return 1
    B PING_PONG_CheckKey3                ; Return
;***************************************************
; Read Key Inputs For Ping  Pong Game (Returns in R0 and R1: 0=none, R0 = 1=key1, R0 = 2=key2, R1 = 1=key3, R1 = 2=key4)
;***************************************************
PING_PONG_CheckKey2
    TST R2, #KEY2_PIN          ; Test key2 (PB1) bit
    BEQ NoKeyPressedForPlayer1 ; If key2 is not pressed, check key3
    MOV R0, #2                 ; If key2 is pressed, return 2
    B PING_PONG_CheckKey3                ; Return

NoKeyPressedForPlayer1
    MOV R0, #0                 ; Return 0 if no key is pressed
    ;POP {R1, LR}              ; Restore registers
    ;BX LR 

PING_PONG_CheckKey3
    TST R2, #KEY3_PIN          ; Test key3 (PB2) bit
    BEQ PING_PONG_CheckKey4              ; If key3 is not pressed, check key4
    MOV R1, #1                  ; If key3 is pressed, return 3
    B END_PING_PONG_READ_KEYS   ; Return

PING_PONG_CheckKey4
    TST R2, #KEY4_PIN          ; Test key4 (PB3) bit
    BEQ NoKeyPressedForPlayer2           ; If key4 is not pressed, no key is pressed
    MOV R1, #2                 ; If key4 is pressed, return 4
    B END_PING_PONG_READ_KEYS  ; Return

NoKeyPressedForPlayer2
    MOV R1, #0                 ; Return 0 if no key is pressed
END_PING_PONG_READ_KEYS	
    POP {R2, LR}               ; Restore registers
    BX LR                      ; Return
	
	
	END