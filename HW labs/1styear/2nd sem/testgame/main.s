; This code is written for STM32F407VG

; Important Note: Backlight should have 5V (in hardware)

; Special Toggle Button in EasyMX



;Implement a simple game using a TFT display and buttons on the STM32F407VG board. The game logic is as follows:



;* A square is initially drawn at a center point specified by registers (R5, R6) on the TFT display.



;* The player can move the square left or right using designated buttons.



;* The objective is to move the square to a target square located at the bottom-right corner of the screen.



;* If the moving square reaches the target square, the "Win" screen should be displayed.



;* If the square hits the edge of the TFT screen, the "Lose" screen should be shown.



;* You are required to complete the following functions: TFT_DrawSquare,TFT_ReDrawSquare,GET_state





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

Red     EQU 0xF800  ; 11111 000000 00000

Green   EQU 0x07E0  ; 00000 111111 00000

Blue    EQU 0x001F  ; 00000 000000 11111

Yellow  EQU 0xFFE0  ; 11111 111111 00000

White   EQU 0xFFFF  ; 11111 111111 11111

Black   EQU 0x0000  ; 00000 000000 00000 



; Define register base addresses

RCC_BASE        EQU     0x40023800

GPIOE_BASE      EQU     0x40021000

GPIOB_BASE      EQU     0x40010C00

GPIOD_BASE		EQU		0x40020C00



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



DELAY_INTERVAL  EQU     0x18604  



__main FUNCTION

    ; Enable clocks for GPIOE

    LDR R0, =RCC_BASE + RCC_AHB1ENR

    LDR R1, [R0]

    ORR R1, R1, #0X1F

    STR R1, [R0]

	



	



    ; Configure GPIOE as General Purpose Output Mode

    LDR R0, =GPIOE_BASE + GPIO_MODER

    LDR R1, =0x55555555  

    STR R1, [R0]



    ; Configure output speed for GPIOE (High Speed)

    LDR R0, =GPIOE_BASE + GPIO_OSPEEDR

    LDR R1, =0xFFFFFFFF  

    STR R1, [R0]





	; Configure GPIOB as General Purpose INput Mode

    LDR R0, =GPIOD_BASE + GPIO_MODER

    LDR R1, =0x00000000 

    STR R1, [R0]



    ; Configure input speed for GPIOB (High Speed)

    LDR R0, =GPIOD_BASE + GPIO_OSPEEDR

    LDR R1, =0xFFFFFFFF  

    STR R1, [R0]

	

	; Configure output speed for GPIOB (PULL Down)

    LDR R0, =GPIOD_BASE + GPIO_PUPDR

    LDR R1, =0xAAAAAAAA  

    STR R1, [R0]

	

    ; Initialize TFT

    BL TFT_Init



    ; Fill screen with color 

    MOV R0, #White

    BL TFT_FillScreen
	
	
	MOV R0, #0       ; X start position (50)
	MOV R1, #110      ; Y position (100)
	MOV R2, #240      ; Length (120 pixels)
	MOV R3, #Black     ; Color (Blue)
	BL TFT_DrawHLine
	
	MOV R0, #0       ; X start position (50)
	MOV R1, #220      ; Y position (100)
	MOV R2, #240      ; Length (120 pixels)
	MOV R3, #Black     ; Color (Blue)
	BL TFT_DrawHLine
	


	


	MOV R0, #80      ; X position (120)
	MOV R1, #0      ; Y start position (40)
	MOV R2, #320      ; Length (150 pixels)
	MOV R3, #Black      ; Color (Red)
	BL TFT_DrawVLine  ; Call the function

	

	MOV R0, #160      ; X position (120)
	MOV R1, #0       ; Y start position (40)
	MOV R2, #320      ; Length (150 pixels)
	MOV R3, #Black      ; Color (Red)
	BL TFT_DrawVLine  ; Call the function




; *************************************************************

; TFT Write Command (R0 = command)

; *************************************************************

TFT_WriteCommand

    PUSH {R1-R2, LR}



    ; Set CS low

    LDR R1, =GPIOE_BASE + GPIO_ODR

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

    LDR R1, =GPIOE_BASE + GPIO_ODR

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

    LDR R1, =GPIOE_BASE + GPIO_ODR

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

; Draw Square Center at (x=R5, y=R6 ,Color=R1)

; *************************************************************

