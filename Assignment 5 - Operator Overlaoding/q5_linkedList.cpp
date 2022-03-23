#include <iostream>
using namespace std;

template <typename T>
struct node {
  public:
    T data;
    node * next;
    node(T, node * = NULL);

    friend ostream& operator<< (ostream& out, const node<T> n){
      out << ">> Data: " << n.data << " Next Node @: " << n.next;
      return out;
    };
};

template <typename T>
node<T>::node(T n, node * next){
  this->data = n;
  this->next = next;
};

template <typename T>
class List {
private:
  node<T> * head;
  int size;
public:
  List();
  List(const List<T>&);
  ~List();
  node<T> * getHead();
  List& operator+(const List<T>&);
  List& operator!(void);
  bool operator==(const List<T>&);
  List& operator=(const List<T>&);
  node<T>* operator[](int);

  List& insert(const T&);
  List& insertBegining(const T&);
  List& deleteNode(const int&);

  template <typename U>
  friend istream& operator>>(istream&, List<U>&);

  template <typename U>
  friend ostream& operator<< (ostream&, const List<U>&);
};

template <typename T>
List<T>::List(){
  head = NULL; size = 0;
}

template <typename T>
List<T>::List(const List<T>& l){
  node<T> * ptr = l.head;
  while (ptr != NULL){
    this->insert(ptr->data);
    ptr = ptr->next;
  }
}

template <typename T>
List<T>::~List(){
  node<T> * current = head;
  while (current != NULL){
    node<T> * next = current->next;
    delete current;
    current = next;
  }
  head = NULL;
}

template <typename T>
List<T>& List<T>::insert(const T &n){
  node<T> * newNode = new node<T>(n);
  if (head == NULL)
    head = newNode;
  else {
    node<T> * temp = head;
    while (temp->next != NULL)
      temp = temp->next;
    temp->next = newNode;
  }
  size++;
  return *this;
};

template <typename T>
node<T> * List<T>::getHead(){
  return head;
}

template <typename T>
List<T> &List<T>::insertBegining(const T &n){
  node<T> * newNode = new node<T>(n, head);
  head = newNode; size++;
  return (*this);
}

template <typename T>
List<T>& List<T>::operator+(const List<T>& l){
  static List<T> full;
  full.~List();
  full = *this;
  node<T> * ptr = l.head;
  while (ptr != NULL){
    full.insert(ptr->data);
    ptr = ptr->next;
  }
  return full;
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& l){
  node<T> * ptr = l.head;
  while (ptr != NULL){
    this->insert(ptr->data);
    ptr = ptr->next;
  }
  return *this;
}

template <typename T>
List<T>& List<T>::operator!(void){
  static List<T> reverse;
  reverse.~List();
  node<T> * ptr = this->head;
  while (ptr != NULL){
    reverse.insertBegining(ptr->data);
    ptr = ptr->next;
  }
  return reverse;
}

template <typename T>
bool List<T>::operator==(const List<T>& l){
  bool flag = true;
  node<T> * left = this->head; 
  node<T> * right = l.head;
  while (left != NULL || right != NULL){
    if (left->data != right->data){
      flag = false;
      break;
    }
    left = left->next;
  }
  return flag;
}

template <typename T>
node<T>* List<T>::operator[](int index){
  node<T> * ptr = this->head;
  if (index > size-1){
    cout << "Error: Invalid Size.\n";
    return head;
  }
  while (index != 0){
    index--;
    ptr = ptr->next;
  }
  return ptr;
}

template <typename T>
istream& operator>>(istream& in, List<T>& l){
  cout << "Enter number of nodes: ";
  int n; in >> n;
  cout << "Enter #values:\n";
  for (int i = 0; i < n; i++){
    T x; cin >> x; 
    l.insert(x);
  }
  return in;
};

template <typename T>
ostream& operator<< (ostream& out, const List<T>& l){
  node<T> * ptr = l.head;
  if (ptr == NULL)
    out << "Empty List.\n";
  else {
    out << "List: ";
    while (ptr != NULL){
      out << ptr->data << " -> ";
      ptr = ptr->next;
    }
    out << "\n";
  }
  return out;
};

int main(void){

  List<int> i;
  i.insert(10);
  i.insert(20);
  cout << i;
  List<int> j;
  j.insert(30);
  j.insert(100);
  j.insert(400);
  cout << j;
  cout << *(j.getHead()) << "\n";
  cout << "i+j " << i+j;
  cout << "not i " << !(i);
  cout << "j " << j;
  cout << "not j " << !(j);
  cout << "not (i+j) " << !(i+j);
  cout << *j[1] << "\n";
  return 0;
}