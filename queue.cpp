#include "stdafx.h"
#include "I:\Codes\VS\ConsoleApplication2\queue.h"

template<typename T>
void queue<T>::enqueue(T input)
{
	head = new protoQueue(input, head);
}
template<typename T>
T queue<T>::dequeue()
{
	protoQueue* temp = head;
	T output=temp->data;
	head = head->next;
	delete temp;
	return output;
}
template<typename T>
bool queue<T>::isEmpty()
{
	if (head) return 0;
	return 1;
}