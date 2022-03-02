#include <iostream>
using namespace std;

template <typename T>
class stack {
  private:
    T * data;
    int top;
    int size;

  public:
    stack(const int);
    stack &push(const T);
    stack &pop();
    T peek();
    bool isEmpty();
    bool isFull();
    void display();
    ~stack();
};

template <typename T>
stack<T>::stack(const int s){
  size = s;
  data = new T[size];
  top = -1;
}

template <typename T>
stack<T> &stack<T>::push(const T n){
  if (top < size-1){
    data[++top] = n;
  }
  else 
    cout << "\nError: (Overflow) Stack is Full\n";
  return (*this);
}

template <typename T>
stack<T> &stack<T>::pop(){
  if (top > -1){
    T temp = data[top];
    data[top--] = T(NULL);
    cout << ">> " << temp << " was popped.\n";
  }
  else 
    cout << "\nError: (Underflow) Stack is empty.\n";
  return (*this);
}

template <typename T>
T stack<T>::peek(){
  if (isEmpty()){
    cout << "Stack is Empty.\n";
    return T(NULL);
  }
  return data[top];
}

template <typename T>
bool stack<T>::isEmpty(){
  return top == -1;
}

template <typename T>
bool stack<T>::isFull(){
  return top == size-1;
}

template <typename T>
void stack<T>::display(){
  cout << ">> Stack: ";
  for (int i = 0; i <= top; i++)
    cout << data[i] << " ";
  cout << "\n";
}

template <typename T>
stack<T>::~stack(){
  delete[] data;
}


int main(void){

  cout << "\nEnter the size of stack: ";
  int size; cin >> size;
  stack<int> s(size);

  cout << "\n";
  cout << "1: Push\n";
  cout << "2: Push multiple values\n";
  cout << "3: Pop\n";
  cout << "4: Peek [Top of stack]\n";
  cout << "5: Is Empty?\n";
  cout << "6: Is Full?\n";
  cout << "7: Display Stack\n";
  cout << "0: Exit Program\n";

  bool wantToExit = 0;

  while (!wantToExit){
    cout << "\nChoose Option: ";
    int n; cin >> n;

    int i, value, d;

    switch (n){
      
      case 1:
        cout << "Enter #value to be inserted: ";
        cin >> value;
        s.push(value);
        break;

      case 2:
        cout << "\nEnter no. of values: ";
        cin >> d;
        if (d > size)
          cout << "Error: No. of elements exceed the stack size.";
        else {
          cout << "Enter #min and #max range of values: ";
          int rangeMin, rangeMax;
          cin >> rangeMin >> rangeMax;
          while (d--){
            int x = (rand() % (rangeMax-rangeMin)) + rangeMin;
            s.push(x);
          }
        }
        s.display();
        break;

      case 3:
        s.pop();
        break;

      case 4:
        cout << "\n>> Top of stack is: " << s.peek() << "\n";
        break;

      case 5:
        s.isEmpty() ? cout << "True\n" : cout << "False\n";
        break;

      case 6:
        s.isFull() ? cout << "True\n" : cout << "False\n";
        break;

      case 7:
        s.display();
        break;

      default:
        wantToExit = 1;
        break;
    }
  }

  return 0;
}