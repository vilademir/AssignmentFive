#include <iostream>
#include <fstream>
#include "Faculty.h"
#include "Student.h"

using namespace std;

template <class tree>
class TreeNode
{
public:
  TreeNode();
  TreeNode(tree value);
  ~TreeNode();

  tree key;
  TreeNode<tree> *left;
  TreeNode<tree> *right;

};

template <class tree>
TreeNode<tree>::TreeNode()
{
  left = NULL;
  right = NULL;
}

template <class tree>
TreeNode<tree>::TreeNode(tree value)
{
  left = NULL;
  right = NULL;
  key = value;
  //data = k;
}

template <class tree>
TreeNode<tree>::~TreeNode()
{

}


template <class tree>
class BST
{
public:
  BST();
  virtual ~BST();

  void insert(tree value);
  bool contains(tree value);
  bool deleteRec(tree k);
  bool isEmpty();
  TreeNode<tree>* getSuccessor(TreeNode<tree> *d);
  tree find(tree searchKey);
  void traverseTree(TreeNode<tree>* node, string fileName);

  void filePrint(string fileName);
  void printTree();   //interative
  void recPrint(TreeNode<tree> *node);     //in-order traversal

private:
  TreeNode<tree> *root;
  TreeNode<tree> *successor;
};

template <class tree>
BST<tree>::BST()
{
  root = NULL;
}

template <class tree>
BST<tree>::~BST()
{
    //maybe iterate and delete == research
}

template <class tree>
void BST<tree>::filePrint(string fileName)
{
  traverseTree(root, fileName);
}

template <class tree>
bool BST<tree>::isEmpty()
{
  return root == NULL;
}

template <class tree>
void BST<tree>::printTree()
{
  recPrint(root);
}

template <class tree>
void BST<tree>::recPrint(TreeNode<tree> *node)
{
    if(node == NULL)
    {
      return;
    }

    recPrint(node->left);
    cout << node->key << '\n';
    recPrint(node->right);

}

template <class tree>
void BST<tree>::traverseTree(TreeNode<tree>* node, string fileName)
{
  ofstream tempFile;
  tempFile.open(fileName);

  if(node == NULL)
  {
    return;
  }

  traverseTree(node->left, fileName);
  tempFile << node->key << endl;
  traverseTree(node->right, fileName);

  tempFile.close();
}

template <class tree>
void BST<tree>::insert(tree value)
{
  //check if duplicates exists before doing all of this
  TreeNode<tree> *node = new TreeNode<tree>(value);
  if(isEmpty())
  {
    root = node;
  }else{
    TreeNode<tree> *current = root;
    TreeNode<tree> *parent; //empty node

    while(true)
    {
      parent = current;

      if(value < current->key)
      {
        current = current->left;

        if (current == NULL)  //we found insertion point
        {
          parent->left = node;
          break;
        }
      }else{
        current = current->right;
        if(current == NULL)
        {
          parent->right = node;
          break;
        }
      }
    }
  }
}

template <class tree>
tree BST<tree>::find(tree searchKey)
{
  TreeNode<tree>* current = root;

  while(current->key != searchKey)  //begin searching for value
  {
    if(current == NULL)
    {
      return false;
    }

    if(searchKey < current->key)
    {
      current = current->left;
    }
    else
    {
      current = current->right;
    }
  }

  return current->key;
}

template <class tree>
bool BST<tree>::contains(tree value)
{
  if(isEmpty())
  {
    return false;
  }
  else
  {
    TreeNode<tree> *current = root;

    while(current->key != value)  //begin searching for value
    {
      if(current == NULL)
      {
        return false;
      }

      if(value < current->key)
      {
        current = current->left;
      }else{
        current = current->right;
      }
    }
  }
  return true;
}

template <class tree>
bool BST<tree>::deleteRec(tree k)
{
  //check if empty
  //check if value exists

  if(!contains(k))
  {
    return false;
  }else{
    TreeNode<tree> *parent = root;
    TreeNode<tree> *current = root;
    bool isLeft = true;

    //now we need to find it

    while(current->key != k)
    {
      parent = current;

      if(k < current->key)
      {
        isLeft = true;
        current = current->left;
      }else{
        isLeft = false;
        current = current->right;
      }
      if(current == NULL)
      {
        return false;
      }
    }

    if(current->left == NULL && current->right == NULL)
    {
      if(current = root)
      {
        root = NULL;

      }else if(isLeft){
        parent->left = NULL;
      }else{
        parent->right = NULL;
      }
      //now check if node has one child
    }else if(current->right == NULL){   //no right child = left node
      if(current == NULL)
      {
        root = current->left;
      }else if(isLeft){
        parent->left = current->left;
      }else{  //right child
        parent->right = current->left;
      }
    }else if(current->left == NULL){   //no left child = right node
      if(current == NULL)
      {
        root = current->right;
      }else if(isLeft){
        parent->left = current->right;
      }else{  //right child
        parent->right = current->right;
      }
    }else{  //node has 2 children

      TreeNode<tree>* successor = getSuccessor(current);

      if(current == root)
      {
        root == successor;
      }else if (isLeft){
        parent->left = successor;
      }else{
        parent->right = successor;
      }

      successor->left = current->left;
    }
  }
  return true;
}

template <class tree>
TreeNode<tree>* BST<tree>::getSuccessor(TreeNode<tree> *d)
{
  TreeNode<tree> *sp = d; //successor parent
  TreeNode<tree> *successor = d; //should be one right, all the way left
  TreeNode<tree> *current = d->right;

  while(current != NULL)
  {
    sp = successor;
    successor = current;
    current = current->left;
  }

  if(successor != d->right)
  {
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}
