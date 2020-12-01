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


int main()
{
    int n; cin >> n;
    int c[n-1];
    rep(i,n-1) cin >> c[i];
    ll res; cin >> res;

    ll dp[n][21];
    rep(i,n) rep(j,21) dp[i][j] = 0;
    dp[1][c[0]] = 1;

    for(int i=1; i<n-1; i++){
        rep(j,21){
            if(j-c[i] >= 0) dp[i+1][j] += dp[i][j-c[i]];
            if(j+c[i] <= 20) dp[i+1][j] += dp[i][j+c[i]];
        }
    }
    cout << dp[n-1][res] << endl;
}