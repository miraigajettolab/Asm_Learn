#include <stdio.h>
#include <conio.h>
void output();

void main(void)
{
  printf("\n\nBEFORE:\n");
  output();

	asm {
	mov bx, [0x8000]
	push bx
	mov bx, [0x8300]
	mov [0x8000], bx
	pop bx
	mov [0x8300], bx
	}

  printf("\n\nAFTER:\n");
  output();
  getch();
}

void output(){
  int A[2];
	asm {
	lea si, A
	mov bx, [0x8000]
	mov [si], bx
	add si, 2
	mov bx, [0x8300]
	mov [si], bx
	}
  for (int k=0;k<2;k++)
  printf("\n %d",A[k]);
}

//DRUZHININ GRIGORENKO MAGOMEDOV 13537/1