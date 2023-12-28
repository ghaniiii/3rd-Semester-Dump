[org 0x0100]

jmp start

array : dw 7 , 14 , 21 , 28 , 35 , 42 , 49 , 6 , 13 , 20
even1 : dw 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0
odd1 : dw 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0

start:
	mov ax , 1
	mov si , 0
	mov bx , 0
	mov bp , 0
	
	loop1:  mov ax , [array + si]
			shr ax , 1
			
			jnc evenInstructions
			 
			mov cx , [array + si]
			mov [odd1 + bp] , cx
			add bp , 2
			jmp endOfLoop
			
		evenInstructions:
		
			mov cx , [array + si]
			mov [even1 + bx] , cx
			add bx , 2
			
			jmp endOfLoop
			
		endOfLoop
			add si , 2
			cmp si , 20
	jnz loop1
		
mov ax , 0x4c00
int 0x21
	
		
		