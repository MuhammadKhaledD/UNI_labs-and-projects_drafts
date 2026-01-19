            AREA    Graphics, CODE, READONLY

        IMPORT  TFT_WriteCommand
        IMPORT  TFT_WriteData
        IMPORT  TFT_Init
        IMPORT  TFT_FillScreen
        IMPORT  Delay
        IMPORT  font_map

        EXPORT  Draw_Pixel
       ; EXPORT  Draw_Char
        ;EXPORT  Draw_Msg
        EXPORT  Draw_Line
        EXPORT  Draw_Rectangle
        EXPORT  Clear_Screen
        EXPORT  Init_Screen

; *************************************************************
; Draw_Pixel:
; R0 = x, R1 = y, R2 = color
; *************************************************************
Draw_Pixel
        PUSH {LR}

        ; Set column address (0x2A)
        LDR R3, =0x2A
        BL  TFT_WriteCommand
        MOV R3, R0         ; x
        BL  TFT_WriteData
        BL  TFT_WriteData  ; x end (same)

        ; Set row address (0x2B)
        LDR R3, =0x2B
        BL  TFT_WriteCommand
        MOV R3, R1         ; y
        BL  TFT_WriteData
        BL  TFT_WriteData  ; y end (same)

        ; Memory write (0x2C)
        LDR R3, =0x2C
        BL  TFT_WriteCommand

        ; Write pixel color
        MOV R3, R2
        BL  TFT_WriteData

        POP {LR}
        BX  LR


; *************************************************************
; Draw_Char:
; R3 = character, R4 = color, R5 = bgcolor
; R6 = x, R7 = y, R8 = size (not used here — optional future scaling)
; *************************************************************
;Draw_Char
;        PUSH {R0-R2, LR}

;        ; Load font base
;        LDR R0, =font_map

;        ; Offset = char * 5 (5 bytes per character)
;        MOV R1, R3
;        MOV R2, #5
;        MUL R1, R1, R2
;        ADD R0, R0, R1

;        MOV R10, #0        ; column = 0
;Char_Col_Loop
;        CMP R10, #5
;        BGE Char_End

;        LDRB R11, [R0, R10]

;        MOV R12, #0        ; row = 0
;Char_Row_Loop
;        CMP R12, #7
;        BGE Next_Col

;        ; Check bit
;        MOV R1, R11
;        LSR R1, R12
;        AND R1, R1, #1
;        CMP R1, #0
;        BEQ Draw_Background

;        ; Draw char pixel
;        MOV R0, R6
;        ADD R0, R0, R10    ; x + col
;        MOV R1, R7
;        ADD R1, R1, R12    ; y + row
;        MOV R2, R4         ; char color
;        BL  Draw_Pixel
;        B   Next_Row

;Draw_Background
;        MOV R0, R6
;        ADD R0, R0, R10
;        MOV R1, R7
;        ADD R1, R1, R12
;        MOV R2, R5         ; background color
;        BL  Draw_Pixel

;Next_Row
;        ADD R12, R12, #1
;        B   Char_Row_Loop

;Next_Col
;        ADD R10, R10, #1
;        B   Char_Col_Loop

;Char_End
;        POP {R0-R2, LR}
;        BX  LR

;; *************************************************************
;; Draw_Msg:
;; R9 = string pointer, R4 = color, R5 = bgcolor
;; R6 = x, R7 = y, R8 = size (not used here — for future scaling)
;; *************************************************************

;Draw_Msg
;        PUSH {R0-R3, LR}

;        MOV R0, R9       ; pointer to string

;Msg_Loop
;        LDRB R3, [R0], #1
;        CMP R3, #0       ; null terminator
;        BEQ Msg_End

;        BL  Draw_Char

;        ADD R6, R6, #8   ; move x by (5+3) pixels

;        B   Msg_Loop

;Msg_End
;        POP {R0-R3, LR}
;        BX  LR

;************************************************************* 
; draw_line: Draw a line between two points (x1, y1) to (x2, y2) with the given color
; R0 = x1, R1 = y1, R2 = x2, R3 = y2, R4 = color
; *************************************************************
Draw_Line
        PUSH {R5-R12, LR}

        MOV R5, R0       ; x0
        MOV R6, R1       ; y0
        MOV R7, R2       ; x1
        MOV R8, R3       ; y1
        MOV R9, R4       ; color

        ; dx = abs(x1 - x0)
        SUBS R10, R7, R5
        CMP R10, #0
        RSBMI R10, R10, #0

        ; dy = -abs(y1 - y0)
        SUBS R11, R8, R6
        CMP R11, #0
        RSBMI R11, R11, #0
        RSB R11, R11, #0   ; dy = -abs(dy)

        ; sx = (x0 < x1) ? 1 : -1
        CMP R5, R7
        MOVLT R12, #1
        MOVGE R12, #-1

        ; sy = (y0 < y1) ? 1 : -1
        CMP R6, R8
        MOVLT R4, #1        ; Reusing R4 as temporary sy (color is already in R9)
        MOVGE R4, #-1

        ; err = dx + dy
        ADD R0, R10, R11    ; Use R0 for error term

