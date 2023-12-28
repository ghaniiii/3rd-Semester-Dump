[org 0x0100] 
 
jmp start 

data:  dw 9 , 5 , 7 , 2 , 1   


bubblesort: push bp 
			mov bp, sp 
			sub sp, 2 
			push ax  
			push bx  
			push cx  
			push si 
			mov bx, [bp+6]  
			mov cx, [bp+4]  
			dec cx 
			shl cx, 1 

	mainloop:   mov si, 0 
				mov word [bp-2], 0 
		
		innerloop:  mov ax, [bx+si] 
					cmp ax, [bx+si+2] 
					jbe noswap 
					xchg ax, [bx+si+2] 
					mov [bx+si], ax 
					mov word [bp-2], 1 
	
		noswap: add si, 2 
				cmp si, cx 
				jne innerloop  
 
		cmp word [bp-2], 1 
		
		je mainloop
			
		pop si 
		pop cx  
		pop bx 
		pop ax 
		mov sp, bp 
		pop bp 

ret 4  



start:  mov ax, data 
		push ax  
		mov ax, 5
		push ax 
 
		call bubblesort 

 
		mov ax, 0x4c00 
 
 int 0x21