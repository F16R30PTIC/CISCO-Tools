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
#include <cmath>
using namespace std;

void BiDecConv(), IPAND(), Error(), BitChrt(), HexDecConv();
int DecToBi(int input), BiToDec(int input), AND(int input1, int input2);
char DecToHex(int input);

int main()
{
	system("color f1");
	system("cls");

	int answer;

	cout << "+-------MAIN MENU-------+" << endl;
	cout << "| 1. Decimal <> Binary\t|" << endl;
	cout << "| 2. Decimal <> Hex\t| < BUGS" << endl;
	cout << "| 3. EMPTY\t\t| < NOT YET IMPLEMENTED" << endl;
	cout << "| 4. Subnet Bit Chrt\t|" << endl;
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
		HexDecConv();
	}
	else if (answer == 3) {
		Error();
	}
	else if (answer == 4) {
		Error();
	}
	else if (answer == 5) {
		IPAND();
	}
	else if (answer == 6) {
		exit(0);
	}
	else {
		Error();
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

void HexDecConv()
{
	int input;

	cout << "TYPES" << endl;
	cout << "++======================++" << endl;
	cout << "|| 1. Decimal\t\t||" << endl;
	cout << "|| 2. Hex\t\t||" << endl;
	cout << "++======================++" << endl;
	cout << "Please enter type of # to be converted: ";
	cin >> input;

	system("cls");

	if (input == 1) {
		cout << "Please enter number to be converted: ";
		cin >> input;

		system("cls");

		cout << "Decimal:\t" << input << endl;
		cout << "Hex    :\t" << DecToHex(input) << endl;
	}
	else if (input == 2) {
		cout << "Please enter number to be converted: ";
		cin >> input;

		system("cls");

		cout << "Hex    :\t" << input << endl;
		cout << "Decimal:\t" << BiToDec(input) << endl;
	}

	system("pause");

	main();
}

char DecToHex(int input)
{
	int i, remainder;
	char plc0, plc1;

	remainder = input % 16;

	if (remainder != 0) {
		i = floor(input / 16);

		if (i < 10) {
			plc0 = i;
		}
		else if (i == 10) {
			plc0 = 'A';
		}
		else if (i == 11) {
			plc0 = 'B';
		}
		else if (i == 12) {
			plc0 = 'C';
		}
		else if (i == 13) {
			plc0 = 'D';
		}
		else if (i == 14) {
			plc0 = 'E';
		}
		else if (i == 15) {
			plc0 = 'F';
		}
	}
	else plc0 = 0;

	if (remainder < 10) {
		plc1 = remainder;
	}
	else if (remainder == 10) {
		plc1 = 'A';
	}
	else if (remainder == 11) {
		plc1 = 'B';
	}
	else if (remainder == 12) {
		plc1 = 'C';
	}
	else if (remainder == 13) {
		plc1 = 'D';
	}
	else if (remainder == 14) {
		plc1 = 'E';
	}
	else if (remainder == 15) {
		plc1 = 'F';
	}

	return plc0, plc1;
}

void IPAND()
{
	int IP1(0), IP2(0), IP3(0), IP4(0), IP1A(0), IP2A(0), IP3A(0), IP4A(0);
	char rndChar;

	cout << "++======================================================++" << endl;
	cout << "||  Please enter IP in std format ex. (192.168.1.0) OR  ||" << endl;
	cout << "||     Enter one octet at a time, then press ENTER      ||" << endl;
	cout << "++======================================================++" << endl;

	system("pause");
	system("cls");

	cout << "IP Add: ";
	cin >> IP1 >> rndChar >> IP2 >> rndChar >> IP3 >> rndChar >> IP4;

	system("cls"); 

	cout << "Sub Mask: ";
	cin >> IP1A >> rndChar >> IP2A >> rndChar >> IP3A >> rndChar >> IP4A;

	system("cls");

	cout << "+---------------------------------------+" << endl;
	cout << "|IP Add:\t\t" << IP1 << "." << IP2 << "." << IP3 << "." << IP4 << "\t|" << endl;
	cout << "|Sub Mask:\t\t" << IP1A << "." << IP2A << "." << IP3A << "." << IP4A << "\t|" << endl;
	cout << "|Subnet ID:\t\t" << BiToDec(AND(DecToBi(IP1), DecToBi(IP1A))) << "." << BiToDec(AND(DecToBi(IP2), DecToBi(IP2A))) << "." << BiToDec(AND(DecToBi(IP3), DecToBi(IP3A))) << "." << BiToDec(AND(DecToBi(IP4), DecToBi(IP4A))) << "\t|" << endl;
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

void Error()
{
	system("cls");

	cout << "++================================++" << endl;
	cout << "!!   PLEASE ENTER A VALID VALUE   !!" << endl;
	cout << "++================================++" << endl;

	system("pause");

	main();
}