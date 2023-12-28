; bubble sort subroutine called twice 
[org 0x0100] 


 jmp start 


data: 		dw 11, 12 , 27 
data2: 		dw 10, 15 , 30 
swap: 		db 0
 
bubblesort: dec cx ; last element not compared 
			shl cx, 1 ; turn into byte count 

mainloop: 	mov si, 0 ; initialize array index to zero 
			mov byte [swap], 0 ; reset swap flag to no swaps 

innerloop: 	mov ax, [bx+si] ; load number in ax 
			cmp ax, [bx+si+2] ; compare with next number 
			jbe noswap ; no swap if already in order 
 
			mov dx, [bx+si+2] ; load second element in dx 
			mov [bx+si], dx ; store first number in second 
			mov [bx+si+2], ax ; store second number in first 
			mov byte [swap], 1 ; flag that a swap has been done 

noswap: 	add si, 2 ; advance si to next index
			cmp si, cx ; are we at last index 
			jne innerloop ; if not compare next two 
 
			cmp byte [swap], 1 ; check if a swap has been done 
			je mainloop ; if yes make another pass 
 
			ret ; go back to where we came from 

start: 		mov bx, data ; send start of array in bx 
			mov cx, 3 ; send count of elements in cx 
			call bubblesort ; call our subroutine 
 
			mov bx, data2 ; send start of array in bx 
			mov cx, 3 ; send count of elements in cx 
			call bubblesort ; call our subroutine again 
 
	mov ax, 0x4c00 ; terminate program 
	int 0x21