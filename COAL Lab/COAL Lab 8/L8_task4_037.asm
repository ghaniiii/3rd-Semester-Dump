[org 0x0100]

jmp start

multiplicand : dd 61000
multiplier : dw 53000
result : dd 0

start: 
		mov cx , 16
		mov bx , [multiplier]
		
		
	check:
		shr bx , 1
		
		jnc skip
	
		mov ax , [multiplicand]
		add [result] , ax
		
		mov ax , [multiplicand + 2]
		adc [result + 2] , ax  
	
			skip:
			
				shl word [multiplicand] , 1
				rcl word [multiplicand + 2] , 1
				
				sub cx , 1
				jnz check
				
	mov ax , 0x4c00
	int 0x21
	
	
		