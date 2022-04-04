#include <iostream>
using namespace std;

class salary {
public:
  double basic, bonus, gross;
  static double da;

public:
  salary(const double&);
  void updateGross();
  double averageSalary(const salary&);

  template <typename T>
  salary& operator=(const T&);
};

salary::salary(const double& basic){
  this->basic = basic;
  this->bonus = 5000;
  updateGross();
}

void salary::updateGross(){
  this->gross = this->basic + ((this->basic * da)/100) + this->bonus;
}

// WARN: NOT A FRIEND
double salary::averageSalary(const salary& s){
  return (s.gross + this->gross)/2;
}

template <typename T>
salary& salary::operator=(const T& basic){
  this->basic = double(basic);
  this->bonus = 5000;
  updateGross();
  return (*this);
}

double salary::da = 28;

int main(void){

  salary ceo = 150000;
  cout << ceo.basic << "\n";
  cout << ceo.bonus << "\n";
  cout << ceo.da << "\n";
  cout << ceo.gross << "\n";

  return 0;
}