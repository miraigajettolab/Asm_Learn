MODEL TINY  
STACK 256	
DATASEG
	A DW 10 DUP(0)
CODESEG		
start:	
	mov ax,@data	
	mov ds,ax

        lea si, A
        mov cx, 10
        
input:        
	mov dx, 0      ;we'll store inputed number here

input_char:   ;works up to 2047(will switch to next number if you press "enter"
;or input non-numeric character
	
        mov ah, 1h     ;input ascii char 
        int 21h
        
        cmp al, 57       ;check if it's a digit
        jg end_of_input
        cmp al, 48
        jl end_of_input 

        push ax          ;save ax(cause input is in al, and we need ax for multiplication)
        
        mov bl, 10       ;specifing operand(multiple)
        mov ax, dx       ;setting up
        mul bl
        mov dx, ax       ;saving result to dx
        
        pop ax           ;retrieving input char
        
        sub al, 30h      ;converting it from ascii
        add dl, al       ;adding it to dx
        
        jmp input_char
        
end_of_input:  ;now the result is in dx      
 
        mov [si], dx ;storing the number into array A
        add si, 2 
        
        mov ah, 2h ;nextline 
       	mov dl, 0ah
	int 21h
 
        loop input
        
        
        mov ah, 2h ;nextline to separate input from output 
       	mov dl, 0ah
	int 21h
        
        
        lea si, A       
        mov cx, 10
loop_start:        
        push cx  ;saving counter

        mov ax, [si] ;getting the number we need to quantize
        mov cl, 10  ;storing the divisor(10)
        push 42     ;42 indicates the end of number
quant:
        div cl      ;divide number by 10
        mov bx, 0   ;initializing bx(just in case)
        mov bl, ah  ;moving the remaider to bl
        mov ah, 0   ;clearing the remainder(now in ax we have only integral part)
        push bx     ;saving the remainder(right digit) to stack
        cmp al, 0   ;if the integral part is 0, then stop, else jump to "quant:"
        jne quant

        
        mov ah,2h 
print_digit:             
	pop bx     ;pop the digit from the stack
        cmp bx, 42 ;if the digit is in fact a flag(42), stop printing(jmp "end..")
        je end_of_number	
	mov dl, bl  ;else set up the interrupt
	add dl, 30h  ;convert to ascii        
	int 21h
	jmp print_digit  ;infinate loop
end_of_number: ;lable for braking out of it	

	mov dl, 0ah   ;nextline
	int 21h
	
        pop cx      ;retrieve counter
        add si, 2
        loop loop_start  
        
	mov ah, 04Ch		
	int 21h
end start	

