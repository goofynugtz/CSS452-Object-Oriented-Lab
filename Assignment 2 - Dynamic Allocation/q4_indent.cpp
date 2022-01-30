#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#define BUFFER_SIZE 1000
using namespace std;

void indent(){

  string readBuffer;
  ifstream reader("unindented.cpp");
  ofstream writer("indented.cpp");

  int tab = 0;
  int tabWidth = 2;
  while (getline(reader, readBuffer)){

    if (readBuffer.find('{') != string::npos){
      writer << setw(tab * tabWidth) << "" << readBuffer << "\n";
      tab++;
    }

    else if (readBuffer.find('}') != string::npos){
      tab--;
      writer << setw(tab * tabWidth) << "" << readBuffer << "\n";
    }

    else {
      writer << setw(tab * tabWidth) << "" << readBuffer << "\n";
    }
  }
}

void singleLine(){

  string readBuffer;
  ifstream reader("indented.cpp");
  ofstream writer("singleline.cpp");

  while (getline(reader, readBuffer)){
    writer << readBuffer;
  }
}

int main (void){

  indent();
  singleLine();

  return 0;
}