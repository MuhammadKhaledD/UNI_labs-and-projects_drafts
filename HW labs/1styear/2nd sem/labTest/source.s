    EXPORT __main

    AREA MYDATA, DATA, READWRITE  

; Define register base addresses
RCC_BASE        EQU     0x40023800
GPIOA_BASE      EQU     0x40020000
GPIOB_BASE      EQU     0x40020400
GPIOC_BASE      EQU     0x40020800
GPIOD_BASE      EQU     0x40020C00
GPIOE_BASE      EQU     0x40021000

; Define register offsets
RCC_AHB1ENR     EQU     0x30
GPIO_MODER      EQU     0x00
GPIO_OTYPER     EQU     0x04
GPIO_OSPEEDR    EQU     0x08
GPIO_PUPDR      EQU     0x0C
GPIO_IDR        EQU     0x10
GPIO_ODR        EQU     0x14

    AREA MYCODE, CODE, READONLY 
        
__main FUNCTION

    ; Enable GPIO-D clock
    LDR     R1, =RCC_BASE + RCC_AHB1ENR
    LDR     R0, [R1]           
    ORR     R0, R0, #(1 << 3)         
    STR     R0, [R1]          

    ; Configure PD15 & PD14 as output mode (LEDs)
    LDR     R1, =GPIOD_BASE + GPIO_MODER 
    LDR     R0, [R1]  
    ORR     R0, R0, #( (1 << (15 * 2)) | (1 << (14 * 2)) )  ; Set PD15 & PD14 as outputs
    STR     R0, [R1]            

    ; Configure PD11 & PD12 as input mode (Buttons)
    LDR     R1, =GPIOD_BASE + GPIO_MODER
    LDR     R0, [R1]
    BIC     R0, R0, #( (3 << (11 * 2)) | (3 << (12 * 2)) )  ; Clear PD11 & PD12 (Set to input)
    STR     R0, [R1]

    ; Enable pull-down resistors for PD11 & PD12
    LDR     R1, =GPIOD_BASE + GPIO_PUPDR
    LDR     R0, [R1]
    ORR     R0, R0, #( (2 << (11 * 2)) | (2 << (12 * 2)) )  ; Pull-down PD11 & PD12
    STR     R0, [R1]

; Main loop
mainLoop
    ; Read button inputs
    LDR     R1, =GPIOD_BASE + GPIO_IDR
    LDR     R0, [R1]

    TST     R0, #(1 << 12)  
    BNE     blinkTwoLEDs    

    TST     R0, #(1 << 11) 
    BNE     blinkOneLED     

    ; If no button is pressed, turn off LEDs
    LDR     R1, =GPIOD_BASE + GPIO_ODR
    LDR     R0, [R1]
    BIC     R0, R0, #( (1 << 15) | (1 << 14) )  
    STR     R0, [R1]
    
    B       mainLoop  ; Repeat checking

; Blink LED1 (PD15) only
blinkOneLED
    LDR     R1, =GPIOD_BASE + GPIO_ODR
    LDR     R0, [R1]
    ORR     R0, R0, #(1 << 15)  ; Turn ON PD15
    STR     R0, [R1]

    BL      delay  ; Wait

    LDR     R1, =GPIOD_BASE + GPIO_ODR
    LDR     R0, [R1]
    BIC     R0, R0, #(1 << 15)  ; Turn OFF PD15
    STR     R0, [R1]

    BL      delay  ; Wait

    B       mainLoop  ; Repeat checking

; Blink LED1 (PD15) and LED2 (PD14) together
blinkTwoLEDs
    LDR     R1, =GPIOD_BASE + GPIO_ODR
    LDR     R0, [R1]
    ORR     R0, R0, #( (1 << 15) | (1 << 14) )  ; Turn ON PD15 & PD14
    STR     R0, [R1]

    BL      delay  ; Wait

    LDR     R1, =GPIOD_BASE + GPIO_ODR
    LDR     R0, [R1]
    BIC     R0, R0, #( (1 << 15) | (1 << 14) )  ; Turn OFF PD15 & PD14
    STR     R0, [R1]

    BL      delay  ; Wait

    B       mainLoop  ; Repeat checking

; Simple delay function
delay
    LDR     R2, =0x3FFFFF  ; Load large value for delay loop
delayLoop
    SUBS    R2, R2, #1
    BNE     delayLoop
    BX      LR

    ENDFUNC
    END
