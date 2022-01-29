#include <iostream>
#include <iomanip>
using namespace std;


class Matrix {

  private:

    int rows;
    int columns;
    bool isSquare;
    int ** matrix;

    // This is an overloaded function 
    // I don't want to use outside of this class.
    int calculateDeterminant(int ** arr, int &order) {
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
          determinant += power * (arr[0][axis] * calculateDeterminant(minor, size));
          power *= (-1);
        }
      }
      return determinant;
    };


  public:

    int getRows(){
      return rows;
    };
    
    int getColumns(){
      return columns;
    };

    int getValue(int i, int j){
      return matrix[i][j];
    };

    void setValue(int i, int j, int value){
      matrix[i][j] = value;
    };

    Matrix (int order){
      rows = order;
      columns = order;
      isSquare = true;
      matrix = new int *[rows];
      for (int i = 0; i < rows; i++)
        matrix[i] = new int[columns];
    };

    Matrix (int row, int column){
      rows = row;
      columns = column;
      isSquare = false;
      matrix = new int *[rows];
      for (int i = 0; i < rows; i++)
        matrix[i] = new int[columns];
    };

    void fillValues (){
      cout << "Enter the values:\n";
      for (int i = 0; i< rows; i++)
        for (int j = 0; j < columns; j++){
          int n; cin >> n;
          matrix[i][j] = n;
        }
    };

    int calculateDeterminant() {
      if (isSquare){
        int determinant;
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
            determinant += power * (matrix[0][axis] * calculateDeterminant(minor, size));
            power *= (-1);
          }
        }
        return determinant;
      } else 
        cout << "Error: Not a square matrix.\n";
    };
    
    void previewMatrix (){
      cout << "\n";
      for (int i = 0; i < rows; i++){
        cout << char(179);
        for (int j = 0; j < columns; j++)
          cout << setw(4) << right << matrix[i][j] << setw(2) << "";
        cout << char(179) << "\n";
      }
      cout << "\n";
    };

    Matrix operator* (Matrix const &arr){
      if (columns == arr.rows){
        Matrix result(rows, arr.columns);
        for (int i = 0; i < rows; i++)
          for (int j = 0; j < arr.columns; j++){
            result.matrix[i][j] = 0;
            for (int k = 0; k < columns; k++)
              result.matrix[i][j] += matrix[i][k] * arr.matrix[k][j];
          }
        return result;
      }
    };
    
    void operator= (Matrix const &arr){
      columns = arr.columns;
      rows = arr.rows;
      isSquare = arr.isSquare;
      matrix = arr.matrix;
    };
};
