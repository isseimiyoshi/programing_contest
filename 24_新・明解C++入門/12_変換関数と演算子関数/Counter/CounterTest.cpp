#include <iostream>
#include "Counter.h"

using namespace std;

int main(){
  int no;
  Counter x;

  cout << x.value() << endl;

  for(int i=0; i<10; i++){
    x.increment();
    cout << x.value() << endl;
  }

  for(int i=0; i<5; i++){
    x.decrement();
    cout << x.value() << endl;
  }
}