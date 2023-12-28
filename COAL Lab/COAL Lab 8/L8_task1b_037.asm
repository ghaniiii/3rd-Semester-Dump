[org 0x0100]

jmp start

num : dw 13000

start:

shl byte [num] , 1
rcl byte [num + 1], 1

mov ax , 0x4c00
int 0x21

