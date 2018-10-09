MODEL	TINY 
STACK 256	
DATASEG
	A DB 10 DUP(0)
CODESEG		
start:	
	mov ax,@data	
	mov ds,ax
	
	lea si,A
	mov dl, 0ah
	mov cx, 10
	
input_start:
        mov ah, 1h
        int 21h
        mov [si], al
        add si, 1
        mov ah, 2h
        int 21h
        loop input_start
        
        int 21h
      		
        lea si,A
        mov cx, 10
        mov ah,2h
        
loop_start: 

	mov dl, [si]
	int 21h
	add si, 1
	mov dl, 0ah
	int 21h
	loop loop_start

	mov ah, 04Ch		
	int 21h
end start	

