// ConsoleApplication2.cpp : Defines the entry point for the console application.
//pre defined headers
#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <fstream>
using namespace std;
//user defined header for ternary search tree, stack , queue and linked list
#include "TST.h"
#include "I:\Codes\VS\ConsoleApplication2\ConsoleApplication2\stack.h"
#include "I:\Codes\VS\ConsoleApplication2\ConsoleApplication2\linkedList.h"


///////////////////////////MAIN
int main()
{
	TST P;	
	string input;
	ifstream file1("resources\\google-10000-english.txt", ifstream::out), file2("resources\\freq_1000.txt", ifstream::out);
	
	//building TST by reading strings from file
	while (file1)
	{
		getline(file1,input);
		P << input;
		getline(file2,input);
		P << input;
	}

	//variables to store datas
	string temp;															//temporary word buffers
	char* WordBuffer = (char*)temp.c_str();
	string sent;
	char* SentenceBuffer = (char*)sent.c_str();												//to store sentence
	int WordLength = 0, SentenceLength = 0, i = 0, j = 0, end = 1;
	PQueue<string> predict;													//queue for sending it to autocomplete funtion
	Stack history;															//to store previous words
	while (end)
	{

		WordBuffer[WordLength] = _getch();									//getting input
		WordBuffer[WordLength + 1] = '\0';
		switch (WordBuffer[WordLength])
		{
		case ' ':
			
			SentenceBuffer[SentenceLength++] = WordBuffer[WordLength];
			SentenceBuffer[SentenceLength] = '\0';

			history.push(temp);
			WordLength = 0;

			break;

		case '\r':
			if (SentenceLength)
			{
				predict.clear();
				WordLength = 0;
				SentenceLength = 0;
				cout << "STRING :" << SentenceBuffer << endl << endl;

				SentenceBuffer[SentenceLength] = '\0';
				WordBuffer[WordLength] = '\0';
			}
			continue;

		case '\t':
			
			if (!predict.isEmpty())
			{
				temp = predict.peek();
				predict.skip(1);
			
				SentenceLength = SentenceLength - WordLength;

				for (i = SentenceLength, j = 0; i < temp.size() + SentenceLength; i++, j++)
					SentenceBuffer[i] = temp[j];

				SentenceLength += j;
				WordLength = temp.size();

				SentenceBuffer[SentenceLength] = '\0';
				WordBuffer[WordLength] = '\0';

			}
			break;

		case'\b':		
			WordLength--;
			SentenceLength--;
			if (WordLength < 0 || SentenceLength < 0)
			{	
				if (!history.isEmpty())
				{
					temp = history.pop();
					WordLength = temp.size();
				}
				else 
				{
					WordLength = 0;
					SentenceLength = 0;
					continue;
				}
			}

			SentenceBuffer[SentenceLength] = '\0';
			WordBuffer[WordLength] = '\0';
			predict.clear();

			P.autoComplete(SentenceBuffer, predict,25);
			P.autoComplete(WordBuffer, predict,25);

			break;
			
		default:

			SentenceBuffer[SentenceLength] = WordBuffer[WordLength];
			SentenceBuffer[SentenceLength+1] = '\0';
			
			predict.clear();
			P.autoComplete(SentenceBuffer, predict,25);
			P.autoComplete(WordBuffer, predict,25);

			WordLength++;
			SentenceLength++;

		}
		system("cls");
		WordBuffer[WordLength] = '\0';
		SentenceBuffer[SentenceLength] = '\0';
		
		cout << SentenceBuffer << endl << endl;
		predict.display();	
	}

	system("cls");
	cout <<"you entered: " << SentenceBuffer << endl << endl;
	cin >> temp;

}
