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
    int n; cin >> n;
    int c[5][n];
    rep(i,5){
        rep(j,n){
            char moji; cin >> moji;
            if(moji == 'R') c[i][j] = 0;
            else if(moji == 'B') c[i][j] = 1;
            else if(moji == 'W') c[i][j] = 2;
            else c[i][j] = -1;
        }
    }

    int dp[n][3];
    rep(i,n) rep(j,3) dp[i][j] = INF;

    rep(i,n){
        rep(j,3){
            int cnt = 0;
            rep(k,5){
                if(c[k][i] != j) cnt++;
            }
            if(i == 0) dp[i][j] = cnt;
            else{
                rep(j2,3){
                    if(j == j2) continue;
                    dp[i][j] = min(dp[i][j], dp[i-1][j2]+cnt);
                }
            }
        }
    }
    int res = INF;
    rep(i,3) res = min(res, dp[n-1][i]);
    cout << res << endl;
}