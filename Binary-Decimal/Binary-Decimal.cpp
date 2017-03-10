// Binary-Decimal.cpp : Defines the entry point for the console application.
//

//-----------------------------//
//       Converter V1.0        //
//       ==============        //
//                             //
// Fixes:                  0   //
// Additions:              0   //
// Lines Added:            0   //
//-----------------------------//

#include "stdafx.h"
#include <iostream>
using namespace std;

void BiDecConv(), IPAND();
int DecToBi(int input), BiToDec(int input), AND(int input1, int input2);

int main()
{
	system("color f1");
	system("cls");

	int answer;
	int input1(0), input2(0);

	cout << "+-----------------------+" << endl;
	cout << "| 1. Decimal <> Binary\t|" << endl;
	cout << "| 2. Decimal <> Hex\t|" << endl;
	cout << "| 3. AND (Binary)\t|" << endl;
	cout << "| 4. AND (Decimal)\t|" << endl;
	cout << "| 5. AND IP Address\t|" << endl;
	cout << "| 6. EXIT\t\t|" << endl;
	cout << "+-----------------------+" << endl;
	cout << "Please enter an option and press enter: ";
	cin >> answer;

	system("cls");

	if (answer == 1) {
		BiDecConv();
	}
	else if (answer == 2) {
		
	}
	else if (answer == 3) {
		
	}
	else if (answer == 4) {
		
	}
	else if (answer == 5) {
		IPAND();
	}
	else if (answer == 6) {
		exit(0);
	}
	else {
		main();
	}

    return 0;
}

void BiDecConv()
{
	int input;

	cout << "TYPES" << endl;
	cout << "++======================++" << endl;
	cout << "|| 1. Decimal\t\t||" << endl;
	cout << "|| 2. Binary\t\t||" << endl;
	cout << "++======================++" << endl;
	cout << "Please enter type of # to be converted: ";
	cin >> input;

	system("cls");

	if (input == 1) {
		cout << "Please enter number to be converted: ";
		cin >> input;

		system("cls");

		cout << "Decimal:\t" << input << endl;
		cout << "Binary :\t" << DecToBi(input) << endl;
	}
	else if (input == 2) {
		cout << "Please enter number to be converted: ";
		cin >> input;

		system("cls");

		cout << "Binary :\t" << input << endl;
		cout << "Decimal:\t" << BiToDec(input) << endl;
	}

	system("pause");

	main();
}

int DecToBi(int input)
{
	int output(0);

	if ((input - 128) >= 0) {
		input -= 128;
		output += 10000000;
	}
	if ((input - 64) >= 0) {
		input -= 64;
		output += 1000000;
	}
	if ((input - 32) >= 0) {
		input -= 32;
		output += 100000;
	}
	if ((input - 16) >= 0) {
		input -= 16;
		output += 10000;
	}
	if ((input - 8) >= 0) {
		input -= 8;
		output += 1000;
	}
	if ((input - 4) >= 0) {
		input -= 4;
		output += 100;
	}
	if ((input - 2) >= 0) {
		input -= 2;
		output += 10;
	}
	if ((input - 1) >= 0) {
		input -= 1;
		output += 1;
	}

	return output;
}

int BiToDec(int input)
{
	int output(0);

	if (input >= 10000000) {
		output += 128;
		input -= 10000000;
	}
	if (input >= 1000000) {
		output += 64;
		input -= 1000000;
	}
	if (input >= 100000) {
		output += 32;
		input -= 100000;
	}
	if (input >= 10000) {
		output += 16;
		input -= 10000;
	}
	if (input >= 1000) {
		output += 8;
		input -= 1000;
	}
	if (input >= 100) {
		output += 4;
		input -= 100;
	}
	if (input >= 10) {
		output += 2;
		input -= 10;
	}
	if (input >= 1) {
		output += 1;
		input -= 1;
	}

	return output;
}

