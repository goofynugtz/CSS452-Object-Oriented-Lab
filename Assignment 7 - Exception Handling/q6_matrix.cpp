#include <iostream>
#include <iomanip>
using namespace std;

template <typename U>
class row {
public:
  U * row_address;
  int row_size;
  row(U ** f = NULL){
    if(f != NULL)
      row_address = *f;
    else
      row_address = NULL;
  }
  U& operator[](int index){
    return this->row_address[index];
  }
};

template <typename U>
class matrix {
private:
  int rows, columns;
  U ** array;

public:
  matrix(const matrix&);
  matrix(const int&);
  matrix(const int&, const int&);
  matrix& operator+(const matrix&);
  matrix& operator+(const U&);
  matrix& operator-(const matrix&);
  matrix& operator-(const U&);
  matrix& operator*(const matrix&);
  matrix& operator*(const U&);
  matrix& operator!(void);
  matrix& getCofactor(const int&, const int&);
  matrix& adjoint();
  int determinant();
  matrix& T();

  // template <typename V>
  row<U>& operator[](const int&);
  bool operator==(const matrix&);
  
  template <typename V>
  friend istream & operator>> (istream&, matrix<V>&);
  template <typename V>
  friend ostream & operator<< (ostream&, matrix<V>&);
};

template <typename U>
matrix<U>::matrix(const matrix<U>& m){
  this->rows = m.rows;
  this->columns = m.columns;
  this->array = new U*[this->rows];
  for (int i = 0; i < this->columns; i++)
    array[i] = new U[this->columns];
  for (int i = 0; i < m.rows; i++)
    for (int j = 0; j < m.columns; j++)
      this->array[i][j] = m.array[i][j];
}

template <typename U>
matrix<U>::matrix(const int& order){
  rows = order;
  columns = order;
  array = new U*[order];
  for (int i = 0; i < order; i++)
    array[i] = new U[order];
}

template <typename U>
matrix<U>::matrix(const int& row, const int& column){
  this->rows = row;
  this->columns = column;
  array = new U*[rows];
  for (int i = 0; i < rows; i++)
    array[i] = new U[columns];
}

template <typename U>
matrix<U>& matrix<U>::operator+(const matrix& m){
  if (this->rows != m.rows || this->columns != m.columns)
    throw -1;
  static matrix a(*this);
  for (int i = 0; i < m.rows; i++)
    for (int j = 0; j < m.columns; j++)
      a.array[i][j] += m.array[i][j];
  return a;
}

template <typename U>
matrix<U>& matrix<U>::operator+(const U& n){
  static matrix a(*this);
  for (int i = 0; i < this->rows; i++)
    for (int j = 0; j < this->columns; j++)
      a.array[i][j] += n;
  return a;
}

template <typename T>
matrix<T>& matrix<T>::operator-(const matrix& m){
  if (this->rows != m.rows || this->columns != m.columns)
    throw -1;
  static matrix a(m);
  for (int i = 0; i < m.rows; i++)
    for (int j = 0; j < m.columns; j++)
      a.array[i][j] -= m.array[i][j];
  return a;
}

template <typename U>
matrix<U>& matrix<U>::operator-(const U& n){
  static matrix a(*this);
  for (int i = 0; i < this->rows; i++)
    for (int j = 0; j < this->columns; j++)
      a.array[i][j] -= n;
  return a;
}

template <typename T>
matrix<T>& matrix<T>::operator*(const matrix& m){
  if (columns != m.rows){
    cout << "Error: Multiplication is not defined.\n";
    cout << "c1 != r2.\n";
    throw -1;
  }
  static matrix result(rows, m.columns);
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < m.columns; j++){
      result.array[i][j] = 0;
      for (int k = 0; k < columns; k++)
        result.array[i][j] += array[i][k] * m.array[k][j];
    }
  return result;
}

template <typename U>
matrix<U>& matrix<U>::operator*(const U& n){
  static matrix a(*this);
  for (int i = 0; i < this->rows; i++)
    for (int j = 0; j < this->columns; j++)
      a.array[i][j] *= n;
  return a;
}

template <typename T>
matrix<T>& matrix<T>::operator!(void){
  int d = this->determinant();
  if (d == 0){
    cout << ">> Non-invertible matrix as |matrix| = 0.\n";
    throw -1;
  }
  static matrix m(this->rows);
  double a = 1/double(this->determinant());
  m = this->adjoint() * a;
  return m;
}

template <typename U>
row<U>& matrix<U>::operator[](const int& index){
  static row<U> object;
  if (index >= this->rows)
    return object;
  object = &(this->array[index]);
  object.row_size = columns;
  return object;
}

