#include <iostream>
using namespace std;

template <typename T>
class complex {
private:
  T real;
  T imaginary;

public:
  complex(const T& = 0, const T& = 0);
  complex& operator+(const complex&);
  complex& operator+(const T&);
  template <typename U>
  friend complex<U>& operator+(const int&, complex<U>&);

  complex& operator-(const complex&);
  complex& operator-(const T&);
  template <typename U>
  friend complex<U>& operator-(const int&, complex<U>&);

  complex& operator*(const complex&);
  complex& operator*(const T&);
  template <typename U>
  friend complex<U>& operator*(const int&, complex<U>&);

  complex& operator/(const complex&);
  complex& operator/(const T&);

  complex& operator!(void);
  bool operator==(const complex&);
  bool operator!=(const complex&);
  // Default copy constructer/assignment '=' operator would work fine as 
  // no pointers are involved in class.
  T& operator[](const int&);
  template <typename U>
  friend ostream& operator<< (ostream&, complex<U>&);
  template <typename U>
  friend istream& operator>> (istream&, complex<U>&);
};

template <typename T>
complex<T>::complex(const T& real, const T& imaginary){
  this->real = real;
  this->imaginary = imaginary;
}

template <typename T>
complex<T>& complex<T>::operator+(const complex<T>& n){
  static complex<T> c;
  c.real = this->real + n.real;
  c.imaginary = this->imaginary + n.imaginary;
  return c;
}

template <typename T>
complex<T>& complex<T>::operator+(const T& n){
  static complex<T> c;
  c.real = this->real + n;
  c.imaginary = this->imaginary;
  return c;
}

template <typename U>
complex<U>& operator+(const int& n, complex<U>& c){
  static complex<U> a;
  a.real = n + c.real;
  a.imaginary = c.imaginary;
  return a;
}

template <typename T>
complex<T>& complex<T>::operator-(const T& n){
  static complex<T> c;
  c.real = this->real - n;
  c.imaginary = this->imaginary;
  return c;
}

template <typename T>
complex<T>& complex<T>::operator-(const complex<T>& n){
  static complex<T> c;
  c.real = this->real - n.real;
  c.imaginary = this->imaginary - n.imaginary;
  return c;
}

template <typename U>
complex<U>& operator-(const int& n, complex<U>& c){
  static complex<U> a(c);
  a.real -= n;
  return a;
}

template <typename T>
complex<T>& complex<T>::operator*(const complex<T>& n){
  static complex<T> c(0,0);
  c.real = (this->real * n.real) - (this->imaginary * n.imaginary);
  c.imaginary = (this->real * n.imaginary) + (this->imaginary * n.real);
  return c;
}

template <typename T>
complex<T>& complex<T>::operator*(const T& n){
  static complex<T> c(*this);
  c.real *= n;
  c.imaginary *= n;
  return c;
}

template <typename U>
complex<U>& operator*(const int& n, complex<U>& c){
  static complex<U> a(c);
  a.real *= n;
  a.imaginary *= n;
  return a;
}

template <typename T>
complex<T>& complex<T>::operator/(const complex<T>& n){
  static complex<T> c(0,0);
  c.real = ((this->real * n.real) + (this->imaginary * n.imaginary))/(n.real * n.real) + (n.imaginary * n.imaginary);
  c.imaginary = ((this->imaginary * n.real) - (this->real * n.imaginary))/(n.real * n.real) + (n.imaginary * n.imaginary);
  return c;
}

template <typename T>
complex<T>& complex<T>::operator/(const T& n){
  static complex<T> c(*this);
  c.real /= n;
  c.imaginary /= n;
  return c;
}

template <typename T>
complex<T>& complex<T>::operator!(void){
  static complex<T> c(this->real, -1 * this->imaginary);
  return c;
}

template <typename T>
bool complex<T>::operator==(const complex<T>& n){
  return (this->real == n.real) && (this->imaginary == n.imaginary);
}
template <typename T>
bool complex<T>::operator!=(const complex<T>& n){
  return !this->operator==(n);
}

template <typename T>
T& complex<T>::operator[](const int& n){
  return n ? this->imaginary : this->real;
}

template <typename T>
ostream& operator<< (ostream &out, complex<T> &c){
  c.imaginary > 0 ? 
  out << c.real << "+i" << abs(c.imaginary) : out << c.real << "-i" << abs(c.imaginary);
  return out;
}

template <typename T>
istream& operator>> (istream &in, complex<T> &c){
  in >> c.real >> c.imaginary;
  return in;
}

int main(void){

  complex<int> c(3,-3);
  complex<int> d(2,2);
  cout << "c: " << c << "\n";
  cout << "d: " << d << "\n";
  cout << "c+d: " << c+d << "\n";
  cout << "4+c+d: " << 4+c+d << "\n"; 
  cout << "c*2: " << c*2 << "\n";
  cout << "2*c: " << 2*c << "\n";
  cout << "!c: " << !c << "\n";
  cout << "!c[1]: " << !c[1] << "\n";  
  cout << "c[1]: " << c[1] << "\n";
  cout << "c+d: " << c+d << "\n"; 
  cout << "c*d: " << c*d;
  return 0;
}