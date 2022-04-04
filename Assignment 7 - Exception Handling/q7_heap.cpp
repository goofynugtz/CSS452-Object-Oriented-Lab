#include <iostream>
#include <math.h>
#include <iomanip>
// #include <time.h>
using namespace std;

// Max Heap
template <typename T>
class heap {
private:
  T * data;
  int maxsize;
  int current;
  void heapify(int);
public:
  heap (const int&);
  ~heap();
  template <typename U>
  friend ostream& operator<< (ostream&, heap<U>&);
  template <typename U>
  friend istream& operator>> (istream&, heap<U>&);
  T getMax();
  T getMin();
  int findIndexOf(const T&);
  heap& insertNode(const T&);
  heap& insertMultiple();
  heap& removeNode(const int&);
  void removeMax();
  void removeMin();
  heap& replace(const int&, const T&);
  void printArray();
};

template <typename T>
void heap<T>::heapify(int i){
  int size = current;
  int parent = i;
  int left = 2*i+1;
  int right = 2*i+2;
  if (left < size && data[left] > data[parent])
    parent = left;
  if (right < size && data[right] > data[parent])
    parent = right;
  if (parent != i){
    swap(data[i], data[parent]);
    heapify(parent);
  }
}

template <typename T>
heap<T>::heap(const int& n){
  data = new T[n];
  for (int i = 0; i < n; i++)
    data[i] = 0;
  maxsize = n;
  current = 0;
};

template <typename T>
heap<T>::~heap(){
  delete[] data;
};

template <typename T>
ostream & operator<< (ostream& out, heap<T>& h){
  // system("clear");
  int n = 0; int level = 0;
  for (level = 0; level < h.maxsize; level++){
    n = pow(2, level);
    if (n >= h.current)
      break;
  }
  out << "\n";
  int node = 0;
  for (int l = 0; l < level; l++){
    out << setw(pow(2, level-l)+1) << h.data[node++];
    for (int i = 1; i < pow(2, l) && node < h.current; i++)
      out << setw(pow(2,level-l+1)) << h.data[node++];
    out << "\n";
  }
  return out;
};

template <typename T>
istream& operator>> (istream& in, heap<T>& h){
  cout << "\nEnter #value: ";
  T temp; in >> temp;
  try {
    h.insertNode(temp);
  } catch(int){
    cout << "Error: Heap is full.\n";
  }
  return in;
}

template <typename T>
T heap<T>::getMax(){
  return data[0];
};

template <typename T>
T heap<T>::getMin(){
  T minimum = data[0];
  for (int i = 1; i < current; i++)
    minimum = min(minimum, data[i]);
  return minimum;
};

template <typename T>
int heap<T>::findIndexOf(const T& n){
  int index = 0;
  for (index; index < current; index++)
    if (data[index] == n)
      break;
  return index;
}

template <typename T>
heap<T>& heap<T>::insertNode(const T& value){
  if (current > maxsize-1)
    throw -1;
  data[current++] = value;
  cout << ">> " << T(value) << " has been inserted.\n";
  for (int i = (current/2) - 1; i >= 0; i--)
    heapify(i);
  return (*this);
};

template <typename T>
heap<T>& heap<T>::insertMultiple(){
  cout << "\nEnter no. of values: ";
  int d; cin >> d;
  if (d > maxsize - current)
    cout << "Error: No. of elements exceed the free heap size.";
  else {
    cout << "Enter #min and #max range of values: ";
    T rangeMin, rangeMax;
    cin >> rangeMin >> rangeMax;
    while (d--){
      T x = (rand() % (int(rangeMax) - int(rangeMin))) + int(rangeMin);
      try {
        this->insertNode(T(x));
      } catch(int) {
        cout << "Error: Heap is full.\n";
      }
    }
  }
  return (*this);
};

template <typename T>
heap<T>& heap<T>::removeNode(const int& index){
  // system("clear");
  if (current == 0)
    throw -1;
  data[index] = data[--current];
  cout << ">> Node at index " << index << " has been removed.\n";
  for (int i = (current/2) - 1; i >= 0; i--)
    heapify(i);
  return (*this);
}

template <typename T>
void heap<T>::removeMax(){
  removeNode(0);
}

template <typename T>
void heap<T>::removeMin(){
  T minimum = getMin();
  int index = findIndexOf(minimum);
  try {
    removeNode(index);
  } catch(int){
    cout << "Error: Empty heap.\n";
  }
}

template <typename T>
heap<T>& heap<T>::replace(const int& indexToRemove,const T& value){
  try {
    removeNode(indexToRemove);
    insertNode(value);
  } catch(int){

  }
  return (*this);
}

template <typename T>
void heap<T>::printArray(){
  // system("clear");
  cout << "\nHeap: ";
  for (int i = 0; i < current; i++)
    cout << data[i] << " ";
  cout << "\n";
};

int main (void){
  
  cout << "\nEnter maximum #size of heap: ";
  int n; cin >> n;

  heap<int> h(n);

  bool wantToExit = false;
  cout << "\n 0. Exit";
  cout << "\n 1. Insert";
  cout << "\n 2. Insert multiple random values";
  cout << "\n 3. Get Maximum Value";
  cout << "\n 4. Get Minimum Value";
  cout << "\n 5. Delete an index";
  cout << "\n 6. Delete Minimum Value";
  cout << "\n 7. Delete Maximum Value";
  cout << "\n 8. Replace index";
  cout << "\n 9. Display Heap (Tree)";
  cout << "\n10. Display Heap (Array)\n";

  while (!wantToExit){
    cout << "\nChoose Option >> ";
    int choice; cin >> choice;
    int x; int d;
    int rangeMin, rangeMax;
    srand(time(NULL));

    switch (choice){
      case 0:
        wantToExit = true;
        break;

      case 1:
        cin >> h;
        break;

      case 2:
        h.insertMultiple();
        break;

      case 3:
        cout << ">> Maximum in heap: " << h.getMax() << "\n";
        break;

      case 4:
        cout << ">> Minimum in heap: " << h.getMin() << "\n";
        break;

      case 5:
        cout << "\nIndex to be deleted: ";
        cin >> x;
        try {
          h.removeNode(x);
        } catch (int) {
          cout << "Error: Empty heap.\n";
        }
        break;

      case 6:
        h.removeMin();
        break;

      case 7:
        h.removeMax();
        break;

      case 8:
        cout << "Enter #index to be replaced and with #value: ";
        cin >> d >> x;
        h.replace(d, x);
        break;

      case 9:
        cout << h;
        break;

      case 10:
        h.printArray();
        break;

      default:
        cout << "Error: Please enter valid option.\n";
        break;
    }
  }
  return 0;
}
