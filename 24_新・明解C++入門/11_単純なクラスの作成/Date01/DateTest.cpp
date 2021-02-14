#include <iostream>
#include "Date.h"

using namespace std;

int main(){
  Date a[3];
  a[2] = Date(2999,12,31);

  cout << a[0] << endl;
  cout << a[1] << endl;
  cout << a[2].preceding_day() << endl;
  return 0;
}