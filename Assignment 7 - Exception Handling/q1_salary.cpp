#include <iostream>
using namespace std;

class salary {
public:
  double basic, bonus, gross;
  static double da;

public:
  salary(const double&);
  void updateGross();
  // double averageSalary(const salary&);
  friend double averageSalary(const salary&, const salary&);

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
/* double salary::averageSalary(const salary& s){
  return (s.gross + this->gross)/2;
} */

double averageSalary(const salary& s1, const salary& s2){
  return (s1.gross + s2.gross)/2;
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
  salary cto = 100000;
  cout << "CEO Basic: " << ceo.basic << "\n";
  cout << "Bonus: " << ceo.bonus << "\n";
  cout << "DA: " << ceo.da << "\n";
  cout << "CEO Gross Income: " << ceo.gross << "\n";
  cout << "Average salary of CEO && CTO: " << averageSalary(ceo, cto) << "\n";
  return 0;
}