#include <stdio.h>
#include <conio.h>
void main(void)
{
int A[5]={1,2,3,4,5};
int B[5]={0,0,0,0,0};

asm {
lea si,A
lea di,B
mov cx,5
}
loop_start: asm {
mov ax, [si]
mov [di], ax
add si, 2
add di, 2
loop loop_start
}

for (int i=0 ;i<5;i++)
	printf("\n %d",B[i]);
	getch();
 }

//DRUZHININ GRIGORENKO MAGOMEDOV 13537/1






























































































