#include <iostream>
using namespace std;

template <typename T>
struct node {
  public:
    T data;
    node * next;
    node(T, node * = NULL);
    template <typename U>
    friend istream& operator>>(istream&, node<U>&);
    template <typename U>
    friend ostream& operator<< (ostream&, const node<U>&);
    ~node();
};

template <typename T>
node<T>::node(T n, node * next){
  this->data = n;
  this->next = next;
};

template <typename T>
node<T>::~node(){
}

template <typename T>
istream& operator>>(istream& in, node<T>& n){
  T data; in >> data;
  n.data = data;
  n.next = NULL;
  return in;
}

template <typename T>
ostream& operator<<(ostream& out, node<T>& n){
  out << "\n>> Node: " << n.data << " at address: " << &n.data << "\n";
  return out;
}

int main(void){
  node<int> a(23);
  cout << a;
  return 0;
}