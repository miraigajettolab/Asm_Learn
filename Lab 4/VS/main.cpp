#include <iostream>
using namespace std;

void LAB4_11();
void LAB4_12();
void LAB4_2();

int main()

{
	unsigned sw;
	cout << "Input function code (1-3)" << endl;;

	try {
		cin >> sw;
		if (!cin)
			throw "Input isn't an integer number";

		switch (sw) {
		case 1: LAB4_11();
			break;
		case 2: LAB4_12();
			break;
		case 3: LAB4_2();
			break;
		default: cout << "Not a valid function code, use numbers 1-4" << endl;
			break;
		}
	}
	catch (const char* errorString) {
		cerr << errorString << endl;
		return -1;
	}
	return 0;
}