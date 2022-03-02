#include <iostream>
#include <math.h>
#include <iomanip>
#include <time.h>
using namespace std;

// Max Heap
class heap {
  private:
    int * data;
    int maxsize;
    int current;
    void heapify(int);

  public:
    // 1. initialize
    heap (const int);
    ~heap();
    friend ostream &operator<< (ostream &, heap &);
    // 2. find-max/find-min
    int getMax();
    int getMin(int);
    int findIndexOf(int);
    // 3. insert
    void insertNode(const int);
    void removeNode(int);
    // 4. delete-max/delete-min
    void removeMax();
    void removeMin();
    // 5. replace
    void replace(int,int);
    void printArray();
};

void heap::heapify(int i){
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

heap::heap (const int n){
  data = new int[n];
  for (int i = 0; i < n; i++)
    data[i] = 0;
  maxsize = n;
  current = 0;
};

heap::~heap(){
  delete[] data;
};

ostream & operator<< (ostream &out, heap &h){
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

int heap::getMax(){
  return data[0];
};


int heap::getMin(int n){
  int minimum = data[0];
  for (int i = 1; i < current; i++)
    minimum = min(minimum, data[i]);
  return minimum;
};

int heap::findIndexOf(int n){
  int index = 0;
  for (index; index < current; index++)
    if (data[index] == n)
      break;
  return index;
}

void heap::insertNode(const int value){
  data[current++] = value;
  cout << ">> " << value << " has been inserted.\n";
  for (int i = (current/2) - 1; i >= 0; i--)
    heapify(i);
  // return (*this);
};

void heap::removeNode(int index){
  // system("clear");
  data[index] = data[--current];
  cout << ">> Node at index " << index << " has been removed.\n";
  for (int i = (current/2) - 1; i >= 0; i--)
    heapify(i);
  // return (*this);
}

void heap::removeMax(){
  removeNode(0);
}

void heap::removeMin(){
  int minimum = getMin(0);
  int index = findIndexOf(minimum);
  removeNode(index);
}

void heap::replace(int indexToRemove, int value){
  removeNode(indexToRemove);
  insertNode(value);
}


void heap::printArray(){
  // system("clear");
  cout << "\nHeap: ";
  for (int i = 0; i < current; i++)
    cout << data[i] << " ";
  cout << "\n";
};


int main (void){
  
  cout << "\nEnter maximum #size of heap: ";
  int n; cin >> n;

  heap h(n);

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
        cout << "\nEnter #value: ";
        cin >> x;
        h.insertNode(x);
        break;

      case 2:
        cout << "\nEnter no. of values: ";
        cin >> d;
        if (d > n)
          cout << "Error: No. of elements exceed the heap size.";
        else {
          cout << "Enter #min and #max range of values: ";
          cin >> rangeMin >> rangeMax;
          while (d--){
            x = (rand() % (rangeMax-rangeMin)) + rangeMin;
            h.insertNode(x);
          }
        }
        break;

      case 3:
        cout << ">> Maximum in heap: " << h.getMax() << "\n";
        break;

      case 4:
        cout << ">> Minimum in heap: " << h.getMin(0) << "\n";
        break;

      case 5:
        cout << "\nIndex to be deleted: ";
        cin >> x;
        h.removeNode(x);
        break;

      case 6:
        h.removeMin();
        break;

      case 7:
        h.removeMax();
        break;

      case 8:
        cout << "Enter #index and #value to insert: ";
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
