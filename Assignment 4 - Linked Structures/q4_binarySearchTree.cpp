#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

template <typename T>
struct node {
  public:
    T data;
    node * left;
    node * right;
    node(T, node<T> * = NULL, node<T> * = NULL);
};

template <typename T>
node<T>::node(T data, node<T> * right, node<T> * left){
  this->data = data;
  this->right = right;
  this->left = left;
}

template <typename T>
class tree {
  private:
    node<T> * root;
    int size; // No. of Nodes
  
  public:
    tree();
    node<T> * getRoot();
    int getSize();
    tree &insertNode(const T&);
    tree &deleteNode(const T&);
    void search(const T&);
    int height(const node<T> *);
    void dfsTraverse(node<T> *);
    void bfsTraverse(node<T> *);
};

template <typename T>
tree<T>::tree(){
  root = NULL;
  size = 0;
}

template <typename T>
node<T> * tree<T>::getRoot(){
  return root;
}

template <typename T>
int tree<T>::getSize(){
  return size;
}

template <typename T>
tree<T> &tree<T>::insertNode(const T &value){
  node<T> * r = this->root;
  if (r == NULL){
    this->root = new node<T>(value);
    this->size++;
    return (*this);
  }
  node<T> * parent, * n;
  while(r != NULL){
    // To avoid duplicate data in tree
    if (r->data == value){
      cout << "Error: Node already exists.\n";
      return (*this);
    }
    parent = r;
    if (r->data > value)
      r = r->left;
    else
      r = r->right;
  }
  n = new node<T>(value);
  if (parent->data > value)
    parent->left = n;
  else
    parent->right = n;
  this->size++;
  return (*this);
}

template <typename T>
tree<T> &tree<T>::deleteNode(const T &value){
  node<T> * previous;
  node<T> * r = this->root;
  while (r != NULL){
    if (value == r->data)
      break;
    previous = r;
    if (value < r->data)
      r = r->left;
    else
      r = r->right;
  }
  if (r == NULL)
    return (*this);
  if (r->left == NULL && r->right == NULL){
    if (previous->left == r)
      previous->left = NULL;
    else
      previous->right = NULL;
    delete r;
    return (*this);
  }
  node<T> * n;
  if (r->left != NULL){
    n = r->left;
    if (n->right == NULL){
      r->data = n->data;
      r->left = n->left;
      delete r;
      return (*this);
    }
    while (n->right != NULL){
      previous = n;
      n = n->right;
    }
    r->data = n->data;
    previous->right = n->left;
    delete r;
    return (*this);
  }
  if (r->right != NULL){
    n = r->right;
    if (n->left == NULL){
      r->data = n->data;
      r->right = n->right;
      delete r;
      return (*this);
    }
    while (n->left != NULL){
      previous = n;
      n = n->left;
    }
    r->data = n->data;
    previous->left = n->right;
    delete r;
    return (*this);
  }
  return (*this);
}

template <typename T>
void tree<T>::search(const T &value){
  node<T> * n = this->root;
  while (n != NULL){
    if (value == n->data){
      cout << ">> Value " << value << " is found at address " << n  << ".\n";
      break;
    }
    if (value < n->data)
      n = n->left;
    else if (value > n->data)
      n = n->right;
  }
  if (n == NULL){
    cout << ">> Value " << value << " not found in tree.\n";
    return;
  }
}

template <typename T>
int tree<T>::height(const node<T> *n){
  if(n == NULL)
    return 0;
  else{
    int left, right;
    left = height(n->left);
    right = height(n->right);
    return left >= right ? left+1 : right+1;
  }
}

template <typename T>
void tree<T>::dfsTraverse(node<T> * n){
  if(n != NULL){
    dfsTraverse(n->left);
    cout << n->data << " ";
    dfsTraverse(n->right);
  }
}

template <typename T>
void tree<T>::bfsTraverse(node<T> * n){
  if (n != NULL){
    cout << n->data << " ";
    if (n->left != NULL && n->right != NULL){
      bfsTraverse(n->left);
      bfsTraverse(n->right);
    } else if (n->left == NULL && n->right != NULL){
      bfsTraverse(n->right);
    } else if (n->right == NULL && n->left != NULL){
      bfsTraverse(n->left);
    }
  } else return;
}

int main(void){

  tree<int> t;
  t.insertNode(5);
  t.insertNode(1);
  t.insertNode(10);
  t.insertNode(6);
  t.insertNode(23);
  
  cout << "\nDFS Traverse: ";
  t.dfsTraverse(t.getRoot());
  cout << "\nBFS Traverse: ";
  t.bfsTraverse(t.getRoot());
  cout << "\nHeight: " << t.height(t.getRoot());
  cout << "\n\n";

  t.search(6);
  t.deleteNode(6);
  t.search(6);
  t.deleteNode(11);

  cout << "\nDFS Traverse: ";
  t.dfsTraverse(t.getRoot());
  cout << "\nBFS Traverse: ";
  t.bfsTraverse(t.getRoot());
  cout << "\nHeight: " << t.height(t.getRoot());
  cout << "\n";

  return 0;
}