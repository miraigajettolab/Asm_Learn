.MODEL SMALL
.STACK 100h
gg macro
 mov ah, 09h
 lea dx, prompt
 int 21h
 lea dx, newline
 int 21h
endm
.DATA
 char DB 1
 openBrackets DW 0
 closedBrackets DW 0
 prompt DB 'Enter a string: ','$'
 newline DB 0Dh, 0Ah, '$'
 messTrue DB 'This is an expression','$'
 messFalse DB 'This is NOT an expression','$'
.CODE
main proc
 mov ax, @data
 mov ds, ax
 gg
 call GetChar
 call IsExpression
 cmp al, 1
 jne notAnExpression
 lea si, openBrackets
 lea di, closedBrackets
 mov dx, [si]
 mov bx, [di]
 cmp dx, bx
 jne notAnExpression
 lea si, char
 mov bl, [si]
 cmp bl, 13 

 jne notAnExpression
 mov ah, 09h
 lea dx, newline
 int 21h
 lea dx, messTrue
 int 21h
 jmp exit
 notAnExpression:
 mov ah, 09h
 lea dx, newline
 int 21h
 lea dx, messFalse
 int 21h
 exit:
main endp
GetChar proc
 push si
 push ax

 mov ah,1h
 int 21h

 lea si, char
 mov [si], al
 pop ax
 pop si
ret
GetChar endp
IsExpression proc
 call IsTerm
 cmp ax,1
 jne IsExpressionFalse1
 push si
 lea si, char
 mov al, [si]
 pop si

 cmp al,43
 je IsExpressionTrue2
 cmp al,45
 jne IsExpressionFalse2
 IsExpressionTrue2:
 call GetChar
 call IsExpression
 ret
 IsExpressionFalse2:
 mov ax,1
 ret
 IsExpressionFalse1:
 mov ax, 0
 ret
IsExpression endp
IsTerm proc
 call IsOpenBracket

 call IsMultiplier
 cmp ax,1
 jne IsTermFalse1
 call IsClosedBracket

 push si
 push di
 lea si, openBrackets
 lea di, closedBrackets
 mov ax, [si]
 mov bx, [di]
 pop di
 pop si

 cmp ax, bx
 jl IsTermFalse1

 push si
 lea si, char
 mov al, [si]
 pop si

 cmp al,42
 je IsTermTrue2
 cmp al,47
 jne IsTermFalse2
 IsTermTrue2:
 call GetChar
 call IsTerm
 ret
 IsTermFalse2:
 mov ax,1
 ret
 IsTermFalse1:
 mov ax, 0
 ret
IsTerm endp
IsMultiplier proc
 call IsLetter
 cmp ax, 1
 jne IsMultiplierFalse
 mov ax, 1
 ret
 IsMultiplierFalse:
 call IsUnsignedInt
 ret
IsMultiplier endp
IsUnsignedInt proc
 call IsDigit
 cmp ax, 1
 jne IsUnsignedIntFalse
 call IsUnsignedInt
 mov ax, 1
 ret
 IsUnsignedIntFalse:
 mov ax, 0
 ret
IsUnsignedInt endp
IsDigit proc
 push si
 lea si, char
 mov al, [si]
 pop si

 cmp al, 57
 jg IsDigitFalse
 cmp al, 48
 jl IsDigitFalse
 call GetChar
 mov ax, 1
 ret
 isDigitFalse:
 mov ax, 0
 ret
IsDigit endp
IsLetter proc
 push si
 lea si, char
 mov al, [si]
 pop si

 cmp al, 102
 jg IsLetterFalse
 cmp al, 97
 jl IsLetterFalse
 call GetChar
 mov ax, 1
 ret
 IsLetterFalse:
 mov ax, 0
 ret
IsLetter endp
IsOpenBracket proc
 push ax
 push si
 lea si, char
 mov al, [si]
 pop si

 cmp al, 40
 jne IsOpenBracketFalse
 call GetChar

 push si
 lea si, openBrackets
 mov ax, [si]
 inc ax
 mov [si], ax
 pop si

 call IsOpenBracket
 IsOpenBracketFalse:
 pop ax
 ret
IsOpenBracket endp
IsClosedBracket proc
 push ax
 push si
 lea si, char
 mov al, [si]
 pop si

 cmp al, 41
 jne IsClosedBracketFalse
 call GetChar
 push si
 lea si, closedBrackets
 mov ax, [si]
 inc ax
 mov [si], ax
 pop si

 call IsClosedBracket
 IsClosedBracketFalse:
 pop ax
 ret
IsClosedBracket endp
end main