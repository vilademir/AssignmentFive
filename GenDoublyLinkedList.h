#include <iostream>
#include "ListNode.h"

using namespace std;


template <class list>
class GenDoublyLinkedList
{

public:
  GenDoublyLinkedList();
  ~GenDoublyLinkedList();

  void insertFront(list d);
  list removeFront();
  void insertBack(list d);
  list removeBack();

  void printList();
  int find(list value);

  unsigned int getSize();
  int deletePos(list pos);
  ListNode<list>* remove(list key);

  ListNode<list> *front;
  ListNode<list> *back;
  unsigned int size;

};



template <class list>
GenDoublyLinkedList<list>::GenDoublyLinkedList()
{
  front = NULL;
  size = 0;
}

template <class list>
GenDoublyLinkedList<list>::~GenDoublyLinkedList()
{
  //research
}

template <class list>
unsigned int GenDoublyLinkedList<list>::getSize()
{
  return size;
}

template <class list>
void GenDoublyLinkedList<list>::printList()
{
  ListNode<list> *curr = front;

  while(curr)
  {
    std::cout << curr -> data << endl;
    curr = curr -> next;
  }
}

template <class list>
void GenDoublyLinkedList<list>::insertBack(list d)
{
  ListNode<list> *node = new ListNode<list>(d);

  if(size == 0)
  {
    front = node;
  }else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

template <class list>
void GenDoublyLinkedList<list>::insertFront(list d)
{
  ListNode<list>* node = new ListNode<list>(d);
  if(size == 0) // empty list
  {
    back = node;
  }
  else // not empty
  {
    front->prev = node;
    node->next = front;
  }

  front = node;
  size++;
}

template <class list>
list GenDoublyLinkedList<list>::removeFront()
{
  ListNode<list> *temp = front;
  if(front->next == NULL) //only node in list
  {
    back = NULL;
  }else{
    front->next->prev = NULL;
  }

 front->next = front;
 temp->next = NULL;
 list val = temp->data;

 delete temp;
 size--;

 return val;
}

template <class list>
list GenDoublyLinkedList<list>::removeBack()
{
  ListNode<list> *temp = back;
  if(back->prev == NULL)
  {
    front = NULL;
  }
  else
  {
    back->prev->next = NULL;
  }
  back->prev = back;
  temp->prev = NULL;
  list val = temp->data;

  delete temp;
  size--;

  return val;
}

template <class list>
int GenDoublyLinkedList<list>::find(list value)
{
  int idx = -1;
  ListNode<list> *curr = front;

  while(curr != NULL)
  {
    ++idx;
    if(curr -> data == value)
    {
      break;
    }else{
      curr = curr -> next;
    }
  }
  if (curr == NULL)
  {
    idx = -1;
  }

  return idx;

}

template <class list>
int GenDoublyLinkedList<list>::deletePos(list pos)
{
  int idx = 0;
  ListNode<list> *prev = front;
  ListNode<list> *curr = front;

  while (idx != pos)
  {
    prev = curr;
    curr = curr -> next;
    ++idx;
  }
  //when it finds the position, add logic to verify value was found

  prev -> next = curr -> next;
  curr -> next = NULL;
  int d = curr -> data;
  size--;

  delete curr;

  return d;
}
