#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

int myrand(long long &x){
  
  int a = 65539; long long m = 2147483647;
  x = ((x * a) % m);
  return x;
}

void chiSquareTest(int a[10000]){

  double OT[6][6];

  /* OBSERVATION TABLE

    Interval          Oi      Ei   Oi-Ei  (Oi-Ei)^2  (Oi-Ei)^2/Ei
    0  > && <= 10           2000
    10 > && <= 20           2000
    20 > && <= 30           2000
    30 > && <= 40           2000
    40 > && <= 50           2000
                    10000  10000
   */

  for (int i = 0; i < 6; i++){
    OT[i][1] = 0;
    OT[i][2] = 0;
    OT[i][3] = 0;
    OT[i][4] = 0;
    OT[i][5] = 0;
  }

  for (int i = 0; i < 10000; i++){
    if (a[i] > 0 && a[i] <= 10)
      OT[0][1]++;
    
    else if (a[i] > 10 && a[i] <= 20)
      OT[1][1]++;
    
    else if (a[i] > 20 && a[i] <= 30)
      OT[2][1]++;
    
    else if (a[i] > 30 && a[i] <= 40)
      OT[3][1]++;
    
    else if (a[i] > 40 && a[i] <= 50)
      OT[4][1]++;
    
  }


  for (int i = 0; i < 5; i++){
    
    // OT[i][1] = a[i];               // Oi
    OT[i][2] = 2000;                  // Ei
    OT[i][3] = OT[i][1] - OT[i][2];   // Oi-Ei
    OT[i][4] = OT[i][3] * OT[i][3];   // (Oi-Ei)^2 
    OT[i][5] = OT[i][4]/OT[i][2];     // (Oi-Ei)^2/Ei

  }

  int Oi = 0;
  int Ei = 0;
  double chi_square = 0;

  for (int i = 0; i < 6; i++){
    Oi += OT[i][1];
    Ei += OT[i][2];
    chi_square += OT[i][5];
  }
  OT[5][1] = Oi;
  OT[5][2] = Ei;
  OT[5][5] = chi_square;

  cout << "Interval          Oi          Ei     (Oi-Ei)   (Oi-Ei)^2   (Oi-Ei)^2/Ei" << "\n";
  for (int i = 0; i < 6; i++){
    if (i == 5){
      cout << "        " << setprecision(2) << fixed << right << setw(12) << OT[i][1] << right << setw(12) << OT[i][2] << right << setw(12) << OT[i][3] << right << setw(12) << OT[i][4] << right << setw(15)<< OT[i][5] << "\n";
      break;
    }
    cout << setw(3) << right << i*10 << " - " << (i+1)*10 << setprecision(2) << fixed << right << setw(12) << OT[i][1] << right << setw(12) << OT[i][2] << right << setw(12) << OT[i][3] << right << setw(12) << OT[i][4] << right << setw(15)<< OT[i][5] << "\n";
  }

}


int main(void){
  
  long long x0 = time(0);
  srand(x0);

  int a[10000], b[10000];
  for (long long i = 0; i < 10000; i++){
    a[i] = myrand(x0) % 50 + 1;
    b[i] = rand() % 50 + 1;
  }

  // for (int i = 0; i < 10000; i++){
  //   if (i % 10 == 0) cout << "\n";
  //   cout << setw(4) << right << a[i];
  // } 
  // cout << "\n";

  cout << "\n>> Chi-Square Test on myrand() \n";
  chiSquareTest(a);
  cout << "\n>> Chi-Square Test on rand() \n";
  chiSquareTest(b);
  
  return 0;
}