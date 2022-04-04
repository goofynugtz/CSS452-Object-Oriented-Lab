#include <iostream>
using namespace std;

template <typename T>
struct node {
  public:
    T data;
    int payload;
    node * next;
    node(T,T = 1, node * = NULL);
    ~node();
};

template <typename T>
node<T>::node(T n, T w, node * next){
  this->data = n;
  this->payload = w;
  this->next = next;
};

template <typename T>
node<T>::~node(){
}

template <typename T>
class List {
  private:
    node<T> * head ;
    int size;

  public:
    List();
    List(const List &);
    ~List();
    node<T> * getHead();
    int getSize();
    List &insertNode(const T&);
    List &deleteNode(const int&);
    List &insertBegining(const T&, const int& = 1);
    List &concatenate(List<T>&);
    int search(const T&);
    friend ostream &operator<< (ostream &out, const List<T> &l){
      node<T> * ptr = l.head;
      if (ptr == NULL)
        out << "Empty List\n";
      else {
        // out << ">> ";
        while (ptr != NULL){
          out << ptr->data << " (" << ptr->payload << ")" << " -> ";
          ptr = ptr->next;
        }
        out << "\n";
      }
      return out;
    };
};

template <typename T>
List<T>::List(){
  head = NULL;
  size = 0;
}

template <typename T>
List<T>::List(const List &list){
  head->data = list.head->data;
  node<T> * t;
  const node<T> * c = list.head->next;
  for (int i = 0; i <= list.size; i++){
    node<T> * n = new node<T>(c->data);
    if (i==0)
      head->next = n;
    else 
      t->next = n;
    t = n;
    c = c->next;
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
node<T> * List<T>::getHead(){
  return head;
}

template <typename T>
int List<T>::getSize(){
  return size;
}

template <typename T>
List<T> &List<T>::insertNode(const T &n){
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
List<T> &List<T>::deleteNode(const int &i){
  int index = i;
  if (head == NULL) {
    cout << "List empty." << endl;
    return (*this);
  }
  if (index > size) {
    cout << "Error: Index out of range.\n";
    return (*this);
  }
  node<T> * ptr1 = head;
  node<T> * ptr2 = NULL;
  if (index == 1) { 
    head = head->next;
    delete ptr1;
  } else {
    while (index > 1){
      index--;
      ptr2 = ptr1;
      ptr1 = ptr1->next;
    }
    ptr2->next = ptr1->next;
    delete ptr1;
  }
  size--;
  return (*this);
}

template <typename T>
List<T> &List<T>::insertBegining(const T &n, const int &w){
  node<T> * newNode = new node<T>(n, w, head);
  head = newNode;
  size++;
  return (*this);
}

template <typename T>
List<T> &List<T>::concatenate(List<T> &l){
  node<T> * ptr = head;
  if (ptr == NULL){
    head = l.head;
    size = l.size;
    return l;
  }
  else if (l.head == NULL)
    return (*this);
  else {
    while (ptr->next != NULL)
      ptr = ptr->next;
    ptr->next = l.head;
    size += l.size;
  }
  return (*this);
};

template <typename T>
int List<T>::search(const T &value){
  node<T> * ptr = head;
  int index = 0;
  for (int i = 1; i <= size; i++){
    if (ptr->data == value){
      index = i;
      return index;
    }
    else
      ptr = ptr->next;
  }
  return index;
}
