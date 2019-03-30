#include<iostream>
using namespace std;
//template<typename L>
class protoList {
public:
	char data;
	protoList* next;
	protoList(char data,protoList* next):data(data),next(next){}
};
//template<typename L>
class List {
	protoList* tail; 
	protoList* head;
public:
	List() :tail(NULL),head(NULL){}
	void push(char input);
	char pop();
	bool isEmpty();
	void display(char ch='\0');
};