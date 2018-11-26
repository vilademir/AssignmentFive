#include <iostream>

using namespace std;

template <class S>
class Stack
{
  public:
    Stack();
    ~Stack();
    Stack(int val);
    Stack(int maxSize, S type);

    void push(S d);
    S pop();
    S peek();

    bool isFull();
    bool isEmpty();

    int size;
    int top;

    S* myArray;
};

template <class S>
Stack<S>::Stack() // Default constructor
{
  // initialize variables to default value
}

template <class S>
Stack<S>::Stack(int maxSize) // Overload constructor
{
  myArray = new S[maxSize];
  size = maxSize;
  top = -1;
}

template <class S>
Stack<S>::~Stack() // Destructor
{
  delete myArray;
  cout << "stack destroyed" << endl;
}

template <class S>
void Stack<S>::push(S d)
{
  if(isFull() == true)
  {
    top == -1;
  }
  // Check if not full
  if(isFull() == false)
  {
      myArray[++top] = d;
  }
}

template <class S>
S Stack<S>::pop()
{
  // Check if empty
  if(isEmpty() == false)
  {
    return myArray[top--];
  }
}

template <class S>
S Stack<S>::peek()
{
  return myArray[top];
}

template <class S>
bool Stack<S>::isFull()
{
  return(top == size - 1);
}

template <class S>
bool Stack<S>::isEmpty()
{
  return(top == -1);
}
