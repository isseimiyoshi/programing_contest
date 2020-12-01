#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;

  // ここにプログラムを追記
  int sum = 0;
  int size = S.size();
  int n;
  string op;
  for(int i=0; i<size; i++){
      if(i == 0){
          sum += 1;
      }else if(i % 2 == 0){
          if(op == "+"){
              sum += 1;
          }else if(op == "-"){
              sum -= 1;
          }
      }else{
          op = S.at(i);
      }
  }
  cout << sum << endl;
}
