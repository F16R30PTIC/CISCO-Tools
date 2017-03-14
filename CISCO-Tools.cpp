// Binary-Decimal.cpp : Defines the entry point for the console application.
//

//-----------------------------//
//      Converter V1.0.1       //
//      ================       //
//                             //
// Fixes:                  3   //
// Additions:              1   //
// Lines Added:            ?   //
// NOTES:                      //
// Decimal <> Hex coverter     //
// started: Many bugs, only    //
// returns unknown characters. //
//-----------------------------//

#include "stdafx.h"
#include <iostream>
#include <cmath>;
using namespace std;

void BiDecConv(), IPAND(), Error(), Ranges(), SubMap();
int DecToBi(int input), BiToDec(int input), AND(int input1, int input2), NumNetBits(int binary);
char DecToHex(int input);

int main()
{
	system("color f1");
	system("cls");

	int answer;

	cout << "+-------MAIN MENU-------+" << endl;
	cout << "| 1. Decimal <> Binary\t|" << endl;
	cout << "| 2. Decimal <> Hex\t| < NOT YET IMPLEMENTED" << endl;
	cout << "| 3. Subnet Ranges\t|" << endl;
	cout << "| 4. Subnet Map\t| < NOT YET IMPLEMENTED" << endl;
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
		Error();
	}
	else if (answer == 3) {
		Ranges();
	}
	else if (answer == 4) {
		Error();
		SubMap();
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

void Ranges()
{
	int octet(0), numHosts(0), range(-1);

	cout << "++==============================================++" << endl;
	cout << "||                     NOTE                     ||" << endl;
	cout << "||  THIS FUNCTION ONLY WORKS FOR ONE OCTET OF   ||" << endl;
	cout << "||                  THE SUBNET                  ||" << endl;
	cout << "++==============================================++" << endl;

	system("pause");
	system("cls");

	cout << "Enter a subnet octet to find the ranges of each subnet: ";
	cin >> octet;

	system("cls");

	numHosts = pow(2, (8 - NumNetBits(DecToBi(octet))));

	cout << "Ranges of each subnet: " << endl;

	while (range < 255) {
		cout << range + 1 << " - " << range + numHosts << endl;
		range += numHosts;
	}

	system("pause");

	main();
}

int NumNetBits(int binary)
{
	int num(0);

	if (binary >= 10000000) {
		num += 1;
		binary -= 10000000;
	}
	if (binary >= 1000000) {
		num += 1;
		binary -= 1000000;
	}
	if (binary >= 100000) {
		num += 1;
		binary -= 100000;
	}
	if (binary >= 10000) {
		num += 1;
		binary -= 10000;
	}
	if (binary >= 1000) {
		num += 1;
		binary -= 1000;
	}
	if (binary >= 100) {
		num += 1;
		binary -= 100;
	}
	if (binary >= 10) {
		num += 1;
		binary -= 10;
	}
	if (binary >= 1) {
		num += 1;
		binary -= 1;
	}

	return num;
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

void SubMap()
{
	int cnt(1), hosts(0);
	ofstream binFile;
	
	cout << "++===========================================++" << endl;
	cout << "|| THIS FEATURE IS TO CREATE A TEMPORARY MAP ||" << endl;
	cout << "||   FOR A SUBNET. CHANGES CAN BE SAVED TO   ||" << endl;
	cout << "||           A TEXT FILE WHEN DONE           ||" << endl;
	cout << "++===========================================++" << endl;

	system("pause");

	cout << "Enter the number of hosts in this subnet: ";
	cin >> hosts;
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
