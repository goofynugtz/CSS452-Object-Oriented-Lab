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
  friend ostream& operator<<(ostream&, const car&);
};

car::car(const int& passengers, const int& wheels, const int& speed){
  this->wheels = wheels;
  this->speed = speed;
  this->passengers = passengers;
}

ostream& operator<<(ostream& out, const car& c){
  out << "\nCar:\n";
  out << ">> Top Speed: " << c.speed;
  out << "\n>> Passenger Capacity: " << c.passengers;
  out << "\n>> Wheels: " << c.wheels << "\n";
  return out;
}

class truck: public vehicle {
protected:
  int loadLimit;
public:
  truck(const int& = 10000, const int& = 16, const int& = 70);
  friend ostream& operator<<(ostream&, const truck&);
};

truck::truck(const int& loadLimit, const int& wheels, const int& speed){
  this->wheels = wheels;
  this->speed = speed;
  this->loadLimit = loadLimit;
}

ostream& operator<<(ostream& out, const truck& t){
  out << "\nTruck:\n";
  out << ">> Top Speed: " << t.speed;
  out << "\n>> Max Load: " << t.loadLimit;
  out << "\n>> Wheels: " << t.wheels << "\n";
  return out;
}

int main(void){

  car c1;
  truck t1;

  cout << c1 << t1 << endl;
  c1.isFasterThan(t1) ? cout << "faster: " : cout << "slower: ";
  cout << c1.isFasterThan(t1) << "\n";
  t1.isFasterThan(c1) ? cout << "faster: " : cout << "slower: ";
  cout << t1.isFasterThan(c1) << "\n";

  car c2(5,5, 100);
  truck t2(1800, 8, 120);
  
  cout << c2 << t2 << endl;
  c2.isFasterThan(t2) ? cout << "faster: " : cout << "slower: ";
  cout << c2.isFasterThan(t2) << "\n";
  t2.isFasterThan(c2) ? cout << "faster: " : cout << "slower: ";
  cout << t2.isFasterThan(c2) << "\n";
  
  return 0;
}