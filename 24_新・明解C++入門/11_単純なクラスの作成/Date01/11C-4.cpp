#include <iostream>

using namespace std;

class Int {
  int v;
public:
  Int(int val) : v(val) { cout << v << endl;}
};

class ABC {
  Int a,b,c;
public:
  ABC(int aa, int bb, int cc) : c(cc), b(bb), a(aa) {}
};


int main(){
  ABC x(1,2,3);
}