line_loop
        ; Draw pixel at (R5, R6)
        MOV R0, R5
        MOV R1, R6
        MOV R2, R9
        BL  Draw_Pixel

        ; if x0 == x1 and y0 == y1 -> done
        CMP R5, R7
        BNE check_y
        CMP R6, R8
        BEQ done

check_y
        ; e2 = 2 * err
        ADD R3, R0, R0

        ; if e2 >= dy
        CMP R3, R11
        BLT skip_x
        ADD R0, R0, R11     ; err += dy
        ADD R5, R5, R12     ; x0 += sx

skip_x
        ; if e2 <= dx
        CMP R3, R10
        BGT skip_y
        ADD R0, R0, R10     ; err += dx
        ADD R6, R6, R4      ; y0 += sy

skip_y
        B   line_loop

done
        POP {R5-R12, LR}
        BX LR




; *************************************************************
; draw_rectangle: Draw a rectangle between 4 lines (x1, x2) to (y1, y2) with the given color
; R0 = color ,R1 = Y1 ,R2 = Y2 ,R3 = X1 ,R4 = X2
; *************************************************************
Draw_Rectangle
    PUSH {R1-R12, LR}

    ; Save color
    MOV R5, R0
	
    ; Set Column Address (0-239)
    MOV R0, #0x2A
    BL TFT_WriteCommand
	;HIGHER EIGHT BITS OF START COLUMN
    MOV R0, R3, LSL #8
    BL TFT_WriteData
	;LOWER EIGHT BITS BITS OF STAET COLUMN
    MOV R0, R3
    BL TFT_WriteData
	;HIGHER EIGHT BITS OF END COLUMN
    MOV R0, R4, LSL #8    
    BL TFT_WriteData
	;LOWER EIGHT BITS OF END COLUMN
    MOV R0, R4      
    BL TFT_WriteData

    ; Set Page Address (0-319)
    MOV R0, #0x2B
    BL TFT_WriteCommand
    MOV R0, R1, LSL #8    
    BL TFT_WriteData
	;LOWER EIGHT BITS OF END PAGE
    MOV R0, R1      
    BL TFT_WriteData
    MOV R0, R2, LSL #8    
    BL TFT_WriteData
	;LOWER EIGHT BITS OF END PAGE
    MOV R0, R2      
    BL TFT_WriteData
    ; Memory Write
    MOV R0, #0x2C
    BL TFT_WriteCommand

    ; Prepare color bytes
    MOV R1, R5, LSR #8     ; High byte
    AND R2, R5, #0xFF      ; Low byte

    ; Fill screen with color AREA (X2 - X1) * (Y2 - Y1)
	SUBS R7, R4,R3
	ADD R7, R7 ,#1	
	SUBS R8, R2, R1
    MUL R3, R8,R7
FillLoop
    ; Write high byte
    MOV R0, R1
    BL TFT_WriteData
    
    ; Write low byte
    MOV R0, R2
    BL TFT_WriteData
    
    SUBS R3, R3, #1
    BNE FillLoop

    POP {R1-R12, LR}
    BX LR

; *************************************************************
; clear_screen: Clears the screen (sets all pixels to a default color, usually black)
; R0 = color (black)
; *************************************************************
Clear_Screen
    PUSH {R1-R12, LR}

    MOV R0, #0x0000       ; Set color to black (assuming 16-bit color depth)
    BL TFT_FillScreen     ; Call the TFT_FillScreen function to fill the screen

    POP {R1-R12, LR}
    BX LR
	
; *************************************************************
; init_screen: Initializes the TFT screen (clear screen, set up resolution, etc.)
; *************************************************************
Init_Screen
    PUSH {R1-R12, LR}
    
    ; Initialize the TFT display
    BL TFT_Init           ; Call the TFT_Init function to initialize the screen
    
    ; Clear the screen (default color black)
    MOV R0, #0x0000       ; Set color to black (assuming 16-bit color depth)
    BL Clear_Screen       ; Clear the screen with black color
    
    POP {R1-R12, LR}
    BX LR
	
		END