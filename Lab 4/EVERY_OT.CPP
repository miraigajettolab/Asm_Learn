#include <stdio.h>
#include <conio.h>
void main(void)
{
int B[9]={1,2,3,4,5,6,7,8,9};
int A[15][9];

for(int i=0;i<15;i++){
  for(int j=0;j<9;j++)
    A[i][j] = 0;
}

asm {
lea si, A
mov dx, 18
}
e1: asm  {
lea di, B
mov cx, 9
}
e2: asm {
mov ax, [di]

add si, dx
mov [si], ax
lea si, A

add dx, 2
add di, 2
loop e2
}
asm {
add dx, 18
cmp dx, 270
jl e1
}

printf("\n");

for(i=0;i<15;i++){
  for (int j=0; j<9; j++)
    printf("%d", A[i][j]);
  printf("\n");
}
getch();
}