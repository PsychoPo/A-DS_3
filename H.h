#ifndef H_H
#define H_H

#include <iostream>
using namespace std;

struct Node
{
    double x;
    Node *Next, *Prev;
};

class List
{
    int count;
    Node *Head, *Tail;

public:
    List() : count(0), Head(NULL), Tail(NULL) {}
    List(int n);
    List(const List &A);
    ~List();

    int getCount() const { return count; }

    void show();
    void addTail(double x);
    void addHead(double x);
    void addAfter(double x, int numb);
    void delHead();
    void delTail();
    void delN(int n);
    int SearchData(double x);
    bool SearchPos(double &x, int pos);
    void ListL(List &L1, List &L2);
};

#endif