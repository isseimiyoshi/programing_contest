#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// コインの金額
const int V[6] = {1, 5, 10, 50, 100, 500};

// 入力
int C[6]; // C[0] = C_1; C[1] = C_5; C[2] = C_10; C[3] = C_50; C[4] = C_100; C[5] = C_500;
int A;

void solve(){
    int ans = 0;
    for(int i=5; i>=0; i--){
        int t = min(A / V[i], C[i]);    // コインを使う枚数
        A -= t*V[i];
        ans += t;
    }
    printf("%d\n", ans);
}

/*
input1

3 2 1 3 0 2
620

*/

int main()
{
    for(int i=0; i<6; i++){
        cin >> C[i];
    }
    cin >> A;
    solve();
}