#include<iostream>
using namespace std;

template<typename P>
class protoQueue {
public:
	P data;
	int priority;
	protoQueue<P>* next;
	protoQueue(P data, int priority, protoQueue<P>* next) :data(data), priority(priority), next(next) {}
};

template<typename P>
class PQueue {

	protoQueue<P>* head;
public:
	PQueue() :head(NULL) {}
	void enqueue(P input, int priority);
	P dequeue();
	bool isEmpty();
	void skip(int move);
	string peek();
	void display();
	void clear();
};
