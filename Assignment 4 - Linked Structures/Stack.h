#include <iostream>
using namespace std;

template <typename T>
class stack {
  private:
    T * data;
    int top;
    int size;

  public:
    stack(const int = 100);
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
