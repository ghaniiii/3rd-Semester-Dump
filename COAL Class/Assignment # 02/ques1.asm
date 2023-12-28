[org 0x0100]

mov ax , 0
mov cx , 20

loop1:	add ax , 20
		dec cx
	
		jnz loop1

mov ax , 0x4c00
int 0x21
		