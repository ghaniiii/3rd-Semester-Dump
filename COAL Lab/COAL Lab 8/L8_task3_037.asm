[org 0x0100]

jmp start

multiplicand: dw 156
multiplier: db 146
result: dw 0

start: 

	mov cl,	8
	;mov bx, [multiplicand]
	mov dl, [multiplier]
	
	check:
		shr dl , 1
		jnc skip
		
		mov bl , [multiplicand]
		add [result], bl
		
		mov bl , [multiplicand + 1]
		adc [result + 1] , bl
		
		skip:
			
			shl byte [multiplicand] , 1
			rcl byte [multiplicand + 1] , 1
			
			sub cl , 1
	
	jnz check
	
	mov ax , 0x4c00
	int 0x21
	