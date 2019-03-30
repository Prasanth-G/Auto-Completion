#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include "I:\Codes\VS\ConsoleApplication2\ConsoleApplication2\priorityQueue.cpp"
using namespace std;
//BASE CLASS TO BUILT TST
class node
{
public:
    char data;
    bool endofstring;
    node *left,*middle,*right;
    node(char input,bool endofstring=0):data(input),endofstring(endofstring),left(NULL),middle(NULL),right(NULL){}

};
//class tst
class TST
{
public:
    node *head;
    TST(node* ptr=NULL): head(ptr){}

    void insert_(node* &cpy,char *word);
    TST operator << (string input);

    char* search_(node* &cpy,char *word,int depth);
    char* Search(string input);

    bool printAll(node* cpy,char *buffer,int depth,int &Count,int total,PQueue<string> &PQ);
    friend ostream&  operator << (ostream &cout,TST a);

    bool autoComplete(char *buffer, PQueue<string> &PQ,int total=10);
    bool autoC(node* head,char *buffer,int depth, PQueue<string> &PQ,int total);

};
