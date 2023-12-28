; bubble sort and swap subroutines saving and restoring registers 
[org 0x0100] 
 jmp start 
data: dw 6 , 7 , 9 , 8 

swapflag: db 0 

swap: push ax ; save old value of ax 
	 mov ax, [bx+si] ; load first number in ax 
	 xchg ax, [bx+si+2] ; exchange with second number 
	 mov [bx+si], ax ; store second number in first 
	 pop ax ; restore old value of ax 
	 ret ; go back to where we came from 

bubblesort: push ax ; save old value of ax 
			 push cx ; save old value of cx 
			 push si ; save old value of si 
			 dec cx ; last element not compared 
			 shl cx, 1 ; turn into byte count 
			 
mainloop: mov si, 0 ; initialize array index to zero 
	 mov byte [swapflag], 0 ; reset swap flag to no swaps 

innerloop: mov ax, [bx+si] ; load number in ax 
	 cmp ax, [bx+si+2] ; compare with next number 
	 jbe noswap ; no swap if already in order
	 call swap ; swaps two elements 
	 mov byte [swapflag], 1 ; flag that a swap has been done 
	 
noswap: add si, 2 ; advance si to next index 
	 cmp si, cx ; are we at last index 
	 jne innerloop ; if not compare next two 
	 
	 cmp byte [swapflag], 1 ; check if a swap has been done 
	 je mainloop ; if yes make another pass 
	 pop si ; restore old value of si 
	 pop cx ; restore old value of cx 
	 pop ax ; restore old value of ax 
	 ret ; go back to where we came from 
	 
start: mov bx, data ; send start of array in bx 
	 mov cx, 4 ; send count of elements in cx 
	 call bubblesort ; call our subroutine 
	 
	 mov ax, 0x4c00 ; terminate program 
	 int 0x21