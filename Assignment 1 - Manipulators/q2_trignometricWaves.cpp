#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;


void displaySineWave(double start, double end, char c, double step){

  system("clear");

  char FILL_LIGHT = char(176);
  char FILL_DARK = char(178);
  int WIDTH = 100;

  cout << "\n";
  cout << setw(WIDTH) << setfill(FILL_LIGHT) << "\n";
  cout << setw(4) << FILL_LIGHT << setw(WIDTH - 9) << setfill(' ') << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(4) << FILL_LIGHT << setw(WIDTH/2) << setfill(' ') << "SINE WAVE" << setw(WIDTH/2 - 9) << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(4) << FILL_LIGHT << setw(WIDTH - 9) << setfill(' ') << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(WIDTH) << setfill(FILL_LIGHT) << "\n";
  

  cout << "\n";

  for (int i = start; i <= end; i += int(step)){
    int x = floor(sin(i * 3.14 / 180) * WIDTH/4);
    if (x >= 0)
      cout << setw(WIDTH/2) << setfill(' ') << char(179) << setw(x) << setfill(c) << char(167) << endl;
    else
      cout << setw(WIDTH/2 + x) << setfill(' ') << char(167) << setw(-x) << setfill(c) << char(179) << endl;
  }

  cout << endl;
  cout << setw(WIDTH) << setfill(FILL_DARK) << "\n";
  cout << endl;
}


void displayCosineWave(double start, double end, char c, double step){

  system("clear");

  char FILL_LIGHT = char(176);
  char FILL_DARK = char(178);
  int WIDTH = 100;

  cout << "\n";
  cout << setw(WIDTH) << setfill(FILL_LIGHT) << "\n";
  cout << setw(4) << FILL_LIGHT << setw(WIDTH - 9) << setfill(' ') << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(4) << FILL_LIGHT << setw(WIDTH/2) << setfill(' ') << "COSINE WAVE" << setw(WIDTH/2 - 9) << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(4) << FILL_LIGHT << setw(WIDTH - 9) << setfill(' ') << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(WIDTH) << setfill(FILL_LIGHT) << "\n";

  cout << "\n";

  for (int i = start; i <= end; i += int(step)){
    int x = floor(cos(i * 3.14 / 180) * WIDTH/4);
    if (x >= 0)
      cout << setw(WIDTH/2) << setfill(' ') << char(179) << setw(x) << setfill(c) << char(167) << endl;
    else
      cout << setw(WIDTH/2 + x) << setfill(' ') << char(167) << setw(-x) << setfill(c) << char(179) << endl;
  }

  cout << endl;
  cout << setw(WIDTH) << setfill(FILL_DARK) << "\n";
  cout << endl;
}


void displayExponentialCurve(double start, double end, char c, double step){

  system("clear");

  char FILL_LIGHT = char(176);
  char FILL_DARK = char(178);
  int WIDTH = 100;

  cout << "\n";
  cout << setw(WIDTH) << setfill(FILL_LIGHT) << "\n";
  cout << setw(4) << FILL_LIGHT << setw(WIDTH - 9) << setfill(' ') << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(4) << FILL_LIGHT << setw(WIDTH/2) << setfill(' ') << "EXPONENTIAL" << setw(WIDTH/2 - 9) << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(4) << FILL_LIGHT << setw(WIDTH - 9) << setfill(' ') << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(WIDTH) << setfill(FILL_LIGHT) << "\n";

  cout << "\n";
  for (double i = start, j = 0.01; i <= end; i+= step, j+= step){
    double x = exp(i);
    cout << fixed << setprecision(1) << j << " " << char(179) << setw(x) << setfill(c) << FILL_DARK << " " << setprecision(2) << x << endl;
  }
  // cout << setw(width) << setfill(FILL_DARK) << "\n";

  cout << endl;
}

int main (void){


  bool wantToExit = 0;

  while (!wantToExit){
    cout << "\n1. Cosine Wave.";
    cout << "\n2. Sine Wave.";
    cout << "\n3. Exponential Wave.";
    cout << "\n0. Exit";
    cout << "\nChoose Option >> ";
    int n; cin >> n;

    double start = 0, end = 360;
    char c = ' ';
    double STEP = 10;
    int SPEED = 10;


    switch (n){
    case 0:
      wantToExit = 1;
      break;

    case 1:
      cout << "Enter #start #end #step (Recommended: 0 360 10) >> ";
      cin >> start >> end >> STEP;
      if (STEP > 0)
        displayCosineWave(start, end, c, STEP);
      else
        cout << "\nError >> Invalid #step value. Value must be greater than 0.\n";
      break;
    
    case 2:
      cout << "Enter #start #end #step (Recommended: 0 360 10) >> ";
      cin >> start >> end >> STEP;
      if (STEP > 0)
        displaySineWave(start, end, c, STEP);
      else
        cout << "\nError >> Invalid #step value. Value must be greater than 0.\n";
      break;

    case 3:
      cout << "Enter #start #end #step (Recommended: 0 4 0.25) >> ";
      cin >> start >> end >> STEP;
      if (STEP > 0)
        displayExponentialCurve(start, end, char(176), STEP);
      else
        cout << "\nError >> Invalid #step value. Value must be greater than 0.\n";
      break;

    default:
      cout << ">> Invalid Option.\n";
      break;
    }
  }





  return 0;
}