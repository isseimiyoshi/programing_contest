#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const ll INF = 100010010000;

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
    int n, W; cin >> n >> W;
    ll w[n], v[n];
    rep(i,n) cin >> w[i] >> v[i];

    int max_v = 100100;

    ll dp[n+1][max_v];
    rep(i,n+1) rep(j,max_v) dp[i][j] = INF;
    dp[0][0] = 0;

    rep(i,n){
        rep(j,max_v){
            if(j-v[i]>=0) dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i]);
            else dp[i+1][j] = dp[i][j];
        }
    }

    int res = 0;
    for(int j=max_v-1; j>=0; j--){
        if(dp[n][j]<=W){
            res = j;
            break;
        }
    }
    

    cout << res << endl;
}