TFT_DrawSquare

    PUSH {R0-R12, LR}

    

	 MOV R8, R1

	

	SUB R1,R5,#5

	ADD R2,R5,#5

	SUB R3,R6,#5

	ADD R4,R6,#5

    ; Set Column Address (0-239)

    MOV R0, #0x2A

    BL TFT_WriteCommand

	MOV R0, R1, LSR #8

    BL TFT_WriteData

	MOV R0, R1

    BL TFT_WriteData

    MOV R0, R2, LSR #8

    BL TFT_WriteData

    MOV R0, R2    ; 239

    BL TFT_WriteData





	

    ; Set Page Address (0-319)

    MOV R0, #0x2B

    BL TFT_WriteCommand

	MOV R0, R3, LSR #8

    BL TFT_WriteData

	MOV R0, R3

    BL TFT_WriteData

    MOV R0, R4, LSR #8

    BL TFT_WriteData

    MOV R0, R4    ; 239

    BL TFT_WriteData



    ; Memory Write

    MOV R0, #0x2C

    BL TFT_WriteCommand



    ; Prepare color bytes

    MOV R1, R8, LSR #8     ; High byte

    AND R2, R8, #0xFF      ; Low byte



    LDR R3, =100

FillLoop2

    ; Write high byte

    MOV R0, R1

    BL TFT_WriteData

    

    ; Write low byte

    MOV R0, R2

    BL TFT_WriteData

    

    SUBS R3, R3, #1

    BNE FillLoop2



    POP {R0-R12, LR}

    BX LR







; *************************************************************

; ReDraw Square Centered at (x=R5, y=R6 ,ColorBackground=R1, ColorSquare=R2,Direction=R7 (0->Nochange,1->Up 2->Down 3->Left 4->right))

; *************************************************************

TFT_ReDrawSquare

	PUSH{R0,LR}

	

	CMP R7,#0

	BEQ SKIP

	CMP R7,#1

	BEQ MOVE_UP

	CMP R7,#2

	BEQ MOVE_DOWN

	CMP R7,#3

	BEQ MOVE_LEFT

	CMP R7,#4

	BEQ MOVE_RIGHT

MOVE_UP

	BL TFT_DrawSquare

	SUB R6,R6,#1

	MOV R1,R2

	BL TFT_DrawSquare

	BL delay

	B SKIP

MOVE_DOWN

	BL TFT_DrawSquare

	ADD R6,R6,#1

	MOV R1,R2

	BL TFT_DrawSquare

	 BL delay

	B SKIP

MOVE_LEFT

	BL TFT_DrawSquare

	SUB R5,R5,#1

	MOV R1,R2

	BL TFT_DrawSquare

	 BL delay

	B SKIP

MOVE_RIGHT

	BL TFT_DrawSquare

	ADD R5,R5,#1

	MOV R1,R2

	BL TFT_DrawSquare

	BL delay

SKIP

	

	pop{R0,PC}





; *************************************************************

; Win screen with Green Color

; *************************************************************

WIN

	; Fill screen with color 

    MOV R0, #Green

    BL TFT_FillScreen




; *************************************************************

; Lose screen with Red Color

; *************************************************************

LOSE 

	; Fill screen with color 

    MOV R0, #Red

    BL TFT_FillScreen









; *************************************************************

; GET STATE  (0->Nochange,1->Up 2->Down 3->Left 4->right) In R7

; *************************************************************

GET_state

	PUSH {R0-R2,LR}

	LDR R0, =GPIOD_BASE + GPIO_IDR

    LDR R1, [R0]

	

	

	TST R1,#(1 << 0)

	MOVNE R7,#1

	BNE END_STATE

	TST R1,#(1 << 1)

	MOVNE R7,#2

	BNE END_STATE

	TST R1,#(1 << 2)

	MOVNE R7,#3

	BNE END_STATE

	TST R1,#(1 << 3)

	MOVNE R7,#4

	BNE END_STATE

	

	

END_STATE



    POP {R0-R2, PC}    



; *************************************************************

; Delay Functions

; *************************************************************

delay

    PUSH {R0, LR}

    LDR R0, =DELAY_INTERVAL

delay_loop

    SUBS R0, R0, #1

    BNE delay_loop

    POP {R0, LR}

    BX LR

