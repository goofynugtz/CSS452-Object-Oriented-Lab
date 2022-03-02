#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
using namespace std;

class graph {
  private:
    List<int> * adjacency_list;
    bool * visited;
    // stack<int> * s;
    int nodes;

  public:
    graph(int);
    ~graph();
    graph &makeEdge(const int&, const int&, const int& = 1);
    graph &makeSymmetricEdge(const int&, const int&, const int& = 1);
    graph &deleteEdge(const int&, const int&);
    void display();
    void dfs(const int&);
};

graph::graph(int n){
  // WARN: Node indexes are starting from index 1.
  nodes = n;
  adjacency_list = new List<int>[n+1];
  visited = new bool[n];
}

graph::~graph(){
  delete[] adjacency_list;
}

graph &graph::makeEdge(const int &from, const int &to, const int &weight){
    adjacency_list[from].insertBegining(to, weight);
  return (*this);
}

graph &graph::makeSymmetricEdge(const int &from, const int &to, const int &weight){
    adjacency_list[from].insertBegining(to, weight);
    adjacency_list[to].insertBegining(from, weight);
  return (*this);
}

graph &graph::deleteEdge(const int &from, const int &to){
  if (adjacency_list[from].search(to)) // If it returns a non-zero index then
    adjacency_list[from].deleteNode(adjacency_list[from].search(to));
  else 
    cout << "Not found in Table\n";
  return (*this);
}

void graph::display(){
  for (int i = 1; i < nodes; i++){
    cout << char(192) << char(196) << "[" << i << "] -> ";
    cout << adjacency_list[i] << char(179) << "\n";
  }
}

void graph::dfs(const int &n){
  visited[n] = true;
  cout << n << " ";
  int size = adjacency_list[n].getSize();
  node<int> * ptr = adjacency_list[n].getHead();
  for (int i = 0; i < size; i++){
    if (!visited[ptr->data])
      dfs(ptr->data);
    ptr = ptr->next;
  }
}

int main(void){

  graph g(5);
  g.makeSymmetricEdge(1,3, 10);
  g.makeSymmetricEdge(1,2, 5);
  g.makeSymmetricEdge(4,2, 15);
  g.makeSymmetricEdge(3,5, 15);
  cout << "\n";
  g.display();
  cout << "\n";
  g.dfs(5);

  return 0;
}