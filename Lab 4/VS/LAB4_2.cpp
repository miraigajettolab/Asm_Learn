#include <iostream>
using namespace std;
/*
Comparing (add ecx, ebx) to (add ecx, [ebx+esi+20])
By Sergey Grigorenko
*/
void LAB4_2() {
	int A[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int O1, O2, T1, T2;

	_asm {
		mov ecx, 5
		mov ebx, 10

		rdtsc
		push eax

		add ecx, ebx //First addressing mode

		rdtsc

		//Saving to variables

		lea ebx, O1
		mov[ebx], ecx

		pop ecx
		sub eax, ecx //The difference of counters is now stored in eax

		lea ebx, T1
		mov[ebx], eax

		//*************

		mov ecx, 10
		lea ebx, A
		mov esi, 4

		rdtsc
		push eax

		add ecx, [ebx + esi + 20] //Second addressing mode

		rdtsc

		//Saving to variables

		lea ebx, O2
		mov[ebx], ecx

		pop ecx
		sub eax, ecx	//The difference of counters is now stored in eax

		lea ebx, T2
		mov[ebx], eax
	}

	cout << "1)Result: " << O1 << endl;
	cout << "1)Cycles: " << T1 << endl;
	cout << "2)Result: " << O2 << endl;
	cout << "2)Cycles: " << T2 << endl;

}