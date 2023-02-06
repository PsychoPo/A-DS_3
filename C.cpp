#include <iostream>
using namespace std;
#include "H.h"

List::List(int n)
{
    count = n;
    for (size_t i = 0; i < count; i++)
    {
        addTail(rand() % 100);
    }
}

List::List(const List &A)
{
    count = 0;
    Head = NULL;
    Tail = NULL;
    Node *temp = A.Head;
    while (temp != NULL)
    {
        addTail(temp->x);
        count++;
        temp = temp->Next;
    }
}

List::~List()
{
    while (Head)
    {
        Tail = Head->Next;
        delete Head;
        Head = Tail;
    }
}

void List::addTail(double x)
{
    Node *temp = new Node;
    temp->Next = NULL;
    temp->x = x;

    if (Head != NULL)
    {
        temp->Prev = Tail;
        Tail->Next = temp;
        Tail = temp;
    }
    else
    {
        temp->Prev = NULL;
        Head = Tail = temp;
    }

    count++;
}

void List::addHead(double x)
{
    Node *temp = new Node;
    temp->Prev = NULL;
    temp->x = x;

    if (Head != NULL)
    {
        temp->Next = Head;
        Head->Prev = temp;
        Head = temp;
    }
    else
    {
        temp->Prev = NULL;
        Head = Tail = temp;
    }

    count++;
}

void List::addAfter(double x, int pos)
{
    Node *temp = Head;
    int number = 0;
    if (temp == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        Node *beg = temp;
        do
        {
            ++number;
            temp = temp->Next;
        } while (temp != NULL);
        if (pos > number)
        {
            cout << "Invalid position" << endl;
            return;
        }
        temp = beg;
        for (int i = 0; i < number; i++)
        {
            if (pos == i)
            {
                Node *n_temp = new Node;
                n_temp->x = x;
                n_temp->Next = temp->Next;
                temp->Next = n_temp;
            }
            else
                temp = temp->Next;
        }
    }
    count++;
}

void List::show()
{
    Node *temp = Tail;

    // while (temp != NULL)
    // {
    //     cout << temp->x << " ";
    //     temp = temp->Prev;
    // }
    // cout << endl;

    temp = Head;
    while (temp != NULL)
    {
        cout << temp->x << " ";
        temp = temp->Next;
    }
    cout << endl;
}

void List ::delHead()
{
    if (Head)
    {
        Node *temp = Head;
        Head = Head->Next;
        Head->Prev = NULL;
        delete temp;
    }
    else
        cout << "List is empty" << endl;

    count--;
}

void List ::delTail()
{
    if (Tail)
    {
        Node *temp = Tail;
        Tail = Tail->Prev;
        Tail->Next = NULL;
        delete temp;
    }
    else
        cout << "List is empty" << endl;

    count--;
}

void List::delN(int n)
{
    Node *temp = Head;
    while (n > 0)
    {
        temp = temp->Next;
        if (temp == nullptr)
        {
            cout << "Invalid position" << endl;
            return;
        }
        n--;
    }
    if (temp->Prev != nullptr)
        temp->Prev->Next = temp->Next;
    if (temp->Next != nullptr)
        temp->Next->Prev = temp->Prev;
    if (Head == temp)
        Head = temp->Next;
    delete temp;

    count--;
}

int List::SearchData(double x)
{
    int pos = 0;
    int k = 1;
    Node *temp = Head;
    while (temp != NULL)
    {
        if (temp->x == x)
        {
            pos = k;
            break;
        }
        k++;
        temp = temp->Next;
    }
    return pos;
}

bool List::SearchPos(double &x, int pos)
{
    if (pos < 1 || pos > count)
        return false;
    Node *temp = Head;
    for (int i = 0; i < pos - 1; i++)
        temp = temp->Next;
    x = temp->x;
    return true;
}

void List::ListL(List &L1, List &L2)
{
    double b = 0, c = 0;
    int k = 0;
    for (size_t i = 1; i <= L1.getCount(); i++)
    {
        L1.SearchPos(b, i);
        for (size_t j = 1; j <= L2.getCount(); j++)
        {
            L2.SearchPos(c, j);
            if (b == c)
                k++;
        }
        if (k == 0)
            this->addTail(b);
        k = 0;
    }
}