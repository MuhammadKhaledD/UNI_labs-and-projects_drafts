
; Pin Connection
; D0-7  =   PA0-7	Data BUS	    Put your command or data on this bus
; RD    =   PA8		Read pin	    Read from touch screen input 
; WR    =   PA9		Write pin	    Write data/command to display
; RS    =   PA10	Command pin	    Choose command or data to write
; CS    =   PA11	Chip Select	    Enable the TFT,(active low)
; RST   =   PA12	Reset		    Reset the TFT (active low)
; D0-7  =   PB0-3	4 Keys

		
	;TFT
	IMPORT GPIO_Init
    IMPORT TFT_WriteCommand
    IMPORT TFT_WriteData
	IMPORT TFT_Init
    IMPORT TFT_FillScreen
    IMPORT Delay
    IMPORT font_map
	IMPORT Read_Keys
	IMPORT PING_PONG_READ_KEYS	
	;Graphics
	IMPORT Draw_Pixel
    ;IMPORT Draw_Char
	IMPORT Draw_Line
    IMPORT Draw_Rectangle	
    IMPORT Clear_Screen
    IMPORT Init_Screen
    
	EXPORT __main
		
    AREA MYDATA, DATA, READWRITE    ; Declare the GameData section

; ---------- COLORS ----------

Red     EQU 0x001F   ; 00000 000000 11111
Green   EQU 0x07E0   ; 00000 111111 00000
Blue    EQU 0xF800   ; 11111 000000 00000
Yellow  EQU 0x06FF   ; 11111 111111 00000
White   EQU 0xFFFF   ; 11111 111111 11111
Black   EQU 0x0000   ; 00000 000000 00000

; PADDLE DATA

PADDLE_WIDTH         DCW     10
PADDLE_HEIGHT        DCW     40
PADDLE_COLOR         DCW     3
PADDLE_SPEED         DCW     2
						ALIGN
; BALL DATA
BALL_X               DCW     170
BALL_Y               DCW     110
BALL_VELOCITY_X      DCW     2
Ball_VELOCITY_Y      DCW     2
						ALIGN
BALL_COLOR           DCB     0

; SCORE DATA AND LIVES
SCORE                DCB     "SCORE: $"
						ALIGN
SCORE_COUNT_PLAYER_1 DCW     0
SCORE_COUNT_PLAYER_2 DCW     0
						ALIGN
; STRING DATA
string1              DCB     "ONE PLAYER MODE => 2.", 13, 10, "$"
string2              DCB     "CO-OP PING PONG  => 4.", 13, 10, "$"
string3              DCB     "Exit => Esc.", 13, 10, "$"

; ESCAPE STATUS
ESCSTATUS            DCB     0
						ALIGN
; TWO PLAYER MODE PADDLE DATA
PADDLE_COLOR1        DCB     8
PADDLE_COLOR2        DCB     8

PADDLE_X1            DCW     50
PADDLE_Y1            DCW     100

PADDLE_X2            DCW     270
PADDLE_Y2            DCW     100
						

            AREA    MYcode, CODE, READONLY

__main FUNCTION
	
    BL GPIO_Init

    
Options_page
    ; Clear the screen colour
	MOV 	R0, #0x001F
    BL      TFT_FillScreen

;    ; Display option strings
;    MOV     R0, #10                ; Row (approximately 10 for the first string)
;    MOV     R1, #32                ; Column (approximately 32 for horizontal centering)
;    LDR     R2, =string1           ; Load address of first string
;    ;BL      Draw_Msg               ; Print string

;    MOV     R0, #12                ; Row (approximately 12 for the second string)
;    MOV     R1, #30                ; Column (approximately 30 for horizontal centering)
;    LDR     R2, =string2           ; Load address of second string
;    ;BL      Draw_Msg	           ; Print string

;    MOV     R0, #14                ; Row (approximately 14 for third string)
;    MOV     R1, #29                ; Column (approximately 29 for horizontal centering)
;    LDR     R2, =string3           ; Load address of third string
;    ;BL      Draw_Msg	           ; Print string

;    ; Wait for key press

