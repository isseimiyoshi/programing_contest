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

ll dp[105][100005];

void init(){
    rep(i,105){
        rep(j,100005) dp[i][j] = INF;
    }
}

int main()
{
    ll n, W; cin >> n >> W;
    ll w[n], v[n];
    rep(i,n) cin >> w[i] >> v[i];

    ll sumv = 0;
    rep(i,n) sumv += v[i];

    init();
    rep(i,n+1) dp[i][0] = 0;

    rep(i,n) rep(j,sumv+1){
        dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i]);
    }
    ll maxv = -1;
    for(ll j=0; j<=sumv; j++){
        if(dp[n][j]<=W) maxv = max(maxv, j);
    }
    // cout << dp[n][140] << endl;
    cout << maxv << endl;
}