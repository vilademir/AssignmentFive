#include <iostream>

using namespace std;


template <class list>
class ListNode
{
public:
  ListNode();
  ListNode(list d);
  ~ListNode();

  ListNode<list> *prev;
  ListNode<list> *next;
  list data;

};


template <class list>
ListNode<list>::ListNode()
{

}

template <class list>
ListNode<list>::ListNode(list d)
{
  data = d;
  next = NULL;
}

template <class list>
ListNode<list>::~ListNode()
{

}