;	BL PING_PONG_MODE

;PING_PONG_MAIN_LOOP 
;	BL PING_PONG_MOVE_PLAYERS
;	
;	
;	ENDFUNC

;PING_PONG_MOVE_PLAYERS
;	;STATE
;	; Read Key Inputs (Returns in R0 and R1: 0=none, R0 = 1=key1, R0 = 2=key2, R1 = 1=key3, R1 = 2=key4)
;	PUSH {R0-R12, LR}

;	BL PING_PONG_READ_KEYS 
;	MOV R7, R1			; STORE THE VALUE OF R1 BECAUSE R1 WILL BE USED IN DRAW_RECT 
;	
;	CMP R0, #1 			; CHECK IF PLAYER 1 IS MOVING DOWN
;	BNE PLAYER_1_UP		; IF NOT, CHECK UP
;	;TODO: CHECK IF THE PLAYER REACHED Y = 240 (END OF SCREEN)
;	LDR R5, =PADDLE_Y1	;TODO: CHECK IF THE PLAYER REACHED Y = 200 (END OF SCREEN)
;	LDRH R1, [R5]
;	CMP R1, #0x200
;	BCS END_MOVE_PLAYER_1
;						; ERASES PLAYER 1 AND REDRAWS PLAYER 1 DOWN 10 PIXELS
;	LDR R5,=Black 		; TODO: CHANGE IF THE BACKGROUND ISN'T BLACK
;	LDRH R0, [R5]
;	LDR R5,=PADDLE_Y1
;	LDRH R1, [R5]
;	MOV R2, R1
;	LDR R6, =PADDLE_HEIGHT
;	LDRH R5, [R6]
;	ADD R2, R5
;	LDR R5,=PADDLE_X1
;	LDRH R3 ,[R5]
;	MOV R4, R3
;	LDR R6, =PADDLE_WIDTH
;	LDRH R5, [R6]
;	ADD R4, R5
;	BL Draw_Rectangle 
;	; DONE ERASING PLAYER 1

;	;NOW REDRAWING BUT Y1 IS INCREASED BY 10
;	LDR R5,=PADDLE_COLOR1
;	LDRH R0, [R5]
;	LDR R5,=PADDLE_Y1
;	LDRH R1, [R5]
;	ADD R1, R1,#0x10	;ADDING 10 DECIMAL TO Y1
;	STRH R1, [R5]	;STORING THE NEW POSITION OF PLAYER 1
;					 
;	MOV R2, R1
;	LDR R6, =PADDLE_HEIGHT
;	LDRH R5, [R6]
;	ADD R2, R5
;	LDR R5,=PADDLE_X1
;	LDRH R3 ,[R5]
;	MOV R4, R3
;	LDR R6, =PADDLE_WIDTH
;	LDRH R5, [R6]
;	ADD R4, R5
;	BL Draw_Rectangle
;	;
;	B END_MOVE_PLAYER_1
;	
;	
;PLAYER_1_UP				; CHECK UP FOR PLAYER 1
;	CMP R0, #2 			; CHECK IF PLAYER 1 IS MOVING UP
;	BNE END_MOVE_PLAYER_1; IF NOT, DO NOTHING TO PLAYER 1 AND CHECK PLAYER 2
;	
;	LDR R5, =PADDLE_Y1	;TODO: CHECK IF THE PLAYER REACHED Y = 0 (END OF SCREEN)
;	LDRH R1, [R5]
;	CMP R1, #0x0
;	BLE END_MOVE_PLAYER_1
;						; ERASES PLAYER 1 AND REDRAWS PLAYER 1 UP 10 PIXELS
;	LDR R5,=Black 		; TODO: CHANGE IF THE BACKGROUND ISN'T BLACK
;	LDRH R0, [R5]
;	LDR R5,=PADDLE_Y1
;	LDRH R1, [R5]
;	MOV R2, R1
;	LDR R6, =PADDLE_HEIGHT
;	LDRH R5, [R6]
;	ADD R2, R5
;	LDR R5,=PADDLE_X1
;	LDRH R3 ,[R5]
;	MOV R4, R3
;	LDR R6, =PADDLE_WIDTH
;	LDRH R5, [R6]
;	ADD R4, R5
;	BL Draw_Rectangle 
;	; DONE ERASING PLAYER 1

