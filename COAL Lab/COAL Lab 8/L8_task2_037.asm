[org 0x0100]

jmp start

num1 : dw 13000
num2 : dw 12000

start:

mov al , [num1]
add [num2] , al

mov al , [num1 + 1]
adc [num2 + 1] , al

mov ax , 0x4c00
int 0x21
