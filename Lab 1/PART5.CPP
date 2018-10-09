#include <stdio.h>
#include <conio.h>
void main(void)
{
int A[10]={1,2,3,4,5,6,7,8,9,10};
int B[10]={9,9,9,9,9,9,9,9,9,9};

asm {
lea si, A
lea di, B
mov cx, 0
}
met: asm {
les ax, [si]
push ax     //pushing A element
push ds     //saving ds because lds will change it
lds ax, [di]
pop ds      //retrieving ds
push ax     //pushing B element
pop bx      //popping B element to A
mov [si], bx
pop bx      //popping A element to B
mov [di], bx
add di, 2
add si, 2
add cx, 1
cmp cx, 10
jne met
}

for (int i=0 ;i<10;i++){
	printf("\n %d  ",A[i]);
	printf("%d",B[i]);}
	getch();
 }

//DRUZHININ GRIGORENKO MAGOMEDOV 13537/1






























































































