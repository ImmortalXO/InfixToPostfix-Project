#include "InfixToPostfix.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	ifstream inFile("InfixData.txt");

	if (!inFile.is_open()) {
		cout << "Could not access the input file." << endl;
		return 1;
	}

	string infix;
	while (getline(inFile, infix)) {
		InfixToPostfix item;
		cout << "Infix: " << infix << ";" << endl;
		// Postfix
		item.Convert(infix);
		cout << "Postfix: " << item.getPostfix() << endl << endl;
	}

	inFile.close();

	return 0;
}