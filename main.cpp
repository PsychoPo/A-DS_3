#include <iostream>
using namespace std;
#include "H.h"
#include "C.cpp"

// Вариант №20.

int main()
{
  int key = 0;
  List lst;
  while (key != 10)
  {
    cout << "\n1 - Add Head.\n2 - Add Tail.\n3 - Add after N.\n4 - Show list.\n5 - Delete Head.\n6 - Delete Tail.\n7 - Delete N-element.\n8 - Search Data.\n9 - Search N.\n";
    cout << "11 - L1,L2 = L3\n10 - EXIT.\nEnter: ";
    cin >> key;
    cout << endl;
    switch (key)
    {

    case 1:
    {
      double a;
      cout << "\nEnter the number: " << endl;
      cin >> a;
      lst.addHead(a);
    }
    break;

    case 2:
    {
      double b;
      cout << "\nEnter the number: " << endl;
      cin >> b;
      lst.addTail(b);
    }
    break;

    case 3:
    {
      int n;
      double c;
      cout << "\nEnter the number: " << endl;
      cin >> c;
      cout << "\nEnter the number position after you want to add: " << endl;
      cin >> n;
      lst.addAfter(c, n);
    }
    break;

    case 4:
    {
      cout << "\nList: \n";
      lst.show();
    }
    break;

    case 5:
    {
      lst.delHead();
      cout << "The Head was deleted." << endl;
    }
    break;

    case 6:
    {
      lst.delTail();
      cout << "The Tail was deleted." << endl;
    }
    break;

    case 7:
    {
      int p;
      cout << "\nEnter the number position what you want to delete: " << endl;
      cin >> p;
      lst.delN(p);
      cout << "The N-element was deleted." << endl;
    }
    break;

    case 8:
    {
      int data, r;
      cout << "\nEnter the Data what you want to find: " << endl;
      cin >> data;
      r = lst.SearchData(data);
      if (r)
      {
        cout << "\nElement found: " << r << endl;
      }
      else
        cout << "Not found.";
    }
    break;

    case 9:
    {
      int pos;
      double el;
      bool res;
      cout << "\nEnter the number position what you want to find: " << endl;
      cin >> pos;
      res = lst.SearchPos(el, pos);
      if (res)
      {
        cout << "\nElement found: " << el << endl;
      }
      else
        cout << "\nNot found.\n";
    }
    break;

    case 11:
    {
      List L1, L2, L3;
      double a;
      cout << "\nEnter L1 list:\n";
      cin >> a;
      L1.addHead(a);
      cin >> a;
      L1.addTail(a);
      cin >> a;
      L1.addTail(a);
      cin >> a;
      L1.addTail(a);
      cout << "\nL1:\n";
      L1.show();
      cout << "\nEnter L2 list:\n";
      cin >> a;
      L2.addHead(a);
      cin >> a;
      L2.addTail(a);
      cin >> a;
      L2.addTail(a);
      cin >> a;
      L2.addTail(a);
      cout << "\nL2:\n";
      L2.show();
      cout << "\nProcessing...\n";
      L3.ListL(L1, L2);
      cout << "\nDone!\n";
      cout << "\nL3:\n";
      L3.show();
    }
    break;
    }
  }

  return 0;
}