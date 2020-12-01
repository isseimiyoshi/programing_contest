#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;

  // ここにプログラムを追記
  for(int i=0; i<N; i++){
    // 変数の定義
    string op;
    int a;
    cin >> op >> a;
    if(op == "+"){
      A += a;
    }else if(op == "-"){
      A -= a;
    }else if(op == "*"){
      A *= a;
    }else if(op == "/"){
      if(a == 0){
        cout << "error" << endl;
        break;
      }else{
        A /= a;
      }
    }
    cout << i+1 << ":" << A << endl;
  }
}
