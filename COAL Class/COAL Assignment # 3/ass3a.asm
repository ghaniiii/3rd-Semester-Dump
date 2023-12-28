[org 0x0100]

jmp start

operand1 : dw 10
operand2 : dw 2

sum_result : dw 0
subtraction_result : dw 0
multiplication_result : dw 0
division_result : dw 0


add1:
	
	push bp
	mov bp , sp
	
	mov bx , [bp + 4]
	mov ax , [bp + 6]
	
	add ax , bx
	mov [sum_result] , ax
	
	pop bp
	
	ret

subtract:
	push bp
	mov bp , sp
	
	mov bx , [bp + 4]
	mov ax , [bp + 6]
	
	sub ax , bx
	mov [subtraction_result] , ax
	
	pop bp
	
	ret


multiply:
	push bp
	mov bp , sp
	
	mov bx , [bp + 4]
	mov ax , [bp + 6]
	
	mul bx
	mov [multiplication_result] , ax
	
	pop bp
	
	ret


divide:
	push bp
	mov bp , sp
	
	mov bx , [bp + 4]
	mov ax , [bp + 6]
	
	div bx
	mov [division_result] , ax
	
	pop bp
	
	ret



start:
	push bx
	push ax
	
	mov ax , [operand1]
	push ax
	
	mov ax , [operand2]
	push ax
	
	call add1
	call subtract
	call multiply
	call divide
	
	pop ax
	pop ax
	pop ax
	pop bx
	
mov ax , 0x4c00
int 0x21
