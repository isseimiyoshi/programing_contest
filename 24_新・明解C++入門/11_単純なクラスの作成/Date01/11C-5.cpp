#include <iostream>

using namespace std;

#define DEBUG 1

int main(){
  int a = 5;
  int x = 7;

#if DEBUG == 0
  a = x;
#endif

  cout << "a is " << a << endl;
  return 0;
}