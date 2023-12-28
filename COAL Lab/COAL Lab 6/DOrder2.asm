[org 0x0100]

	jmp start

	data: dw 6 , 7 , 8 , 9
	swap: db 0


	start:

		outerloop: 
	  
			mov ax , 0
			mov bx , 0
			mov byte [swap] , 0
			
			innerloop:
			
				mov ax,[data + bx]
				
				cmp ax , [data + bx + 2]
				
				je noswap
				
				cmp ax , [data + bx + 2]
				
				ja noswap
				
					mov dx , [data + bx + 2]
					mov [data + bx] , dx
					mov [data + bx + 2] , ax
					mov byte [swap] , 1
					
			noswap:
				
			add bx , 2
			cmp bx , 6
					
			jne innerloop
				
		cmp byte [swap] , 1
		je outerloop
		
		
	mov ax , 0x4c00
	int 0x21

		
		