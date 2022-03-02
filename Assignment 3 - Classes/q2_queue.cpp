#include <iostream>
using namespace std;

template <typename T>
class queue {
  private:
    T * data;
    int front, rear;
    int size;

  public:
    queue(const int);
    queue &push(const T); // Enqueue
    queue &pop();         // Dequeue
    bool isEmpty();
    bool isFull();
    void display();
    ~queue();
};

template <typename T>
queue<T>::queue(const int s){
  front = -1;
  rear = -1;
  size = s;
  data = new T[size];
}

template <typename T>
queue<T>::~queue(){
  delete[] data;
}

template <typename T>
bool queue<T>::isEmpty(){
  return rear == -1;
}

template <typename T>
bool queue<T>::isFull(){
  return rear == size-1;
}

template <typename T>
queue<T> &queue<T>::push(const T n){
  if (this->isFull())
    cout << "Error: Overflow.\n";
  else {
    if (this -> front == -1)
      front = 0;
    size++;
    data[++rear] = n;
  }
  return (*this);
}

template <typename T>
queue<T> &queue<T>::pop(){
  if (this->isEmpty())
    cout << "Error: Underflow.\n";
  else {
    T value = data[front];
    if (front == rear){
      front = -1;
      rear = -1;
      size = 0;
    } else {
      front++;
      size--;
    }
    cout << ">> " << value << " was popped.\n";
  }
  return (*this);
}

template <typename T>
void queue<T>::display(){
  cout << ">> Queue: ";
  for (int i = front; i <= rear; i++)
    cout << data[i] << " ";
  cout << "\n";
}


int main(void){

  cout << "\nEnter the size of queue: ";
  int size; cin >> size;
  queue<int> q(size);

  cout << "\n";
  cout << "1: Push/Enqueue\n";
  cout << "2: Push multiple values\n";
  cout << "3: Pop/Dequeue\n";
  cout << "4: Is Empty?\n";
  cout << "5: Is Full?\n";
  cout << "6: Display Queue\n";
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
        q.push(value);
        break;

      case 2:
        cout << "\nEnter no. of values: ";
        cin >> d;
        if (d > size)
          cout << "Error: No. of elements exceed the queue size.";
        else {
          cout << "Enter #min and #max range of values: ";
          int rangeMin, rangeMax;
          cin >> rangeMin >> rangeMax;
          while (d--){
            int x = (rand() % (rangeMax-rangeMin)) + rangeMin;
            q.push(x);
          }
        }
        q.display();
        break;

      case 3:
        q.pop();
        break;

      case 4:
        q.isEmpty() ? cout << "True\n" : cout << "False\n";
        break;

      case 5:
        q.isFull() ? cout << "True\n" : cout << "False\n";
        break;

      case 6:
        q.display();
        break;

      default:
        wantToExit = 1;
        break;
    }
  }

  return 0;
}