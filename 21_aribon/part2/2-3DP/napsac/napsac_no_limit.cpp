#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 100, MAX_W = 10000;
int w[MAX_N], v[MAX_N], n, W;
int dp[MAX_N + 1][MAX_W + 1];   // メモ化テーブル

void solve(){
    for(int i=0; i<n; i++){
        for(int j=0; j<=W; j++){
            for(int k; k*w[i] <= j; k++){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-k*w[i]]+k*v[i]);
            }
        }
    }
    printf("%d\n", dp[n][W]);
}

/*
input

3
3 4
4 5
2 3
7

*/

int main()
{
    cin >> n;
    for(int i=0; i<n; i++){
        int w_in, v_in;
        cin >> w_in >> v_in;
        w[i] = w_in; v[i] = v_in;
    }
    cin >> W;
    solve();
}