template <typename T>
bool matrix<T>::operator==(const matrix& m){
  if ((this->rows != m.rows) || (this->columns != m.columns))
    return 0;
  for (int i = 0; i < m.rows; i++)
    for (int j = 0; j < m.columns; j++)
      if (m.array[i][j] != this->array[i][j])
        return 0;
  return 1;
}

template <typename T>
matrix<T>& matrix<T>::T(){
  static matrix t(this->columns, this->rows);
  for (int i = 0; i < this->rows; i++)
    for (int j = 0; j < this->columns; j++)
      t.array[j][i] = this->array[i][j];
  return t;
}

template <typename T>
int matrix<T>::determinant(){
  if (this->rows != this->columns)
    throw -1;
  int d = 0;
  int order = this->rows;
  if (order == 1)
    return this->array[0][0];
  else if (order == 2)
    return (array[0][0]*array[1][1] - array[0][1]*array[1][0]);
  else {
    int power = 1;
    for (int axis = 0; axis < order; axis++){
      int row = 0, column = 0;
      matrix cofactor(order-1);
      for (int i = 0; i < order; i++){
        for (int j = 0; j < order; j++){
          if (i != 0 && j != axis){
            cofactor.array[row][column] = this->array[i][j];
            if (column < order - 2)
              column++;
            else {
              column = 0;
              row++;
            }
          }
        }
      } 
      d += power * (this->array[0][axis] * cofactor.determinant());
      power *= (-1);
    }
  }
  return d;
}

template <typename T>
matrix<T>& matrix<T>::getCofactor(const int& ofRowIndex, const int& ofColumnIndex){
  static matrix cofactorMatrix(this->rows-1, this->columns-1);
  int order = this->rows; 
  int row = 0, column = 0;
  for (int i = 0; i < order; i++){
    for (int j = 0; j < order; j++){
      if (i != ofRowIndex && j != ofColumnIndex){
        cofactorMatrix.array[row][column] = this->array[i][j];
        if (column < order - 2)
          column++;
        else {
          column = 0;
          row++;
        }
      }
    }
  }
  return cofactorMatrix;
}

template <typename T>
matrix<T>& matrix<T>::adjoint(){
  if (this->rows != this->columns)
    throw -1;
  
  static matrix adjointMatrix(this->rows, this->columns);
  int order = this->rows;
  if (order == 1) adjointMatrix.array[0][0] = 1;
  else {
    int sign = 1;
    for (int i = 0; i < order; i++){
      for (int j = 0; j < order; j++){
        matrix cofactor = this->getCofactor(i, j);
        // cout << "CofactorMatrix: \n" << cofactor << "\n";
        sign = ((i + j) % 2 == 0) ? 1 : -1;
        adjointMatrix.array[j][i] = (sign) * cofactor.determinant();
      }
    }
  }
  return adjointMatrix;
}

template <typename T>
istream & operator>> (istream &in, matrix<T> &m){
  cout << "Enter the values:\n";
  for (int i = 0; i< m.rows; i++)
    for (int j = 0; j < m.columns; j++){
      int n; in >> n;
      m.array[i][j] = n;
    }
  return in;
};

template <typename T>
ostream & operator<< (ostream &out, matrix<T> &m){
  out << "\n";
  for (int i = 0; i < m.rows; i++){
    out << char(179);
    for (int j = 0; j < m.columns; j++)
      out << fixed << setprecision(2) << setw(8) << right << m.array[i][j] << setw(2) << "";
    out << char(179) << "\n";
  }
  out << "\n";
  return out;
};

int main(void){

  matrix<double> s(3);
  cin >> s; cout << s;
  matrix<double> m(2,3);
  cin >> m; cout << m;
  matrix<double> n(3,2);
  cin >> n; cout << n;

  cout << "m': " << m.T() << "\n";
  cout << "m: " << m << "\n";
  cout << "m+4: " << m+4 << "\n";
  try {
    cout << "m+m: " << m+m << "\n";
  } catch(int){
    cout << "Error: Matrix not of same order.\n";
  }
  try {
    cout << "m+n: " << m+n << "\n";
  } catch(int){
    cout << "Error: Matrix not of same order.\n";
  }
  cout << "s-1: " << s-1 << "\n";
  cout << "m*3: " << m*3 << "\n";
  try {
    cout << "m*n: " << m*n << "\n";
  } catch (int){
    cout << "Error: Matrix not of same order.\n";
  }
  try {
    cout << "|m|: " << m.determinant() << "\n";
  } catch(int){
    cout << "Error: Not a square matrix.\n";
    cout << "Determinant not defined.\n";
  }
  try {
    cout << "|s|: " << s.determinant() << "\n";
  } catch(int){
    cout << "Error: Not a square matrix.\n";
  }
  try {
    cout << "adj(s): \n" << s.adjoint() << "\n";
  } catch (int){
    cout << "Error: Not a square matrix.\n";
  }
  return 0;
}