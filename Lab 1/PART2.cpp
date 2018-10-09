#include <stdio.h>
#include <conio.h>
void main(void)
{
int A[5]={5,6,7,8,9};
int B[5]={7,8,3,6,1};

asm {
lea si,A
lea di,B
mov cx,0
}
met: asm {
mov ax, [si]
mov [di], ax
add si, 2
add di, 2
add cx, 1
cmp cx, 5
jne met
}

for (int i=0;i<5;i++)
	printf("\n %d",B[i]);
	getch();
 }

//DRUZHININ GRIGORENKO MAGOMEDOV 13537/1