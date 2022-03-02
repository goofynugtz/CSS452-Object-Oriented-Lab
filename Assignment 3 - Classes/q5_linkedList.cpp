#include <iostream>
using namespace std;

template <typename T>
struct node {
  public:
    T data;
    node * next;
    node(T n){
      data = n;
      next = NULL;
    };
};

template <typename T>
class List {
  private:
    node<T> * head ;
    int size;

  public:
    List();
    ~List();
    node<T> * getHead();
    void insertNode(const T&);
    void deleteNode(int&);
    void insertBegining(const T&);
    void concatenate(List<T>&);
    int search(const T&);
    // friend ostream &operator<< <T>(ostream&, List<T> &);
    void display();
    
};

template <typename T>
List<T>::List(){
  head = NULL;
  size = 0;
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
void List<T>::insertNode(const T &n){
  node<T> * newNode = new node<T>(n);
  if (head == NULL)
    head = newNode;
  else {
    node<T> * temp = head;
    while (temp->next != NULL)    
      temp = temp->next;
    temp->next = newNode;
  }
  // return *this;
};

template <typename T>
void List<T>::deleteNode(int &index){
  if (head == NULL) {
    cout << "List empty." << endl;
    return;
  }
  if (index >= size) {
    cout << "Error: Index out of range.\n";
    return;
  }
  node<T> * ptr1 = head;
  node<T> * ptr2 = NULL;
  if (index == 1) { 
    head = head->next;
    delete ptr1;
    return;
  }
  while (--index > 1){
    ptr2 = ptr1;
    ptr1 = ptr1->next;
  }
  ptr2->next = ptr1->next;
  delete ptr1;
  return;
}


template <typename T>
void List<T>::insertBegining(const T &n){
  node<T> * newNode = new node<T>(n);
  newNode->next = head;
  head = newNode;
}

template <typename T>
void List<T>::concatenate(List<T> &l){
  node<T> * ptr = head;
  if (ptr == NULL)
    head = l.head;
    // return l;
  else if (l.head == NULL)
    return;
    // return (*this);
  else {
    while (ptr != NULL){
      ptr = ptr->next;
    }
    l.display();
    cout << l.head;
    ptr->next = l.head;
    cout << "here\n";
  }
  // return (*this);
};

template <typename T>
int List<T>::search(const T &value){
  node<T> * ptr = head;
  int index = -1;
  while (ptr != NULL){
    index++;
    if (ptr->data == value)
      break;
    ptr = ptr->next;
  }
  return index;
}

/* template <typename T>
ostream & operator<< (ostream &out, List<T> &l){
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
}; */

template <typename T>
void List<T>::display(){
  node<T> * ptr = head;
  if (ptr == NULL)
    cout << "Empty List.\n";
  else {
    cout << "List: ";
    while (ptr != NULL){
      cout << ptr->data << " -> ";
      ptr = ptr->next;
    }
    cout << "\n";
  }
}




int main(void){

  List<int> l1;
  List<int> l2;

  cout << "\n";
  cout << "1: Insert\n";
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
        cout << "Enter #value to be inserted: ";
        cin >> value;
        l1.insertNode(value);
        break;

      case 2:
        cout << "Enter #value to be inserted: ";
        cin >> value;
        l1.insertBegining(value);
        break;

      case 3:
        cout << "\nEnter no. of values: ";
        cin >> d;
        cout << "Enter #min and #max range of values: ";
        cin >> rangeMin >> rangeMax;
        while (d--){
          value = (rand() % (rangeMax-rangeMin)) + rangeMin;
          l1.insertNode(value);
        }
        l1.display();
        break;

      case 4:
        cout << "Enter #index to be deleted: ";
        cin >> value;
        l1.deleteNode(value);
        break;

      case 5:
        cout << "\nEnter no. of values in List_2: ";
        cin >> d;
        cout << "Enter #min and #max range of values: ";
        cin >> rangeMin >> rangeMax;
        while (d--){
          value = (rand() % (rangeMax-rangeMin)) + rangeMin;
          l2.insertNode(value);
        }
        l2.display();
        l1.concatenate(l2);
        cout << "Updated List_1:: ";
        l1.display();
        break;

      case 6:
        cout << "Enter #value to search: ";
        cin >> value;
        index = l1.search(value);
        if (index == -1)
          cout << "Value not found in List_1.\n";
        else 
          cout << "Value found at index " << index << ".\n";
        break;

      case 7:
        l1.display();
        break;

      default:
        wantToExit = 1;
        break;
    }
  }

  return 0;
}