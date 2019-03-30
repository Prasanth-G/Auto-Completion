#include"stdafx.h"
#include"I:\Codes\VS\ConsoleApplication2\ConsoleApplication2\stack.h"
void Stack::push(string data)
{
	head = new protoStack(data, head);
}

string Stack::pop()
{
	if (!isEmpty())
	{
		string output = head->data;
		protoStack* copy = head;
		head = head->next;
		delete copy;
		return output;
	}
	else
	{
		string data;
		return data;
	}
}
bool Stack::isEmpty()
{
	if (head) return 0;
	return 1;
}
