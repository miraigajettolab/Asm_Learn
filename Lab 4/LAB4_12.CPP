#include <stdio.h>
#include <conio.h>
void main(void)
{
int B[9]={1,2,3,4,5,6,7,8,9};
int A[10][9];

for(int i=0;i<10;i++){
  for(int j=0;j<9;j++)
    A[i][j] = 0;
}

asm {
lea bx, A
mov si, 18
}
e1: asm  {
lea di, B
mov cx, 9
}
e2: asm {
mov ax, [di]

mov [bx+si], ax

add si, 2
add di, 2
loop e2
}
asm {
add si, 18
cmp si, 180
jl e1
}

printf("\n");

for(i=0;i<10;i++){
  for (int j=0; j<9; j++)
    printf("%d", A[i][j]);
  printf("\n");
}
getch();
}