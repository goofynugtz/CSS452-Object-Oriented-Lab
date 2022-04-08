#include <iostream>
using namespace std;

template <typename T>
struct node {
public:
  T data;
  node * next;
  node(T, node * = NULL);
};

template <typename T>
node<T>::node(T n, node * next){
  this->data = n;
  this->next = next;
};

template <typename T>
class List {
private:
  node<T> * head ;
  int size;
public:
  List();
  node<T> * getHead();
  List& insertNode(const T&);
  void pushBack();                  // Interface for insertNode
  void pushBackMultiple();          // Interface for insertNode
  List& insertBegining(const T&);
  void pushFront();                 // Interface for insertBegining
  List& deleteNode(const int&);
  void pop();                       // Interface for deleteNode
  List& concatenate(List<T>&);
  List& operator=(const List<T>&);
  int search(const T&);
  void search();                    // Interface for search
  
  template <typename U>
  friend ostream& operator<<(ostream&, const List<U>&);
  ~List();
};

template <typename T>
List<T>::List(){
  head = NULL; size = 0;
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
List<T>& List<T>::insertNode(const T& n){
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
void List<T>::pushBack(){
  cout << "Enter #value to be inserted: ";
  T value; cin >> value;
  this->insertNode(value);
}

template <typename T>
void List<T>::pushBackMultiple(){
  T rangeMin, rangeMax;
  cout << "\nEnter no. of values: ";
  int d; cin >> d;
  cout << "Enter #min and #max range of values: ";
  cin >> rangeMin >> rangeMax;
  while (d--){
    T value = (rand() % (int(rangeMax)-int(rangeMin))) + int(rangeMin);
    this->insertNode(T(value));
  }
}

template <typename T>
List<T>& List<T>::insertBegining(const T& n){
  node<T> * newNode = new node<T>(n, head);
  head = newNode; size++;
  return (*this);
}

template <typename T>
void List<T>::pushFront(){
  cout << "Enter #value to be inserted: ";
  T value; cin >> value;
  this->insertBegining(value);
}

template <typename T>
List<T>& List<T>::deleteNode(const int& i){
  int index = i;
  if (index < 1)
    throw -1;
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
void List<T>::pop(){
  cout << "Enter #index to be deleted: ";
  int index; cin >> index;
  try {
    this->deleteNode(index);
  } catch(int){
    cout << "Error: Index must be greater than 0.\n";
  }
}

template <typename T>
List<T>& List<T>::concatenate(List<T>& l){
  static List<T> full;
  full.~List();
  full = *this;
  node<T> * ptr = l.head;
  while (ptr != NULL){
    full.insertNode(ptr->data);
    ptr = ptr->next;
  }
  return full;
};

template <typename T>
List<T>& List<T>::operator=(const List<T>& l){
  this->~List();
  node<T> * ptr = l.head;
  while (ptr != NULL){
    this->insertNode(ptr->data);
    ptr = ptr->next;
  }
  return *this;
}

template <typename T>
int List<T>::search(const T& value){
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

template <typename T>
void List<T>::search(){
  cout << "Enter #value to search: ";
  T value; cin >> value;
  int index = this->search(value);
  if (index == 0)
    cout << "Value not found in List_1.\n";
  else 
    cout << "Value found at index " << index << ".\n";
}

template <typename T>
ostream &operator<< (ostream& out, const List<T>& l){
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
  List<char> l1;
  List<char> l2;
  cout << "\n";
  cout << "1: Insert at end\n";
  cout << "2: Insert at Begining\n";
  cout << "3: Push multiple values\n";
  cout << "4: Delete\n";
  cout << "5: Concatenate\n";
  cout << "6: Search #value\n";
  cout << "7: Display List\n";
  cout << "0: Exit Program\n";
  bool wantToExit = 0;
  while (!wantToExit){
    cout << "\nChoose Option: ";
    int n; cin >> n;
    int i, value, d;
    int rangeMin, rangeMax, index;
    switch (n){
      case 1:
        l1.pushBack();
        break;
      case 2:
        l1.pushFront();
        break;
      case 3:
        l1.pushBackMultiple();
        break;
      case 4:
        l1.pop();
        break;
      case 5:
        l2.pushBackMultiple();
        cout << l2;
        l1 = l1.concatenate(l2);
        cout << "Updated List_1:: ";
        cout << l1 << "\n";
        break;
      case 6:
        l1.search();
        break;
      case 7:
        cout << l1;
        break;
      default:
        wantToExit = 1;
        break;
    }
  }
  return 0;
} 