[org 0x0100]

jmp start

multiplicand: db 3
multiplier: db 2
result: db 0

start: 

	mov cl,	2
	mov bl, [multiplicand]
	mov dl, [multiplier]
	
	check:
		shr dl , 1
		jnc skip
		
		add [result], bl
		
		skip:
			
			shl bl , 1
			sub cl , 1
	
	jnz check
	
	mov ax , 0x4c00
	int 0x21
	
			
			