;	;NOW REDRAWING BUT Y1 IS DECREASED BY 10
;	LDR R5,=PADDLE_COLOR1
;	LDRH R0, [R5]
;	LDR R5,=PADDLE_Y1
;	LDRH R1, [R5]
;	SUB R1, R1, #0x10	;SUBTRACTING 10 DECIMAL TO Y1 
;	STRH R1, [R5]		;STORING THE NEW POSITION OF PLAYER 1
;	;TODO: CHECK IF PLAYER 1 REACHED TOP OF SCREEN Y1 = 0 (IT ISN'T REALLY Y = 0)
;	MOV R2, R1
;	LDR R6, =PADDLE_HEIGHT
;	LDRH R5, [R6]
;	ADD R2, R5
;	LDR R5,=PADDLE_X1
;	LDRH R3 ,[R5]
;	MOV R4, R3
;	LDR R6, =PADDLE_WIDTH
;	LDRH R5, [R6]
;	ADD R4, R5
;	BL Draw_Rectangle

;END_MOVE_PLAYER_1
;	
;	MOV R7, R1
;	
;	CMP R1, #1 			; CHECK IF PLAYER 1 IS MOVING DOWN
;	BNE PLAYER_2_UP		; IF NOT, CHECK UP
;	
;	LDR R5, =PADDLE_Y1	;TODO: CHECK IF THE PLAYER REACHED Y = 200 (END OF SCREEN)
;	LDRH R1, [R5]
;	CMP R1, #0x200
;	BCS END_MOVE_PLAYER_2
;	
;	; ERASES PLAYER 1 AND REDRAWS PLAYER 1 DOWN 10 PIXELS
;	LDR R5,=Black 		; TODO: CHANGE IF THE BACKGROUND ISN'T BLACK
;	LDRH R0, [R5]
;	LDR R5,=PADDLE_Y2
;	LDRH R1, [R5]
;	MOV R2, R1
;	LDR R6, =PADDLE_HEIGHT
;	LDRH R5, [R6]
;	ADD R2, R5
;	LDR R5,=PADDLE_X2
;	LDRH R3 ,[R5]
;	MOV R4, R3
;	LDR R6, =PADDLE_WIDTH
;	LDRH R5, [R6]
;	ADD R4, R5
;	BL Draw_Rectangle 
;	; DONE ERASING PLAYER 1

;	;NOW REDRAWING BUT Y2 IS INCREASED BY 10
;	LDR R5,=PADDLE_COLOR2
;	LDRH R0, [R5]
;	LDR R5,=PADDLE_Y2
;	LDRH R1, [R5]
;	ADD R1, R1,#0x10	;ADDING 10 DECIMAL TO Y1
;	STRH R1, [R5]	;STORING THE NEW POSITION OF PLAYER 2
;					 
;	MOV R2, R1
;	LDR R6, =PADDLE_HEIGHT
;	LDRH R5, [R6]
;	ADD R2, R5
;	LDR R5,=PADDLE_X2
;	LDRH R3 ,[R5]
;	MOV R4, R3
;	LDR R6, =PADDLE_WIDTH
;	LDRH R5, [R6]
;	ADD R4, R5
;	BL Draw_Rectangle
;	;
;	B END_MOVE_PLAYER_2
;	
;	
;PLAYER_2_UP				; CHECK UP FOR PLAYER 2
;	CMP R1, #2 			; CHECK IF PLAYER 2 IS MOVING UP
;	BNE END_MOVE_PLAYER_2; IF NOT, DO NOTHING TO PLAYER 1 AND CHECK PLAYER 2
;	
;	LDR R5, =PADDLE_Y1	;TODO: CHECK IF THE PLAYER REACHED Y = 0 (END OF SCREEN)
;	LDRH R1, [R5]
;	CMP R1, #0x0
;	BLE END_MOVE_PLAYER_1
;	
;						; ERASES PLAYER 2 AND REDRAWS PLAYER 2 UP 10 PIXELS
;	LDR R5,=Black 		; TODO: CHANGE IF THE BACKGROUND ISN'T BLACK
;	LDRH R0, [R5]
;	LDR R5,=PADDLE_Y2
;	LDRH R1, [R5]
;	MOV R2, R1
;	LDR R6, =PADDLE_HEIGHT
;	LDRH R5, [R6]
;	ADD R2, R5
;	LDR R5,=PADDLE_X2
;	LDRH R3 ,[R5]
;	MOV R4, R3
;	LDR R6, =PADDLE_WIDTH
;	LDRH R5, [R6]
;	ADD R4, R5
;	BL Draw_Rectangle 
;	; DONE ERASING PLAYER 1

;	;NOW REDRAWING BUT Y1 IS DECREASED BY 10
;	LDR R5,=PADDLE_COLOR2
;	LDRH R0, [R5]
;	LDR R5,=PADDLE_Y2
;	LDRH R1, [R5]
;	SUB R1, R1, #0x10	;SUBTRACTING 10 DECIMAL TO Y1 
;	STRH R1, [R5]		;STORING THE NEW POSITION OF PLAYER 1
;	;TODO: CHECK IF PLAYER 1 REACHED TOP OF SCREEN Y1 = 0 (IT ISN'T REALLY Y = 0)
;	MOV R2, R1
;	LDR R6, =PADDLE_HEIGHT
;	LDRH R5, [R6]
;	ADD R2, R5
;	LDR R5,=PADDLE_X2
;	LDRH R3 ,[R5]
;	MOV R4, R3
;	LDR R6, =PADDLE_WIDTH
;	LDRH R5, [R6]
;	ADD R4, R5
;	BL Draw_Rectangle
;	
;END_MOVE_PLAYER_2	
;	
;	POP {R0-R12, PC}
;	
;; R0 = color ,R1 = Y1 ,R2 = Y2 ,R3 = X1 ,R4 = X2

;PING_PONG_MODE

;	PUSH {R0-R12, LR}
;	
;	;CLEAR THE SCREEN
;	BL Clear_Screen
;	
;	; DRAWS PLAYER 1
;	LDR R5,=PADDLE_COLOR1
;	LDRH R0, [R5]
;	LDR R5,=PADDLE_Y1
;	LDRH R1, [R5]
;	MOV R2, R1
;	LDR R6, =PADDLE_HEIGHT
;	LDRH R5, [R6]
;	ADD R2, R5
;	LDR R5,=PADDLE_X1
;	LDRH R3 ,[R5]
;	MOV R4, R3
;	LDR R6, =PADDLE_WIDTH
;	LDRH R5, [R6]
;	ADD R4, R5
;	BL Draw_Rectangle
;	
;	;DARWS PLAYER 2
;	LDR R5,=PADDLE_COLOR1
;	LDRH R0, [R5]
;	LDR R5,=PADDLE_Y1
;	LDRH R1, [R5]
;	MOV R2, R1
;	LDR R6, =PADDLE_HEIGHT
;	LDRH R5, [R6]
;	ADD R2, R5
;	LDR R5,=PADDLE_X1
;	LDRH R3 ,[R5]
;	MOV R4, R3
;	LDR R6, =PADDLE_WIDTH
;	LDRH R5, [R6]
;	ADD R4, R5
;	BL Draw_Rectangle
;	
;	;DRAW THE BALL
;	LDR R5,=BALL_COLOR
;	LDRH R0, [R5]
;	LDR R5,=BALL_Y
;	LDRH R1, [R5]
;	MOV R2, R1
;	ADD R2, #0x10 ;TODO: CHANGE THIS
;	LDR R5,=BALL_X
;	LDRH R3, [R5]
;	MOV R4, R3
;	ADD R4, #0x10
;	BL Draw_Rectangle
;	
;	POP {R0-R12, PC}
;;ONE_PLAYER_MODE END




;EXIT
;	BX LR
;	
;ONE_PLAYER_MODE
;	BX LR



;	ALIGN
;	END