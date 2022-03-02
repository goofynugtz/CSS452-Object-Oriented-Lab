#include "LinkedList.h"
#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
class Hash {
  private:
    List<T> * table;
    int tableSize;
    int function(const int &);

  public:
    Hash(const int & = 10);
    ~Hash();
    List<T> * getTable();
    Hash &insertValue(const T &);
    Hash &deleteValue(const T &);
    void search(const T &);
    void showTableDistribution();
    void display();
};

template <typename T>
int Hash<T>::function(const int &x){
  // Below function would take the ones place as index of hash table.
  return x % tableSize;
  // Below function would take the tens digit as index of hash table.
  // return (x / tableSize) % tableSize ; 
}

template <typename T>
Hash<T>::Hash(const int &n){
  table = new List<T>[n];
  tableSize = n;
}

template <typename T>
Hash<T>::~Hash(){
  delete []table;
}

template <typename T>
List<T> * Hash<T>::getTable(){
  return table;
}

template <typename T>
Hash<T> &Hash<T>::insertValue(const T &x){
  int n = function(x);
  table[n].insertBegining(x);
  return (*this);
}

template <typename T>
Hash<T> &Hash<T>::deleteValue(const T &x){
  int n = function(x);
  if (table[n].search(x)) // If it returns a non-zero index then
    table[n].deleteNode(table[n].search(x));
  else 
    cout << "Not found in Table\n";
  return (*this);
}

template <typename T>
void Hash<T>::search(const T &x){
  int n = function(x);
  if (table[n].search(x))
    cout << ">> " << x << " is found at index: " << n << " in HashTable.\n";
  else
    cout << ">> Value not found.\n";
}

template <typename T>
void Hash<T>::display(){
  cout << "\n";
  for (int i = 0; i < tableSize; i++)
    cout << char(192) << char(196) << "[" << i << "] " << table[i] << char(179) << "\n";
}

template <typename T>
void Hash<T>::showTableDistribution(){
  cout << ">> Table Distribution\n";
  cout << "Ending at\n Ones   Distribution\n";
  for (int i = 0; i < tableSize; i++){
    cout << ">> " << fixed << left << setfill(' ') << setw(5) << i; 
    cout << right << setw(12) << setfill('.') << table[i].getSize() << "\n";
  }
  cout << "\n";
}

int main(void){
  Hash<int> h1;
  cout << "\n";
  h1.insertValue(10);
  h1.insertValue(22);
  h1.display();
  h1.search(10);
  h1.search(22);
  h1.search(23);
  cout << "\n\n";
  // h1.showTableDistribution();
  h1.deleteValue(22);
  // Inserting 100 random numbers
  for (int i = 0; i < 100; i++)
    h1.insertValue(rand() % 100);
  
  h1.display();
  cout << "\n\n";
  h1.showTableDistribution();
  cout << "\n\n";
  return 0;
}