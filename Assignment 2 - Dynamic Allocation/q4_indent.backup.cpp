#include <iostream>
// #include <string>
#include <cstring>
#define BUFFER_SIZE 1000
using namespace std;

int main (int argc, char *argv[]){
  for (int file = 0; file < argc; file++){
    FILE *reader, *writer;
    reader = fopen(argv[file],"r");
    writer = fopen("indented.cpp","w");

    // char readBuffer[BUFFER_SIZE]; char writeBuffer[BUFFER_SIZE];
    string readBuffer, writeBuffer;
    // memset(readBuffer, '\0', BUFFER_SIZE);

    int indent_level = 0;

    while (fgets(readBuffer, BUFFER_SIZE, reader)){

      memset(writeBuffer, '\0', BUFFER_SIZE);   
      bool blockStart = 0;    
      for (int i = 0; i < BUFFER_SIZE; i++){    
        if (readBuffer[i] == '{'){
          indent_level++;
          blockStart = 1;
          break;
        }   
        else if (readBuffer[i] == '}'){
          indent_level--;
          break;
        }
      }   
      
      if (blockStart){
        for (int i = 0; i < indent_level - 1; i++){
          writeBuffer[i] = '\t';
        }
      } 
      else {
        for (int i = 0; i < indent_level; i++){
          writeBuffer[i] = '\t';
        }
      }
      strcat(writeBuffer, readBuffer);    
      fprintf(writer, writeBuffer);

    }   
    fclose(reader);
    fclose(writer);
  }
  
  return 0;
}