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
    int n; cin >> n;
    double p[n];
    rep(i,n) cin >> p[i];

    double dp[n+1][n+1];
    rep(i,n+1) rep(j,n+1) dp[i][j] = 0;
    dp[0][0] = 1;

    rep(i,n){
        rep(j,n+1){
            if(j>i+1) continue;
            dp[i+1][j] = dp[i][j-1] * p[i] + dp[i][j] * (1.0-p[i]);
            dp[i+1][j] = dp[i][j] * (1.0-p[i]);
        }
    }

    rep(i,n+1){
        rep(j,n+1){
            cout << dp[i][j] << " ";
        }cout << endl;
    }

    double ans = 0.0;
    rep(j,n+1){
        if((n/2+1) <= j) ans += dp[n][j];
    }

    printf("%.6f\n", ans);
}