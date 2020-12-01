#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 100, MAX_W = 10000;
int w[MAX_N], v[MAX_N], n, W;
int dp[MAX_N + 1][MAX_W + 1];   // メモ化テーブル

int rec(int i, int j){
    if(dp[i][j] >= 0){
        return dp[i][j];    // すでに調べたことがあるのならその結果を再利用
    }
    int res;
    if(i == n){
        res = 0;
    }else if(j < w[i]){
        res = rec(i + 1, j);
    }else{
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    }
    // 結果をテーブルに記憶する
    return dp[i][j] = res;
}

void solve(){
    // まだ調べてないことを表す-1でメモ化テーブルを初期化
    memset(dp, -1, sizeof(dp));
    printf("%d\n", rec(0, W));
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