[org 0x0100]

jmp start

tofindfactorial : dw 5
result : dw 0

factorial:

	push bp
	mov bp , sp
	
	mov ax , [bp + 4]

	cmp ax , 1
	jne moveon

totrack: 	
	
	imul ax , [bp + 4]
	mov [bp + 4] , ax
	
	;mov sp , bp
	pop bp
	ret
	
	moveon:
		
	sub ax , 1
	push ax
	
		
	call factorial
	pop ax
	
jmp totrack
	
	
	
start:
	
	mov ax , [tofindfactorial]
	push ax
	
	call factorial
	
	mov [result] , ax
	
	pop ax
	


	
mov ax , 0x4c00
int 0x21