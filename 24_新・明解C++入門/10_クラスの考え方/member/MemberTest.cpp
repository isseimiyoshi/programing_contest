#include <iostream>
#include "Member.h"

using namespace std;

void print(Member* p){
  p->print();
}

int main(){
  Member kaneko("kaneko",15,4);
  kaneko.set_rank(kaneko.get_rank()+1);
  print(&kaneko);
  return 0;
}