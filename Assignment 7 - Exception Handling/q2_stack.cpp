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
  ~stack();
  stack& push(const T);
  stack& pushMultiple();
  stack& pop();
  T peek();
  bool isEmpty();
  bool isFull();
  void display();
  
  template <typename U>
  friend ostream& operator<< (ostream&, stack<U>&);
  template <typename U>
  friend istream& operator>> (istream&, stack<U>&);
};

template <typename T>
stack<T>::stack(const int s){
  size = s;
  data = new T[size];
  top = -1;
}

template <typename T>
stack<T> &stack<T>::push(const T n){
  if (top >= size-1)
    throw -1;
  data[++top] = n;
  cout << ">> " << T(n) << " has been pushed on top.\n";
  return (*this);
}

template <typename T>
stack<T> &stack<T>::pushMultiple(){
  cout << "\nEnter no. of values: ";
  int d; cin >> d;
  if (d > size)
    cout << "Error: No. of elements exceed the stack size.";
  else {
    cout << "Enter #min and #max range of values: ";
    T rangeMin, rangeMax;
    cin >> rangeMin >> rangeMax;
    while (d--){
      T x = (rand() % (int(rangeMax)-int(rangeMin))) + int(rangeMin);
      try {
        this->push(T(x));
      } catch(int){
        cout << "\nError: (Overflow) Stack is Full\n";
      }
    }
  }
  return (*this);
}


template <typename T>
istream& operator>> (istream& in, stack<T>& s){
  cout << "Enter #value to be inserted: ";
  T value; in >> value;
  try {
    s.push(value);
  } catch (int){
    cout << "\nError: (Overflow) Stack is Full\n";
  }
  return in;
}

template <typename T>
stack<T> &stack<T>::pop(){
  if (top <= -1)
    throw -1;
  T temp = data[top];
  data[top--] = T(NULL);
  cout << ">> " << temp << " was popped.\n";
  return (*this);
}

template <typename T>
T stack<T>::peek(){
  if (isEmpty())
    throw -1;
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
ostream& operator<< (ostream& out, stack<T>& s){
  out << ">> Stack: ";
  for (int i = 0; i <= s.top; i++)
    out << s.data[i] << " ";
  out << "\n";
  return out;
}

template <typename T>
stack<T>::~stack(){
  delete[] data;
}

/* int main(void){

  stack<char> s(100);

  s.push('A');
  s.push('C');
  s.push('B');
  s.push('*');
  s.push('/');

  // s.display();
  cout << s;

  return 0;
} */



int main(void){

  cout << "\nEnter the size of stack: ";
  int size; cin >> size;
  stack<char> s(size);

  cout << "\n";
  cout << "1: Push\n";
  cout << "2: Push multiple random values\n";
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
        cin >> s;
        break;

      case 2:
        s.pushMultiple();
        break;

      case 3:
        try {
          s.pop();
        } catch (int){
          cout << "\nError: (Underflow) Stack is empty.\n";
        }
        break;

      case 4:
        try {
          cout << "\n>> Top of stack is: " << s.peek() << "\n";
        } catch (int){
          cout << "empty.\n";
        }
        break;

      case 5:
        s.isEmpty() ? cout << "True\n" : cout << "False\n";
        break;

      case 6:
        s.isFull() ? cout << "True\n" : cout << "False\n";
        break;

      case 7:
        cout << s;
        break;

      default:
        wantToExit = 1;
        break;
    }
  }

  return 0;
}