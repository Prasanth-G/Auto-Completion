#pragma once
#include"stdafx.h"
#include "I:\Codes\VS\ConsoleApplication2\TST.h"
//for inserting a char array
void TST::insert_(node* &cpy, char *word)
{

	if (!cpy)
		cpy = new node(*word);
	if (*word < cpy->data)
		insert_(cpy->left, word);
	else if (*word > cpy->data)
		insert_(cpy->right, word);
	else
	{
		if (*(word + 1))
			insert_(cpy->middle, word + 1);
		else
			cpy->endofstring = 1;
	}
}
//generally we use string (instead of char*) so..
TST TST::operator << (string input)
{
	char *word = (char*)input.c_str();
	if (head)
	{
		node* cpy = head;
		insert_(cpy, word);
	}
	else insert_(head, word);
	TST a(head);
	return a;
}
//TO PRINT ALL THE WORDS BELOW THE POINTER *head
bool TST::printAll(node* head, char* buffer, int depth, int &Count, int total,PQueue<string> &PQ)
{
	if (head && Count<total)
	{
		printAll(head->left, buffer, depth, Count, total,PQ);
		buffer[depth] = head->data;
		if (head->endofstring)
		{
			if (total >= 0) Count++;
			buffer[depth + 1] = '\0';
			//cout << buffer << endl;
			PQ.enqueue(buffer, 0);
			return 1;
		}
		printAll(head->middle, buffer, depth + 1, Count, total,PQ);
		printAll(head->right, buffer, depth, Count, total,PQ);

	}
	else if (!Count && !head) return 0;
	return 0;
}
ostream&  operator << (ostream &cout, TST a)
{
	PQueue<string> PQ;
	char buffer[20] = { '\0' };
	int Count = -2;
	a.printAll(a.head, buffer, 0, Count, -1,PQ);
	while (!PQ.isEmpty())
		cout << PQ.dequeue() << endl;
	return cout;
}
bool TST::autoC(node* head, char* buffer, int depth,PQueue<string> &PQ, int total)
{
	if (head)
	{
		if (head->data > *buffer)
		{
			return autoC(head->left, buffer, depth,PQ, total);
		}
		else if (head->data < *buffer)
		{
			return autoC(head->right, buffer, depth,PQ, total);
		}
		else
		{
			if ((head->data == *buffer) && !*(buffer + 1))
			{
				int Count = 0; return printAll(head->middle, buffer - depth + 1, depth, Count, total,PQ);
			}
			else
				return autoC(head->middle, buffer + 1, depth,PQ, total);
		}
	}
	else return 0;
}

bool TST::autoComplete(char *input,PQueue<string> &PQ ,int total)
{
	return autoC(head, input, strlen(input),PQ, total);
}
//TO SEARCH
char* TST::search_(node* &cpy, char *word, int depth)
{

	if (cpy)
	{
		if (*word == cpy->data)
		{
			if (cpy->endofstring && !*(word + 1))
			{
				char* temp = (char*)word - depth;
				return temp;
			}
			else
				return search_(cpy->middle, word + 1, depth + 1);
		}
		else if (*word < cpy->data)
			return search_(cpy->left, word, depth);
		else if (*word > cpy->data)
			return search_(cpy->right, word, depth);
	}
	return 0;

}
//FOR SIMPLICITY
char* TST::Search(string input)
{
	char *word = (char*)input.c_str();
	return search_(head, word, 0);
}
