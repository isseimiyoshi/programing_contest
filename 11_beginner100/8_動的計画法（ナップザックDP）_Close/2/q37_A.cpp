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
    int c[m];
    rep(i,m) cin >> c[i];
    sort(c, c+m);

    int dp[m][n+1];
    rep(i,m) rep(j,n+1) dp[i][j] = INF;

    rep(i,m){
        rep(j,n+1){
            if(c[i] == 1) dp[i][j] = j;
            else{
                if(j<c[i]) dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-c[i]]+1, dp[i][j-c[i]]+1));
                }
            }
        }
    }

    cout << dp[m-1][n] << endl;
}