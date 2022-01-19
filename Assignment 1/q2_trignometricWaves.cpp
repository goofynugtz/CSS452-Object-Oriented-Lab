#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;


void displaySineWave(double start, double end, char c, int width){

  char FILL_LIGHT = char(176);
  char FILL_DARK = char(178);

  cout << "\n";
  cout << setw(width) << setfill(FILL_LIGHT) << "\n";
  cout << setw(4) << FILL_LIGHT << setw(width - 9) << setfill(' ') << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(4) << FILL_LIGHT << setw(width/2) << setfill(' ') << "SINE WAVE" << setw(width/2 - 9) << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(4) << FILL_LIGHT << setw(width - 9) << setfill(' ') << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(width) << setfill(FILL_LIGHT) << "\n";
  

  cout << "\n";

  for (int i = start; i <= end; i += width/10){
    int x = floor(sin(i * 3.14 / 180) * width/5);
    if (x >= 0)
      cout << setw(width/2) << setfill(' ') << char(179) << setw(x) << setfill(c) << char(167) << endl;
    else
      cout << setw(width/2 + x) << setfill(' ') << char(167) << setw(-x) << setfill(c) << char(179) << endl;
  }

  cout << endl;
  cout << setw(width) << setfill(FILL_DARK) << "\n";
  cout << endl;
}


void displayCosineWave(double start, double end, char c, int width){

  char FILL_LIGHT = char(176);
  char FILL_DARK = char(178);

  cout << "\n";
  cout << setw(width) << setfill(FILL_LIGHT) << "\n";
  cout << setw(4) << FILL_LIGHT << setw(width - 9) << setfill(' ') << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(4) << FILL_LIGHT << setw(width/2) << setfill(' ') << "COSINE WAVE" << setw(width/2 - 9) << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(4) << FILL_LIGHT << setw(width - 9) << setfill(' ') << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(width) << setfill(FILL_LIGHT) << "\n";

  cout << "\n";

  for (int i = start; i <= end; i += width/10){
    int x = floor(cos(i * 3.14 / 180) * width/5);
    if (x >= 0)
      cout << setw(width/2) << setfill(' ') << char(179) << setw(x) << setfill(c) << char(167) << endl;
    else
      cout << setw(width/2 + x) << setfill(' ') << char(167) << setw(-x) << setfill(c) << char(179) << endl;
  }

  cout << endl;
  cout << setw(width) << setfill(FILL_DARK) << "\n";
  cout << endl;
}


void displayExponentialCurve(double start, double end, char c, int width){

  char FILL_LIGHT = char(176);
  char FILL_DARK = char(178);

  cout << "\n";
  cout << setw(width) << setfill(FILL_LIGHT) << "\n";
  cout << setw(4) << FILL_LIGHT << setw(width - 9) << setfill(' ') << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(4) << FILL_LIGHT << setw(width/2) << setfill(' ') << "EXPONENTIAL" << setw(width/2 - 9) << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(4) << FILL_LIGHT << setw(width - 9) << setfill(' ') << "" << setw(4) << setfill(FILL_LIGHT) << FILL_LIGHT << "\n";
  cout << setw(width) << setfill(FILL_LIGHT) << "\n";

  cout << "\n";
  for (double i = start, j = 0.01; i <= end; i+= 0.25, j+= 0.25){
    double x = exp(i);
    cout << fixed << setprecision(1) << j << " " << char(179) << setw(x) << setfill(c) << FILL_DARK << " " << setprecision(2) << x << endl;
  }
  // cout << setw(width) << setfill(FILL_DARK) << "\n";

  cout << endl;
}

int main (void){

  double start = 0, end = 360;
  char c = ' ';
  int WIDTH = 100;
  int SPEED = 10;

  displayCosineWave(start, end, c, WIDTH);
  displaySineWave(start, end, c, WIDTH);
  displayExponentialCurve(0, 4, char(176), WIDTH);

  return 0;
}