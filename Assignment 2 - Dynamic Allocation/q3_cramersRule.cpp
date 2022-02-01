#include <iostream>
#include <vector>
#include "./matrix.h"
using namespace std;


void cramersRule (Matrix A, int n, Matrix B){
  
  int d = A.calculateDeterminant();
  Matrix * D[n];
  for (int k = 0; k < n; k++){
    D[k] = new Matrix(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++){
        int value;
        if (j == k)
          value = B.getValue(i, 0);
        else 
          value = A.getValue(i, j);
        D[k] -> setValue(i, j, value);
      }
  } 
  for (int k = 0; k < n; k++){
    cout << *D[k];
    int di = D[k]->calculateDeterminant();
    cout << "Determinant: " << di << "\n";
    cout << "Corresponding Variable: " << di/d;
    cout << "\n\n\n";
  }
}


int main (void){

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