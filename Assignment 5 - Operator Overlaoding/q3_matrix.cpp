#include <iostream>
#include <iomanip>
using namespace std;

class row {
public:
  double * row_address;
  int row_size;
  row(double ** f = NULL){
    if(f != NULL)
      row_address = *f;
    else
      row_address = NULL;
  }
  double& operator[](int index){
    return this->row_address[index];
  }
};

class matrix {
private:
  int rows, columns;
  double ** array;

public:
  matrix(const matrix&);
  matrix(const int&);
  matrix(const int&, const int&);
  matrix& operator+(const matrix&);
  matrix& operator+(const double&);
  matrix& operator-(const matrix&);
  matrix& operator-(const double&);
  matrix& operator*(const matrix&);
  matrix& operator*(const double&);
  // Don't know about anything as matrix division!
  matrix& operator!(void);
  matrix& getCofactor(const int&, const int&);
  matrix& adjoint();
  int determinant();
  matrix& T();
  row& operator[](const int&);
  bool operator==(const matrix&);
  friend istream & operator>> (istream&, matrix&);
  friend ostream & operator<< (ostream&, matrix&);
};

matrix::matrix(const matrix& m){
  this->rows = m.rows;
  this->columns = m.columns;
  array = new double*[m.rows];
  for (int i = 0; i < m.columns; i++)
    array[i] = new double[m.columns];
  for (int i = 0; i < m.rows; i++)
    for (int j = 0; j < m.rows; j++)
      this->array[i][j] = m.array[i][j];  
}

matrix::matrix(const int& order){
  rows = order;
  columns = order;
  array = new double*[order];
  for (int i = 0; i < order; i++)
    array[i] = new double[order];
}

matrix::matrix(const int& row, const int& column){
  this->rows = row;
  this->columns = column;
  array = new double *[rows];
  for (int i = 0; i < rows; i++)
    array[i] = new double[columns];
}

matrix& matrix::operator+(const matrix& m){
  static matrix a(*this);
  if (this->rows == m.rows && this->columns == m.columns)
    for (int i = 0; i < m.rows; i++)
      for (int j = 0; j < m.columns; j++)
        a.array[i][j] += m.array[i][j];
  return a;
}

matrix& matrix::operator+(const double& n){
  static matrix a(*this);
  for (int i = 0; i < this->rows; i++)
    for (int j = 0; j < this->columns; j++)
      a.array[i][j] += n;
  return a;
}

matrix& matrix::operator-(const matrix& m){
  static matrix a(m);
  if (this->rows == m.rows && this->columns == m.columns)
    for (int i = 0; i < m.rows; i++)
      for (int j = 0; j < m.columns; j++)
        a.array[i][j] -= m.array[i][j];
  return a;
}

matrix& matrix::operator-(const double& n){
  static matrix a(*this);
  for (int i = 0; i < this->rows; i++)
    for (int j = 0; j < this->columns; j++)
      a.array[i][j] -= n;
  return a;
}

matrix& matrix::operator*(const matrix& m){
  static matrix result(rows, m.columns);
  if (columns == m.rows){
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < m.columns; j++){
        result.array[i][j] = 0;
        for (int k = 0; k < columns; k++)
          result.array[i][j] += array[i][k] * m.array[k][j];
      }
    return result;
  } else {
    cout << "Error: Multiplication is not defined.\n";
    cout << "c1 != r2.\n";
  }
  return result;
}

matrix& matrix::operator*(const double& n){
  static matrix a(*this);
  for (int i = 0; i < this->rows; i++)
    for (int j = 0; j < this->columns; j++)
      a.array[i][j] *= n;
  return a;
}

matrix& matrix::operator!(void){
  int d = this->determinant();
  static matrix m(this->rows);
  if (d != 0){
    double a = 1/double(this->determinant());
    m = this->adjoint() * a;
  } else 
    cout << ">> Non-invertible matrix as |matrix| = 0.\n";
  return m;
}

row& matrix::operator[](const int& index){
  static row object;
  if (index >= this->rows)
    return object;
  object = &(this->array[index]);
  object.row_size = columns;
  return object;
}

bool matrix::operator==(const matrix& m){
  if ((this->rows != m.rows) || (this->columns != m.columns))
    return 0;
  for (int i = 0; i < m.rows; i++)
    for (int j = 0; j < m.columns; j++)
      if (m.array[i][j] != this->array[i][j])
        return 0;
  return 1;
  
}

matrix& matrix::T(){
  static matrix t(this->columns, this->rows);
  for (int i = 0; i < this->rows; i++)
    for (int j = 0; j < this->columns; j++)
      t.array[j][i] = this->array[i][j];
  return t;
}

int matrix::determinant(){
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

matrix& matrix::getCofactor(const int& ofRowIndex, const int& ofColumnIndex){
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

matrix& matrix::adjoint(){
  static matrix adjointMatrix(this->rows, this->columns);
  if (this->rows == this->columns){
    int order = this->rows;
    if (order == 1) adjointMatrix[0][0] = 1;
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
  }
  return adjointMatrix;
}

istream & operator>> (istream &in, matrix &m){
  cout << "Enter the values:\n";
  for (int i = 0; i< m.rows; i++)
    for (int j = 0; j < m.columns; j++){
      int n; in >> n;
      m.array[i][j] = n;
    }
  return in;
};

ostream & operator<< (ostream &out, matrix &m){
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

  matrix m(3);
  cin >> m;
  cout << m;
  cout << "m': " << m.T() << "\n";
  cout << "m+4: " << m+4 << "\n";
  cout << "m+m: " << m+m << "\n";
  cout << "m-1: " << m-1 << "\n";
  cout << "m*3: " << m*3 << "\n";
  cout << "m[0][1]: " << m[0][1] << "\n";
  cout << "|m|: " << m.determinant() << "\n";
  cout << "adj(m): \n" << m.adjoint() << "\n";
  cout << "m^-1: \n" << !m << "\n";
  matrix n = m;
  cout << "m == n: " << (m==n) << "\n";

  return 0;
}