; *************************************************************
; TFT_DrawHLine - Draw Horizontal Line
; R0 = x start position
; R1 = y position
; R2 = length
; R3 = color
; *************************************************************
TFT_DrawHLine
    PUSH {R0-R12, LR}
    
    MOV R8, R3            ; Save color to R8
    MOV R4, R0            ; x1 = x_start
    ADD R5, R0, R2        ; x2 = x_start + length
    MOV R6, R1            ; y1 = y_position
    MOV R7, R1            ; y2 = y_position (same as y1 for horizontal line)

    ; Set Column Address (x coordinates)
    MOV R0, #0x2A
    BL TFT_WriteCommand
    MOV R0, R4, LSR #8    ; High byte of x1
    BL TFT_WriteData
    MOV R0, R4            ; Low byte of x1
    BL TFT_WriteData
    MOV R0, R5, LSR #8    ; High byte of x2
    BL TFT_WriteData
    MOV R0, R5            ; Low byte of x2
    BL TFT_WriteData
    
    ; Set Page Address (y coordinates)
    MOV R0, #0x2B
    BL TFT_WriteCommand
    MOV R0, R6, LSR #8    ; High byte of y1
    BL TFT_WriteData
    MOV R0, R6            ; Low byte of y1
    BL TFT_WriteData
    MOV R0, R7, LSR #8    ; High byte of y2
    BL TFT_WriteData
    MOV R0, R7            ; Low byte of y2
    BL TFT_WriteData
    
    ; Memory Write
    MOV R0, #0x2C
    BL TFT_WriteCommand
    
    ; Prepare color bytes
    MOV R1, R8, LSR #8    ; High byte
    AND R2, R8, #0xFF     ; Low byte
    
    ; Calculate total pixels (length)
    MOV R3, R5            ; End position
    SUB R3, R3, R4        ; Subtract start position to get length
    ADD R3, R3, #1        ; Add 1 to include endpoint
    
HLine_Loop
    ; Write high byte
    MOV R0, R1
    BL TFT_WriteData
    
    ; Write low byte
    MOV R0, R2
    BL TFT_WriteData
    
    SUBS R3, R3, #1
    BNE HLine_Loop
    
    POP {R0-R12, LR}
    BX LR

; *************************************************************
; TFT_DrawVLine - Draw Vertical Line
; R0 = x position
; R1 = y start position
; R2 = length
; R3 = color
; *************************************************************
TFT_DrawVLine
    PUSH {R0-R12, LR}
    
    MOV R8, R3            ; Save color to R8
    MOV R4, R0            ; x1 = x_position
    MOV R5, R0            ; x2 = x_position (same as x1 for vertical line)
    MOV R6, R1            ; y1 = y_start
    ADD R7, R1, R2        ; y2 = y_start + length

    ; Set Column Address (x coordinates)
    MOV R0, #0x2A
    BL TFT_WriteCommand
    MOV R0, R4, LSR #8    ; High byte of x1
    BL TFT_WriteData
    MOV R0, R4            ; Low byte of x1
    BL TFT_WriteData
    MOV R0, R5, LSR #8    ; High byte of x2
    BL TFT_WriteData
    MOV R0, R5            ; Low byte of x2
    BL TFT_WriteData
    
    ; Set Page Address (y coordinates)
    MOV R0, #0x2B
    BL TFT_WriteCommand
    MOV R0, R6, LSR #8    ; High byte of y1
    BL TFT_WriteData
    MOV R0, R6            ; Low byte of y1
    BL TFT_WriteData
    MOV R0, R7, LSR #8    ; High byte of y2
    BL TFT_WriteData
    MOV R0, R7            ; Low byte of y2
    BL TFT_WriteData
    
    ; Memory Write
    MOV R0, #0x2C
    BL TFT_WriteCommand
    
    ; Prepare color bytes
    MOV R1, R8, LSR #8    ; High byte
    AND R2, R8, #0xFF     ; Low byte
    
    ; Calculate total pixels (length)
    MOV R3, R7            ; End position
    SUB R3, R3, R6        ; Subtract start position to get length
    ADD R3, R3, #1        ; Add 1 to include endpoint
    
VLine_Loop
    ; Write high byte
    MOV R0, R1
    BL TFT_WriteData
    
    ; Write low byte
    MOV R0, R2
    BL TFT_WriteData
    
    SUBS R3, R3, #1
    BNE VLine_Loop
    
    POP {R0-R12, LR}
    BX LR

    ENDFUNC

    END