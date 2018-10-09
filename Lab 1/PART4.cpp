#include <stdio.h>
#include <conio.h>
void main(void)
{
int A[10]={1,2,3,4,5,6,7,8,9,10};
int B[10]={9,9,9,9,9,9,9,9,9,9};

asm {
lea si,A
lea di,B
mov cx,10
rep movsw
}

for (int i=0 ;i<10;i++)
	printf("\n %d",B[i]);
	getch();
 }

//DRUZHININ GRIGORENKO MAGOMEDOV 13537/1






























































































