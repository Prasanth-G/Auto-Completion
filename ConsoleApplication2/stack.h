#include"stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class protoStack {
public:
	string data;
	protoStack* next;
	protoStack(string data, protoStack* next) :data(data), next(next) {}
};

class Stack {
	protoStack* head;
public:
	Stack() :head(NULL) {}
	void push(string data);
	string pop();
	bool isEmpty();
};
