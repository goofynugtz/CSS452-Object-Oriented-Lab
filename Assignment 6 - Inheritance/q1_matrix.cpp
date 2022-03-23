#include <iostream>
#include <iomanip>
using namespace std;

class matrix {
protected:
  int order = 3;
  int ** array;
public:
  matrix(const matrix&);
  matrix();
  void show();
  friend istream& operator>> (istream &in, matrix &m){
    cout << "Enter the values:\n";
    for (int i = 0; i < m.order; i++)
      for (int j = 0; j < m.order; j++){
        int n; in >> n;
        m.array[i][j] = n;
      }
    return in;
  };
};

matrix::matrix(const matrix& m){
  for (int i = 0; i < m.order; i++)
    for (int j = 0; j < m.order; j++)
      this->array[i][j] = m.array[i][j];
}

matrix::matrix(){
  this->order = 3;
  array = new int *[order];
  for (int i = 0; i < order; i++)
    this->array[i] = new int[order];
}

void matrix::show(){
  cout << "\n";
  for (int i = 0; i < this->order; i++){
    for (int j = 0; j < this->order; j++)
      cout << array[i][j] << " ";
    cout << "\n";
  }
  cout << "\n";
}

class matrixA : public matrix {
public:
  void show(){
    cout << "\n";
    for (int i = 0; i < this->order; i++){
      for (int j = 0; j < this->order; j++)
        cout << array[i][j] << " ";
      cout << "\n";
    }
    cout << "\n";
  };
};

class matrixB : public matrixA {
public:
  void show(){
    cout << "\n";
    for (int i = 0; i < this->order; i++){
      for (int j = 0; j < this->order; j++)
        cout << array[i][j] << " ";
      cout << "\n";
    }
    cout << "\n";
  };
};


int main(void){

  matrix m;
  cin >> m;
  m.show();
  
  matrixA a;
  cin >> a;
  a.show();
  
  matrixB b;
  cin >> b;
  b.show();

  return 0;
}
