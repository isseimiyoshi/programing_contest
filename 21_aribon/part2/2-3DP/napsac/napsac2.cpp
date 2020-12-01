#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 100, MAX_W = 10000;
int w[MAX_N], v[MAX_N], n, W;
int dp[MAX_N + 1][MAX_W + 1];   // メモ化テーブル


void solve(){
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<=W; j++){
            if(j<w[i]){
                dp[i][j] = dp[i+1][j];
            }else{
                dp[i][j] = max(dp[i+1][j], dp[i+1][j-w[i]] + v[i]);
            }
        }
    }
    printf("%d\n", dp[0][W];
}

/*
input

4
2 3
1 2
3 4
2 2
5
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