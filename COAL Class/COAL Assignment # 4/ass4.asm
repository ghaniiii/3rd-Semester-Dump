[org 0x0100]

jmp start

operand1 : dw 21
operand2 : dw 3

sum_result : dw 0
subtraction_result : dw 0
multiplication_result : dw 0
division_result : dw 0

toprint1 : db 'Operand 1 : '
count1 : dw 12

toprint2 : db 'Operand 2 : '
count2 : dw 12

toprint3 : db 'Sum : '
count3 : dw 6

toprint4 : db 'Difference : '
count4 : dw 13 

toprint5 : db 'Multiplication : '
count5 : dw 17

toprint6 : db 'Division : '
count6 : dw 11

add1:
	
	push bp
	mov bp , sp
	
	mov bx , [bp + 4]
	mov ax , [bp + 6]
	
	add ax , bx
	mov [sum_result] , ax
	
	mov sp , bp
	pop bp
	
	ret

subtract:
	push bp
	mov bp , sp
	
	mov bx , [bp + 4]
	mov ax , [bp + 6]
	
	sub ax , bx
	mov [subtraction_result] , ax
	
	mov sp , bp
	pop bp
	
	ret


multiply:
	push bp
	mov bp , sp
	
	mov bx , [bp + 4]
	mov ax , [bp + 6]
	
	mul bx
	mov [multiplication_result] , ax
	
	mov sp , bp
	pop bp
	
	ret


divide:
	push bp
	mov bp , sp
	
	mov bx , [bp + 4]
	mov ax , [bp + 6]
	
	div bx
	mov [division_result] , ax
	
	mov sp , bp
	pop bp
	
	ret

clrscreen:
	mov ax , 0xb800
	mov es , ax
	mov bx , 0

	loop1:
	
	mov word [es : bx] , 0x0720
	add bx , 2
	
	cmp bx , 4000
	jne loop1
	
	ret
	
printing:
	mov ax , 0xb800
	mov es , ax
	
	push bp 
	mov bp , sp
	mov cx , [bp + 4]
	mov si , [bp + 6]
	mov di , [bp + 8]
	
	mov ah , 0x07
	
	
	printingloop1 : 
	mov al , [si]
	
	mov word [es : di] , ax
	add si , 1
	
	add di , 2
	
	loop printingloop1
	

	
	mov sp , bp
	pop bp
	
	;---------------
	
	ret
	
printing2:
	
	;number printing
	mov ax , 0xb800
	mov es , ax
	
	push bp
	mov bp , sp
	
	mov ax , [bp + 4]
	mov bx , [bp + 6]
	mov di , 10
	mov cx , 0
	
	
printing2loop:
	
	mov dx , 0
	div di
	
	add dl , 0x30
	push dx
	
	add cx , 1
	cmp ax , 0
	
	
	jnz printing2loop
	
printing2loop2:
	
	pop dx
	mov dh , 0x07
	
	mov [es : bx] , dx
	add bx , 2
	sub cx , 1
	
	cmp cx , 0
	jnz printing2loop2
	
	mov sp, bp
	pop bp
	
	ret 1


start:
	push bx
	
	mov ax , [operand1]
	push ax
	
	mov ax , [operand2]
	push ax
	
	call add1
	call subtract
	call multiply
	call divide
	
	call clrscreen
	
	mov ax , 0 ;where to start printing
	push ax
	
	mov ax , toprint1
	push ax
	
	mov ax , [count1]
	push ax
	
	call printing

	mov ax , [count1]
	shl ax , 1
	add ax , 0
	
	push ax

	mov ax , [operand1]
	push ax
	
	call printing2
	
	mov ax , 320 ;where to start printing
	push ax
	
	mov ax , toprint2
	push ax
	
	mov ax , [count2]
	push ax
	
	call printing

	mov ax , [count2]
	shl ax , 1
	add ax , 320
	
	push ax

	mov ax , [operand2]
	push ax
	
	call printing2
	
	mov ax , 640 ;where to start printing
	push ax
	
	mov ax , toprint3
	push ax
	
	mov ax , [count3]
	push ax
	
	call printing

	mov ax , [count3]
	shl ax , 1
	add ax , 640
	
	push ax

	mov ax , [sum_result]
	push ax
	
	call printing2
	
	mov ax , 960 ;where to start printing
	push ax
	
	mov ax , toprint4
	push ax
	
	mov ax , [count4]
	push ax
	
	call printing

	mov ax , [count4]
	shl ax , 1
	add ax , 960
	
	push ax

	mov ax , [subtraction_result]
	push ax
	
	call printing2


	mov ax , 1280 ;where to start printing
	push ax
	
	mov ax , toprint5
	push ax
	
	mov ax , [count5]
	push ax
	
	call printing

	mov ax , [count5]
	shl ax , 1
	add ax , 1280
	
	push ax

	mov ax , [multiplication_result]
	push ax
	
	call printing2
	
	mov ax , 1600 ;where to start printing
	push ax
	
	mov ax , toprint6
	push ax
	
	mov ax , [count6]
	push ax
	
	call printing

	mov ax , [count6]
	shl ax , 1
	add ax , 1600
	
	push ax

	mov ax , [division_result]
	push ax
	
	call printing2

	
	pop ax
	pop ax
	pop bx
	
	
	
mov ah , 0x01
int 0x21

mov ax , 0x4c00
int 0x21
