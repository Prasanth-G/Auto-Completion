#include<iostream>
#include<string>
using namespace std;

template<typename T>

class protoQueue {
public:
	T data;
	protoQueue* next;
	protoQueue(T data, protoQueue* next) :data(data), next(next){}
};

template <typename T>
class queue {
	protoQueue<T>* head;
public:
	void enqueue(T input);
	T dequeue();
	bool isEmpty();
};
