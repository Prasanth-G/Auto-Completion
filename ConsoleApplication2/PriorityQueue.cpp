#include "stdafx.h"
#include "I:\Codes\VS\ConsoleApplication2\ConsoleApplication2\priorityQueue.h"
//Add elements to the queue
template<typename P>
void PQueue<P>::enqueue(P input, int priority)
{
	if (head)
	{
		protoQueue<P>* Copy = head;
		protoQueue<P>* prev = NULL;
		if (priority > head->priority && input != head->data)
		{
			head = new protoQueue<P>(input, priority, head);
		}
		else
		{
			int check = 1;
			while (Copy && priority <= Copy->priority )
			{
				if (Copy->data == input)
					check = 0;
				prev = Copy;
				Copy = Copy->next;
			}
			if(check)
				prev->next = new protoQueue<P>(input, priority, prev->next);
		}
	}
	else
		head = new protoQueue<P>(input, priority, head);
}

//To check whether the queue is empty or not
template<typename P>
bool PQueue<P>::isEmpty()
{
	if (head) return 0;
	return 1;
}

//To dequeue elements from queue
template<typename P>
P PQueue<P>::dequeue()
{
	if (head)
	{
		protoQueue<P>* copy = head;
		head = head->next;
		P output = copy->data;
		delete copy;
		return output;
	}
	else
	{
		P data;
		return data;
	}
}
template<typename P>
void PQueue<P>::skip(int move)
{
	protoQueue<P>* copy = head;
	while (move && copy)
	{
		enqueue(dequeue(),copy->priority);
		copy = copy->next;
		move--;
	}
}
template<typename P>
void PQueue<P>::display()
{
	protoQueue<P>* copy = head;
	while (copy)
	{
		cout << copy->data << endl;
		copy = copy->next;
	}
}
template<typename P>
void PQueue<P>::clear()
{
	while (!isEmpty())
		dequeue();
}
template<typename P>
string PQueue<P>::peek()
{
	string temp;
	if (!isEmpty())
	{
		temp = head->data;
		return temp;
	}
	else
		return temp;
}