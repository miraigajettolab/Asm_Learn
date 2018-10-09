  #include<stdio.h>
  #include<conio.h>
  #include<dos.h>
  #include<iostream.h>

  long a = 0xabffff, o3;
  int c  = 5;

  void interrupt (*old)(...);//old

  void interrupt shl_int(...){
    asm {lea si, a
    mov dx, [si]
    mov bx, [si + 2]
    lea si, c
    mov cx, [si]
    }
    loop_start: asm {
	shl bx, 1
	    shl dx, 1
	    jc addCarryBit
	    loop loop_start
	    jmp End
    }
    addCarryBit: asm {
    add bx, 1
    loop loop_start
    }
    End: asm {
    lea si, o3
    mov[si], dx
    mov[si + 2], bx
    }
  }

  void main(void){

  old=getvect(0xf0);//saving the old interruption
  disable();//old

  setvect(0xf0,shl_int);//setting vector in int table to our function

  enable();//old

  geninterrupt(0xf0);//kinda calling the function(shl_mem from LAB5)

  setvect(0xf0,old);//retreiving the old interruption

  cout << o3 << endl;
  getch();

  return;
  }