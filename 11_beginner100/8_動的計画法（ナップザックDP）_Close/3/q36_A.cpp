#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const int INF = 1000100100;

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

int main()
{
    int N, W; cin >> N >> W;
    int v[N], w[N];
    rep(i,N) cin >> v[i] >> w[i];

    int dp[N+1][W+1];
    rep(i,W+1) dp[0][i] = 0;

    rep(i,N){
        rep(j,W+1){
            if(j<w[i]) dp[i+1][j] = dp[i][j];
            else{
                dp[i+1][j] = max(dp[i][j], max(dp[i][j-w[i]]+v[i], dp[i+1][j-w[i]]+v[i]));  // 同行でも比較を行うことによって、同じ品物を複数選択することを表現している
            }
        }
    }

    cout << dp[N][W] << endl;
}