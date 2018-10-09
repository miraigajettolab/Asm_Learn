MODEL	TINY 
STACK 256	
DATASEG
	A DW 282,12,1757,282,10,137,146,359,42,9
	B DW 10 DUP(0)
CODESEG		
start:	
	mov ax,@data	
	mov ds,ax
	
	lea si,A
        lea di,B
        mov cx,10
swap:
        mov ax, [si]
        mov [di], ax
        add si, 2
        add di, 2
        loop swap
	
     		
        lea si, B       
        mov cx, 10
loop_start:        
        push cx

        mov ax, [si]
        mov cl, 10
        push 42
quant:
        div cl
        mov bx, 0
        mov bl, ah
        mov ah, 0
        push bx
        cmp al, 0
        jne quant

        
        mov ah,2h 
print_digit:             
	pop bx
        cmp bx, 42
        je end_of_number	
	mov dl, bl
	add dl, 30h         
	int 21h
	jmp print_digit
end_of_number:	

	mov dl, 0ah
	int 21h
	
	add si, 2
        pop cx
        loop loop_start
 
	mov ah, 04Ch		
	int 21h
end start	

