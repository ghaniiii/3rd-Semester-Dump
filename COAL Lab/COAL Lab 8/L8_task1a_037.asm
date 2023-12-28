[org 0x0100]

jmp start

num : dw 13000

start:

shl word [num] , 1

mov ax , 0x4c00
int 0x21

