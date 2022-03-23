#include <iostream>
using namespace std;

class vehicle {
protected:
  int wheels;
  int speed;
public:
  bool isFasterThan(const vehicle&);
};

bool vehicle::isFasterThan(const vehicle& v){
  return this->speed > v.speed;
}

class car: public vehicle {
protected:
  int passengers;
public:
  car(const int& = 4, const int& = 4, const int& = 180);
};

car::car(const int& passengers, const int& wheels, const int& speed){
  this->wheels = wheels;
  this->speed = speed;
  this->passengers = passengers;
}

class truck: public vehicle {
protected:
  int loadLimit;
public:
  truck(const int& = 10000, const int& = 16, const int& = 70);
};

truck::truck(const int& loadLimit, const int& wheels, const int& speed){
  this->wheels = wheels;
  this->speed = speed;
  this->loadLimit = loadLimit;
}

int main(void){

  car c1;
  truck t1;

  cout << c1.isFasterThan(t1) << "\n";
  cout << t1.isFasterThan(c1) << "\n";

  car c2(5,5, 100);
  truck t2(1800, 8, 120);

  cout << c2.isFasterThan(t2) << "\n";
  cout << t2.isFasterThan(c2) << "\n";
  
  return 0;
}