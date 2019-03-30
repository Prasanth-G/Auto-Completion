#include "stdafx.h"
#include<I:\Codes\VS\ConsoleApplication2\ConsoleApplication2\linkedList.h>
//template<typename L>
void List::push(char input)
{
	tail = new protoList(input,tail);
	if (!head)
		head = tail;
}
//template<typename L>
char List::pop()
{
	if (!head)
	{
		protoList* temp = head;
		while (temp->next)
			temp = temp->next;
		char output = temp->data;
		tail = temp;
		delete temp;
		return output;
	}
	else
	{
		char data='\0';
		return data;
	}
}
//template<typename L>
bool List::isEmpty()
{
	if (head) return 0;
	return 1;
}
//template<typename L>
void List::display(char ch)
{
	protoList* copy = head;
	while (copy)
	{
		cout << copy->data << ch;
		copy = copy->next;
	}
}