#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
  private:
    int rows;
    int columns;
    bool isSquare;
    int ** matrix;
    int calculateMinor(int ** arr, int &order);

  public:
    int getRows(){return rows;};
    int getColumns(){return columns;};
    int getValue(int i, int j){return matrix[i][j];};
    void setValue(int i, int j, int value){matrix[i][j] = value;};

    // 1. allocateSpace
    Matrix(const int);
    Matrix(const int, const int);
    Matrix(const Matrix&);
    ~Matrix();
    // 2. readMatrix
    friend istream & operator>> (istream &, Matrix &);
    // 3. displayMatrix
    friend ostream & operator<< (ostream &, Matrix &);
    // 4. addMatrix
    Matrix operator+ (Matrix const &);
    // 5.  multMatrix
    Matrix operator* (Matrix const &);
    Matrix operator= (const Matrix&);
    // 6. detMatrix
    int getDeterminant();
};

Matrix::Matrix (const int order){
  rows = order;
  columns = order;
  isSquare = true;
  matrix = new int *[rows];
  for (int i = 0; i < rows; i++)
    matrix[i] = new int[columns];
};

Matrix::Matrix (const int row, const int column){
  rows = row;
  columns = column;
  if (rows == columns)
    isSquare = true;
  else
    isSquare = false;
  matrix = new int *[rows];
  for (int i = 0; i < rows; i++)
    matrix[i] = new int[columns];
};

Matrix::Matrix(const Matrix& N){
  rows = N.rows;
  columns = N.columns;
  matrix = new int *[rows];
  for (int i = 0; i < rows; i++)
    matrix[i] = new int[columns];
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)    
      matrix[i][j] = N.matrix[i][j];
}

Matrix::~Matrix(){
  delete[] matrix;
}

istream &operator>> (istream &in, Matrix &m){
  cout << "Enter the values:\n";
  for (int i = 0; i< m.rows; i++)
    for (int j = 0; j < m.columns; j++){
      int n; in >> n;
      m.matrix[i][j] = n;
    }
  return in;
};

ostream &operator<< (ostream &out, Matrix &m){
  out << "\n";
  for (int i = 0; i < m.rows; i++){
    out << char(179);
    for (int j = 0; j < m.columns; j++)
      out << setw(4) << right << m.matrix[i][j] << setw(2) << "";
    out << char(179) << "\n";
  }
  out << "\n";
  return out;
};

Matrix Matrix::operator+ (Matrix const &arr){
  if (this->columns == arr.columns && this->rows == arr.rows){
    Matrix result(rows, columns);
    for (int i = 0; i < rows; i++)
      for (int j = 0; j < columns; j++)
        result.matrix[i][j] = this->matrix[i][j] + arr.matrix[i][j];
    return result;
  } else {
    cout << "Error: Addition not defined.\n";
    cout << "Order of matrix must be equal.\n";
    return (*this);
  }
};

Matrix Matrix::operator* (Matrix const &arr){
  if (this->columns == arr.rows){
    Matrix result(this->rows, arr.columns);
    for (int i = 0; i < this->rows; i++)
      for (int j = 0; j < arr.columns; j++){
        result.matrix[i][j] = 0;
        for (int k = 0; k < this->columns; k++)
          result.matrix[i][j] += this->matrix[i][k] * arr.matrix[k][j];
      }
    return result;
  } else {
    cout << "Error: Multiplication is not defined.\n";
    cout << "c1 != r2.\n";
    return (*this);
  }
};

Matrix Matrix::operator= (Matrix const &arr){
  columns = arr.columns;
  rows = arr.rows;
  isSquare = arr.isSquare;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      matrix[i][j] = arr.matrix[i][j];
  return (*this);
};


int Matrix::calculateMinor(int ** arr, int &order) {
  int determinant;
  int power = 1;
  if (order == 1)
    return arr[0][0];
  else {
    determinant = 0;
    int ** minor; int size = order - 1;
    for (int axis = 0; axis < order; axis++){
      int row = 0, column = 0;
      minor = new int *[size];
      for (int i = 0; i < size; i++){
        minor[i] = new int[size];
      }
      for (int i = 0; i < order; i++){
        for (int j = 0; j < order; j++){
          if (i != 0 && j != axis){
            minor[row][column] = arr[i][j];
            if (column < order - 2)
              column++;
            else {
              column = 0;
              row++;
            }
          }
        }
      }
      determinant += power * (arr[0][axis] * calculateMinor(minor, size));
      power *= (-1);
    }
  }
  return determinant;
};

int Matrix::getDeterminant() {
  int determinant = 0;
  if (isSquare){
    int power = 1;
    int &order = rows;
    if (order == 1)
      return matrix[0][0];
    else {
      determinant = 0;
      int ** minor; int size = order - 1;
      for (int axis = 0; axis < order; axis++){
        int row = 0, column = 0;
        minor = new int *[size];
        for (int i = 0; i < size; i++){
          minor[i] = new int[size];
        }
        for (int i = 0; i < order; i++){
          for (int j = 0; j < order; j++){
            if (i != 0 && j != axis){
              minor[row][column] = matrix[i][j];
              if (column < order - 2)
                column++;
              else {
                column = 0;
                row++;
              }
            }
          }
        }
        determinant += power * (matrix[0][axis] * calculateMinor(minor, size));
        power *= (-1);
      }
    }
    return determinant;
  } else {
    cout << "Error: Not a square matrix.\nDeterminant is not defined.\n";
    return int(NULL);
  }
};

void cramersRule (Matrix A, int n, Matrix C){
  int d = A.getDeterminant();
  Matrix * D[n];
  for (int k = 0; k < n; k++){
    D[k] = new Matrix(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++){
        int value;
        if (j == k)
          value = C.getValue(i, 0);
        else 
          value = A.getValue(i, j);
        D[k] -> setValue(i, j, value);
      }
  } 
  for (int k = 0; k < n; k++){
    cout << *D[k];
    int di = D[k]->getDeterminant();
    cout << "Determinant: " << di << "\n";
    cout << "Corresponding Variable: " << di/d;
    cout << "\n\n\n";
  }
}


int main (void){

  int order;
  cout << "\nEnter #order of matrix: ";
  cin >> order;
  Matrix X(order);
  cout << "\nX: ";
  cin >> X;
  
  Matrix Y(order);
  cout << "\nY: ";
  cin >> Y;

  Matrix added = X+Y;
  Matrix multiplied = X*Y;
  cout << "Added: \n" << added;
  cout << "Multiplied: \n" << multiplied;
  cout << "Determinant of Result: " << multiplied.getDeterminant() << "\n";


  cout << "\nEnter the no. of linear equations: ";
  int n; cin >> n;
  cout << "Enter the co-eff matrix of eq(s) below\n";
  Matrix A(n), B(n,1);
  for (int i = 0; i < n; i++){
    int value;
    for (int j = 0; j < n; j++){
      cin >> value;
      A.setValue(i,j, value);
    }
    cin >> value;
    B.setValue(i,0, value);
  }
  cramersRule(A, n, B);
  
  return 0;
}