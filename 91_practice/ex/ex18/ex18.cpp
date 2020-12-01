#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A.at(i) >> B.at(i);
    }
    
    // ここにプログラムを追記
    // (ここで"試合結果の表"の2次元配列を宣言)
    vector <char> result(N*N, '-');
    for(int i=0; i<M; i++){
        result[N*(A[i]-1)+B[i]-1] = 'o';
        result[N*(B[i]-1)+A[i]-1] = 'x';
    }
    for(int i=0; i<N*N; i++){
        cout << result[i];
        if((i+1) % N == 0) cout << endl;
        else cout << " ";
    }
}