#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

/* 
Roll: 20CS8016
Name: Rahul Ranjan  
 */

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


int main (void){

  indent();

  return 0;
}