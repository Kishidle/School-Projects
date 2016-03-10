#include "stdafx.h"

using namespace std;

void main() {
	//position of pointer in file
	streampos begin;
	streampos end;

	cout << "WHERE'S THE FILE THOUGH HAHAHAHAHA";

	//reading the input.txt file
	ofstream file ("input.txt", ios::out);
	if (file.is_open()) {
		//compute for the answer
		while (!(file.eof())) {
			//find parenthesis
			//find multiply / division / modulo
			//find addition / subtraction
		}

		//output
		cout << "The output is something!";
		file.close();
	}
	else {
		cout << "Unable to open the file :(";
	}
}
