#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A';

/*
string s = "abcdefg"
s.substr(4) "efg"
s.substr(0,3) "abc"
s.substr(2,4) "cdef"

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

const int MAX_N = 105;

int v[MAX_N], w[MAX_N];
int dp[MAX_N][10100];

int main()
{
    int N, W; cin >> N >> W;
    rep(i,N) cin >> v[i] >> w[i];
    // DP初期条件
    rep(j,W) dp[0][j] = 0;
    rep(i,N){
        for(int j=0; j<=W; j++){
            if(j>=w[i]) dp[i+1][j] = max(dp[i][j-w[i]] + v[i], dp[i][j]);
            else dp[i+1][j] = dp[i][j];
        }
    }
    cout << dp[N][W] << endl;
}