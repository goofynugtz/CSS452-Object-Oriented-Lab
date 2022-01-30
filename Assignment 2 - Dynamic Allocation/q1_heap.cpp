#include <iostream>
#include <math.h>
#include <iomanip>
#include <time.h>
using namespace std;

class heap {
  private:

    int * data;
    int size;
    int current;

    void heapify(int i){
      int size = current;
      int largest = i;
      int l = 2 * i + 1;
      int r = 2 * i + 2;
      if (l < size && data[l] > data[largest])
        largest = l;
      if (r < size && data[r] > data[largest])
        largest = r;

      if (largest != i){
        swap(data[i], data[largest]);
        heapify(largest);
      }
    }

  public:

    heap (int n){
      data = new int[n];
      for (int i = 0; i < n; i++)
        data[i] = 0;
      size = n;
      current = 0;
    };


    friend ostream & operator<< (ostream &out, heap &h){
      system("clear");
      int n = 0; int level = 0;
      for (level = 0; level < h.size; level++){
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


    void insertNode(int value){
      data[current++] = value;
      cout << ">> " << value << " has been inserted.\n";
      for (int i = (current/2) - 1; i >= 0; i--){
        heapify(i);
      }
    };

    void removeNode(int index){
      system("clear");
      data[index] = data[--current];

      for (int i = (current/2) - 1; i >= 0; i--){
        heapify(i);
      }
    }

    void printArray(){
      system("clear");
      cout << "\nHeap: ";
      for (int i = 0; i < current; i++)
        cout << data[i] << " ";
      cout << "\n";
    };

};


int main (void){
  
  cout << "\nEnter maximum #size of heap: ";
  int n; cin >> n;

  heap h(n);

  bool wantToExit = false;

  while (!wantToExit){
    cout << "\n1. Insert";
    cout << "\n2. Insert multiple random values";
    cout << "\n3. Delete";
    cout << "\n4. Display Heap (Tree)";
    cout << "\n5. Display Heap (Array)";
    cout << "\n0. Exit";
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
        cout << "\nIndex to be deleted: ";
        cin >> x;
        h.removeNode(x);
        break;

      case 4:
        cout << h;
        break;

      case 5:
        h.printArray();
        break;

      default:
        cout << "Error: Please enter valid option.\n";
        break;
    }
  }
  
  return 0;
}
