MODEL	TINY 
STACK 256	
DATASEG
	A DB 1,3,3,4,5,6,7,8,9,9 
	B DB 10 DUP(0)
CODESEG		
start:	
	mov ax,@data	
	mov ds,ax
	
	lea si,A
        lea di,B
        mov cx,9
swap:
        mov ax, [si]
        mov [di], ax
        add si, 1
        add di, 1
        loop swap
      		
        lea si,B
        mov cx, 10
        mov ah,2h
loop_start: 

	mov dl, [si]
	add dl, 30h
	int 21h
	add si, 1
	mov dl, 0ah
	int 21h
	loop loop_start

	mov ah, 04Ch		
	int 21h
end start	

