#include <iostream>
#include "Boolean.h"

using namespace std;

Boolean int_eq(int x, int y){
  return x == y;
}

int main(){
  int n;
  Boolean a;
  Boolean b = a;
  Boolean c = 100;
  Boolean x[8];

  cout << "整数値：　";
  cin >> n;
  x[0] = int_eq(n,5);
  x[1] = (n != 3);
  x[2] = Boolean::False;
  x[3] = 1000;
  x[4] = c == Boolean::True;

  cout << int(a) << endl;
  cout << static_cast<const char*>(b) << endl;
  for(int i=0; i<8; i++){
    cout << x[i] << endl;
  }
}