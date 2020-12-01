#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
using P = pair<ll, ll>;

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

const int INF = 1000100100;


int main()
{
    int n, m; cin >> n >> m;
    int d[n];
    rep(i,n) cin >> d[i];
    int c[m];
    rep(i,m) cin >> c[i];

    int dp[m+1][n+1];
    rep(i,m+1) rep(j,n+1) dp[i][j] = INF;

    rep(i,m+1) dp[i][0] = 0;

    rep(i,m){
        rep(j,n){
            if(dp[i][j] == INF){
                continue;
            }
            dp[i+1][j+1] = min(dp[i][j]+d[j]*c[i], dp[i][j+1]);
        }
    }
    /*
    rep(i,m+1){
        rep(j,n+1){
            cout << dp[i][j] << " ";
        }cout << endl;
    }
    */

    cout << dp[m][n] << endl;
}