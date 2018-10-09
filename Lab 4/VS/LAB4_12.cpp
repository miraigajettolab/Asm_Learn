#include <iostream>
using namespace std;
/*
Filling even rows of 2d array using base-index addressing mode
By Sergey Grigorenko
*/
void LAB4_12() {

	cout << "Task 1.2) Base-Index Mode" << endl;

	int B[9] = { 1,2,3,4,5,6,7,8,9 };
	int A[10][9];

	for (int i = 0;i<10;i++) {
		for (int j = 0;j<9;j++)
			A[i][j] = 0;
	}

	_asm {

		lea ebx, A
		mov esi, 36
	
		e1:

		lea edi, B
		mov ecx, 9
	
		e2:

		mov eax,[edi]

		mov[ebx + esi], eax

		add esi, 4
		add edi, 4
		loop e2
	
		add esi, 36
		cmp esi, 360
		jl e1
	}

	cout << endl;

	for (int i = 0;i<10;i++) {
		for (int j = 0; j<9; j++)
			cout << A[i][j];
		cout << endl;
	}

}