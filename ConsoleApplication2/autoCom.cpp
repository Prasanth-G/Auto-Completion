// ConsoleApplication2.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include "I:\Codes\SEM 2\package\Data structures\TST.hpp"
using namespace std;
//void addToPara();
///////////////////////////MAIN
int main()
{
	TST a;
	string input;
	int length = 0;
	ifstream file("I:\\Codes\\SEM 2\\package\\Data structures\\Dictionary_1000.txt", ifstream::out);
	//    cout<<"HOW MANY WORDS(MAX) I WANT TO DISPLAY FOR U :";
	//    cin>>total;

	while (file)
	{
		file >> input;
		a << input;
	}

	char buffer[20], output[20], para[500] = { '\0' };
	bool forInsert;
	int lengthOfInput = 0, toPrint, lengthOfPara = 0;
	for (;; lengthOfInput++)
	{
		buffer[lengthOfInput] = _getch();
	l1:
		system("cls");
		cout << para;
		for (toPrint = 0; toPrint <= lengthOfInput; toPrint++)
			cout << buffer[toPrint];
		cout << endl << endl;
		switch (buffer[lengthOfInput])
		{
		case ' ':   buffer[lengthOfInput] = '\0';
			length = strlen(buffer);
			buffer[length] = ' ';
			buffer[length + 1] = '\0';
			cout << "buff" << buffer << endl;
			strcat_s(para, buffer);
			lengthOfPara += length;
			system("cls");
			cout << para;
			lengthOfInput = 0;
			output[lengthOfInput] = '\0';
			buffer[lengthOfInput] = '\0';
			--lengthOfInput;
			break;
		case '\t':
			length = strlen(output);
			output[length] = ' ';
			output[length + 1] = '\0';
			cout << "buff" << buffer << endl;
			strcat_s(para, output);
			lengthOfPara += length;
			system("cls");
			cout << para;
			lengthOfInput = 0;
			output[lengthOfInput] = '\0';
			buffer[lengthOfInput] = '\0';
			--lengthOfInput;
			break;
		case '\b':
			if (!lengthOfInput) lengthOfInput--;
			else if (lengthOfInput>0)
			{
				lengthOfInput -= 2;
				goto l1;
			}
			lengthOfPara -= 1;
			para[lengthOfPara + 1] = '\0';
			break;
		case '\r':
			if (!forInsert)
			{
				a << output;

				length = strlen(output);
				output[length] = ' ';
				output[length + 1] = '\0';
				cout << "buff" << buffer << endl;
				strcat_s(para, output);
				lengthOfPara += length;
				system("cls");
				cout << para;
				lengthOfInput = 0;
				output[lengthOfInput] = '\0';
				buffer[lengthOfInput] = '\0';
				--lengthOfInput;
			}

		}

		buffer[lengthOfInput + 1] = '\0';
		forInsert = a.autoComplete(buffer, 10);
		strcpy_s(output, buffer);
	}
	cout << "OUTPUT : " << output;
}


