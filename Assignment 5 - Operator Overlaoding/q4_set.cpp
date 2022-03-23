#include <iostream>
using namespace std;

template <typename T>
class set {
private:
  T * arr;
  int size;
  int current;
public:
  set(const int& = 100);
  set(const set&);
  set& push(const T&);
  bool count(const T&);
  set& operator+(const set&);
  set& operator-(const set&);
  set& operator*(const set&);
  bool operator<(set&);
  bool operator<=(set&);
  bool operator>(const set&);
  bool operator>=(const set&);
  bool operator==(set&);
  bool operator!=(const set&);

  template <typename U>
  friend ostream& operator<<(ostream&, const set<U>&);
};

template <typename T>
set<T>::set(const int& size){
  arr = new T[size];
  this->size = size;
  this->current = 0;
}

template <typename T>
set<T>::set(const set& s){
  this->size = s.size;
  this->arr = new T[s.size];
  for (int i = 0; i < s.size; i++)
    this->arr[i] = s.arr[i];
  this->current = s.current;
}

template <typename T>
set<T>& set<T>::push(const T& n){
  this->arr[current++] = n;
  return *this;
}

template <typename T>
bool set<T>::count(const T& n){
  for (int i = 0; i < this->current; i++)
    if (this->arr[i] == n)
      return 1;
  return 0;
}

template <typename T>
set<T>& set<T>::operator+(const set& s){
  static set r(this->size + s.size);
  int i;
  for (i = 0; i < this->current; i++){
    r.push(this->arr[i]);
  }
  for (int j = 0; j < s.current; j++){
    r.push(s.arr[j]);
  }
  return r;
}

template <typename T>
set<T>& set<T>::operator-(const set& s){
  static set r(this->size);
  for (int i = 0; i < s.current; i++){
    if (!this->count(s.arr[i]))
      r.push(s.arr[i]);
    else 
      continue;
  }
  return r;
}

template <typename T>
set<T>& set<T>::operator*(const set& s){
  static set r(this->size);
  for (int i = 0; i < this->current; i++){
    if (this->count(s.arr[i]))
      r.push(s.arr[i]);
    else 
      continue;
  }
  return r;
}

template <typename T>
bool set<T>::operator<(set& superset){
  if (superset.current < this->current)
    return 0;
  for (int i = 0; i < this->current; i++){
    // Below condition stands for if element in 'this' subset is not present in 'superset'.
    // Then 'this' set is not a subset of parameter;
    if (!superset.count(this->arr[i]))
      return 0;
  }
  return 1;
}

template <typename T>
bool set<T>::operator<=(set& superset){
  if (superset.current < this->current)
    return 0;
  for (int i = 0; i < this->current; i++){
    // Below condition stands for if element in 'this' subset is not present in 'superset'.
    // Then 'this' set is not a subset of parameter;
    if (!superset.count(this->arr[i]))
      return 0;
  }
  return 1;
}

template <typename T>
bool set<T>::operator>(const set& subset){
  if (subset.current > this->current)
    return 0;
  for (int i = 0; i < subset.current; i++){
    // Below condition stands for if any element in 'subset' is not present 
    // in 'this' superset. Then 'this' set is not a superset;
    if (!this->count(subset.arr[i]))
      return 0;
  }
  return 1;
}

template <typename T>
bool set<T>::operator>=(const set& subset){
  if (subset.current > this->current)
    return 0;
  for (int i = 0; i < subset.current; i++){
    // Below condition stands for if any element in 'subset' is not present 
    // in 'this' superset. Then 'this' set is not a superset;
    if (!this->count(subset.arr[i]))
      return 0;
  }
  return 1;
}

template <typename T>
bool set<T>::operator==(set& s){
  if (this->current != s.current)
    return 0;
  for (int i = 0; i < this->current; i++){
    if (!s.count(this->arr[i]))
      return 0;
  }
  return 1;
}

template <typename T>
bool set<T>::operator!=(const set& s){
  return (*this == s) ? 0 : 1;
}

template <typename T>
ostream& operator<<(ostream& out, const set<T>& s){
  for (int i = 0; i < s.current; i++){
    out << s.arr[i] << " ";
  }
  out << "\n";
  return out;
}

int main(void){

  set<int> s;
  s.push(5).push(10).push(15);
  s.push(20).push(25).push(30);

  set<int> t;
  t.push(10).push(20).push(30);

  set<int> u;
  u.push(7).push(8).push(9).push(10);

  cout << "s: " << s;
  cout << "t: " << t;
  cout << "u: " << u;
  cout << "s union u: " << s+t;
  cout << "s difference u: " << s-u;
  cout << "s intersetion t: " << s*t;

  cout << "\n>> Below 1 stands for true and 0 for false.\n";
  cout << "s is superset t? " << (s >= t) << "\n";
  cout << "s is superset u? " << (s >= u) << "\n";
  cout << "t is subset of s? " << (t < s) << "\n";
  cout << "u is subset of s? " << (u < s) << "\n";

  return 0;
}