#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
T __lcm(const T& a, const T& b){
  return ((a*b)/__gcd(a,b));
}

template <typename T>
class fraction {
private:
  T numerator;
  T denominator;

public:
  fraction(const T& = 0, const T& = 1);
  fraction& operator+(const fraction&);
  fraction& operator+(const T&);
  fraction& operator-(const fraction&);
  fraction& operator-(const T&);
  fraction& operator*(const fraction&);
  fraction& operator*(const T&);
  fraction& operator/(const fraction&);
  fraction& operator/(const T&);
  fraction& operator*(void); // Normalize
  bool operator==(const fraction&);
  bool operator!=(const fraction&);
  bool operator<(const fraction&);
  bool operator>(const fraction&);
  fraction& operator=(const fraction&);
  T& operator[](const T&);
  
  template <typename U>
  friend ostream& operator<<(ostream&, fraction<U>&);
  
  template <typename U>
  friend istream& operator<<(istream&, fraction<U>&);
};

template <typename T>
fraction<T>::fraction(const T& num, const T& den){
  this->numerator = num;
  this->denominator = den;
}

template <typename T>
fraction<T>& fraction<T>::operator+(const fraction<T>& f){
  static fraction a;
  if (this->denominator == f.denominator){
    a.numerator = this->numerator + f.numerator;
    a.denominator = f.denominator;
  } else {
    T LCM = __lcm(this->denominator, f.denominator);
    a.denominator = LCM;
    a.numerator = (this->numerator * LCM) + (f.numerator * LCM);
  }
  return a;
}

template <typename T>
fraction<T>& fraction<T>::operator-(const fraction<T>& f){
  static fraction a;
  if (this->denominator == f.denominator){
    a.numerator = this->numerator - f.numerator;
    a.denominator = f.denominator;
  } else {
    T LCM = __lcm(this->denominator, f.denominator);
    a.denominator = LCM;
    a.numerator = (this->numerator * LCM) - (f.numerator * LCM);
  }
  return a;
}

template <typename T>
fraction<T>& fraction<T>::operator*(const fraction<T>& f){
  static fraction a;
  a.numerator = this->numerator * f.numerator;
  a.denominator = this->denominator * f.denominator;
  return a;
}

template <typename T>
fraction<T>& fraction<T>::operator/(const fraction<T>& f){
  static fraction a;
  a.numerator = this->numerator * f.denominator;
  a.denominator = this->denominator * f.numerator;
  return a;
}

template <typename T>
fraction<T>& fraction<T>::operator*(void){
  static fraction a;
  T n = __gcd(this->numerator, this->denominator);
  a.numerator = this->numerator/n;
  a.denominator = this->denominator/n;
  return a;
}

template <typename T>
bool fraction<T>::operator==(const fraction<T>& f){
  return ((this->numerator / this->denominator) == (f.numerator / f.denominator));
}

template <typename T>
bool fraction<T>::operator!=(const fraction<T>& f){
  return !((this->numerator / this->denominator) == (f.numerator / f.denominator));
}

template <typename T>
bool fraction<T>::operator<(const fraction<T>& f){
  return ((this->numerator / this->denominator) < (f.numerator / f.denominator));
}

template <typename T>
bool fraction<T>::operator>(const fraction<T>& f){
  return ((this->numerator / this->denominator) > (f.numerator / f.denominator));
}

template <typename T>
fraction<T>& fraction<T>::operator=(const fraction<T>& f){
  this->numerator = f.numerator;
  this->denominator = f.denominator;
  return *this;
}

template <typename T>
T& fraction<T>::operator[](const T& n){
  return n ? denominator : numerator;
}

template <typename T>
ostream& operator<<(ostream& out, fraction<T>& f){
  out << f.numerator << "/" << f.denominator;
  return out;
}

template <typename T>
istream& operator<<(istream& in, fraction<T>& f){
  in >> f.numerator >> f.denominator;
  return in;
}


int main(void){

  fraction<int> f1(5,2);
  cout << "f1: " << f1 << " :: @ " << &f1 << "\n";
  fraction<int> f2(2,5);
  cout << "f2: " << f2 << " :: @ " << &f2 << "\n";
  fraction<int> f3(f2);
  cout << "f3: " << f3 << " :: @ " << &f3 << "\n";
  cout << "f1 + f2: " << f1+f2 << "\n";
  cout << "f1 - f2: " << f1-f2 << "\n";
  cout << "f1 * f2: " << f1*f2 << "\n";
  fraction<int> f4(5,10);

  cout << "is f1 < f2: " << (f1<f2) << "\n";
  cout << "f1[0]: " << f1[0] << "\n";
  cout << f4 << " ==> " << *f4 << "\n";

  return 0;
}