#include <iostream>
using namespace std;
/*
Filling even rows of 2d array using register addressing mode
By Sergey Grigorenko
*/
void LAB4_11() {

	cout << "Task 1.1) Register Mode" << endl;

	int B[9] = { 1,2,3,4,5,6,7,8,9 };
	int A[10][9];

	for (int i = 0;i<10;i++) {
		for (int j = 0;j<9;j++)
			A[i][j] = 0;
	}

	_asm {
		lea esi, A
		add esi, 36
		
		mov edx, 0 //edx is used as a counter for a number of passes
		e1: 
		add edx, 1

		lea edi, B

		mov ecx, 9 //ecx is a counter for elements in a row
		e2:

		mov eax,[edi]
		mov[esi], eax

		add esi, 4
		add edi, 4

		loop e2 //row loop
	
		add esi, 36 

		cmp edx, 5 //column loop
		jne e1
	}

	cout << endl;

	for (int i = 0;i<10;i++) {
		for (int j = 0; j<9; j++)
			cout << A[i][j];
		cout << endl;
	}

}