void IPAND()
{
	int IP1(0), IP2(0), IP3(0), IP4(0), IP1A(0), IP2A(0), IP3A(0), IP4A(0);

	cout << "|| Please enter one octet at a time, then press ENTER ||" << endl;
	cout << "++====================================================++" << endl;

	system("pause");
	system("cls");

	cout << "IP Add: ";
	cin >> IP1;

	system("cls");

	cout << "IP Add: " << IP1 << ".";
	cin >> IP2;

	system("cls");

	cout << "IP Add: " << IP1 << "." << IP2 << ".";
	cin >> IP3;

	system("cls");

	cout << "IP Add: " << IP1 << "." << IP2 << "." << IP3 << ".";
	cin >> IP4;

	system("cls");
	//--------------------BREAK--------------------//
	cout << "Sub Add: ";
	cin >> IP1A;

	system("cls");

	cout << "Sub Add: " << IP1A << ".";
	cin >> IP2A;

	system("cls");

	cout << "Sub Add: " << IP1A << "." << IP2A << ".";
	cin >> IP3A;

	system("cls");

	cout << "Sub Add: " << IP1A << "." << IP2A << "." << IP3A << ".";
	cin >> IP4A;

	system("cls");

	cout << "+---------------------------------------+" << endl;
	cout << "|IP Add:\t\t" << IP1 << "." << IP2 << "." << IP3 << "." << IP4 << "\t|" << endl;
	cout << "|Sub Add:\t\t" << IP1A << "." << IP2A << "." << IP3A << "." << IP4A << "\t|" << endl;
	cout << "|Subnet:\t\t" << BiToDec(AND(DecToBi(IP1), DecToBi(IP1A))) << "." << BiToDec(AND(DecToBi(IP2), DecToBi(IP2A))) << "." << BiToDec(AND(DecToBi(IP3), DecToBi(IP3A))) << "." << BiToDec(AND(DecToBi(IP4), DecToBi(IP4A))) << "\t|" << endl;
	cout << "+---------------------------------------+" << endl;

	system("pause");

	main();
}

int AND(int input1, int input2)
{
	int output(0);

	if (input1 >= 10000000) {
		if (input2 >= 10000000) {
			output += 10000000;
			input2 -= 10000000;
		}
		input1 -= 10000000;
	}
	if (input2 >= 10000000) {
		input2 -= 10000000;
	}


	if (input1 >= 1000000) {
		if (input2 >= 1000000) {
			output += 1000000;
			input2 -= 1000000;
		}
		input1 -= 1000000;
	}
	if (input2 >= 1000000) {
		input2 -= 1000000;
	}


	if (input1 >= 100000) {
		if (input2 >= 100000) {
			output += 100000;
			input2 -= 100000;
		}
		input1 -= 100000;
	}
	if (input2 >= 100000) {
		input2 -= 100000;
	}


	if (input1 >= 10000) {
		if (input2 >= 10000) {
			output += 10000;
			input2 -= 10000;
		}
		input1 -= 10000;
	}
	if (input2 >= 10000) {
		input2 -= 10000;
	}


	if (input1 >= 1000) {
		if (input2 >= 1000) {
			output += 1000;
			input2 -= 1000;
		}
		input1 -= 1000;
	}
	if (input2 >= 1000) {
		input2 -= 1000;
	}


	if (input1 >= 100) {
		if (input2 >= 100) {
			output += 100;
			input2 -= 100;
		}
		input1 -= 100;
	}
	if (input2 >= 100) {
		input2 -= 100;
	}


	if (input1 >= 10) {
		if (input2 >= 10) {
			output += 10;
			input2 -= 10;
		}
		input1 -= 10;
	}
	if (input2 >= 10) {
		input2 -= 10;
	}


	if (input1 >= 1) {
		if (input2 >= 1) {
			output += 1;
			input2 -= 1;
		}
		input1 -= 1;
	}
	if (input2 >= 1) {
		input2 -= 1;
	}

	return output;
}