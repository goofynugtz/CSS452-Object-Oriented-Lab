#include <iostream>
using namespace std;

class tool {
protected:
  double strength;
  char type;
public:
  char getType();
  double getStrength();
  void setStrength(const int&);
};
char tool::getType(){
  return this->type;
}
double tool::getStrength(){
  return this->strength;
}
void tool::setStrength(const int& s){
  this->strength = s;
}


class rock: public tool {
public:
  rock(const int&);
  bool fight(tool&);
};
rock::rock(const int& str){
  this->setStrength(str);
  this->type = 'r';
}
bool rock::fight(tool& t){
  if (t.getType() == 'p')
    return this->strength*0.5 > t.getStrength();
  else if (t.getType() == 's')
    return this->strength*2 > t.getStrength();
  return false;
}


class paper: public tool {
public:
  paper(const int&);
  bool fight(tool&);
};
paper::paper(const int& str){
  this->setStrength(str);
  this->type = 'p';
}
bool paper::fight(tool& t){
  if (t.getType() == 's')
    return this->strength*0.5 > t.getStrength();
  else if (t.getType() == 'r')
    return this->strength*2 > t.getStrength();
  return false;
}


class scissors: public tool {
public:
  scissors(const int&);
  bool fight(tool&);
};
scissors::scissors(const int& str){
  this->setStrength(str);
  this->type = 's';
}
bool scissors::fight(tool& t){
  if (t.getType() == 'r')
    return this->strength*0.5 > t.getStrength();
  else if (t.getType() == 'p')
    return this->strength*2 > t.getStrength();
  return false;
}


int main(void){
  scissors s1(5);
  paper p1(7);
  rock r1(15);
  cout << s1.fight(p1) << p1.fight(s1) << endl;
  cout << p1.fight(r1) << r1.fight(p1) << endl;
  cout << r1.fight(s1) << s1.fight(r1) << endl;

  return 0;
}