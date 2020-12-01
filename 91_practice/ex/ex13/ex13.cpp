#include <bits/stdc++.h>
using namespace std;

int main() {
  // 読み込む点数の人数
  int N;
  cin >> N;

  int sum = 0;
  vector <int> points(N, 0);
  for(int i=0; i<N; i++){
    int point;
    cin >> point;
    points[i] = point;
    sum += point;
  }
  // 平均点を求める
  int avg = sum / N;
  for(int j=0; j<points.size(); j++){
    // 平均点と読み込んだ点数を比較して出力のやり方を変える
    if(points[j] >= avg){
        cout << points[j]-avg << endl;
    }else{
      cout << avg-points[j] << endl;
    }
  }
  // cout << avg << endl;
}
