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
    ~List();
    node<T> * getHead();
    List &insertNode(const T&);
    List &deleteNode(const int&);
    List &insertBegining(const T&);
    List &concatenate(List<T>&);
    int search(const T&);
    friend ostream &operator<< (ostream &out, const List<T> &l){
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
List<T> &List<T>::insertBegining(const T &n){
  node<T> * newNode = new node<T>(n, head);
  head = newNode; size++;
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
        cout << l1;
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
        cout << l2;
        l1.concatenate(l2);
        cout << "Updated List_1:: ";
        cout << l1;
        break;

      case 6:
        cout << "Enter #value to search: ";
        cin >> value;
        index = l1.search(value);
        if (index == 0)
          cout << "Value not found in List_1.\n";
        else 
          cout << "Value found at index " << index << ".\n";
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