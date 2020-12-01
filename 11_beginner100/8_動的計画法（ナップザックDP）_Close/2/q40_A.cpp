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
    int n, k; cin >> n >> k;

    int fix[n];
    rep(i,n) fix[i] = -1;
    rep(_,k){
        int day, pas; cin >> day >> pas; day--, pas--;
        fix[day] = pas;
    }

    ll dp[n][3][2];   // 1次元目：パスタの種類、1次元目：メニューを決める日数、1次元目：何日連続でそのパスタが続いているか
    rep(i,n) rep(j,3) rep(l,2) dp[i][j][l] = 0;

    if(fix[0] == -1) rep(j,3) dp[0][j][0] = 1;
    else dp[0][fix[0]][0] = 1;

    for(int i=1; i<n; i++){
        rep(j,3){
            rep(l,2){
                rep(j2,3){
                    if(fix[i] == -1 || fix[i] == j){
                        if(l == 0){
                            if(j == j2) dp[i][j][l+1] += dp[i-1][j2][l];
                            else dp[i][j][l] += dp[i-1][j2][l];
                        }else if(l == 1){
                            if(j == j2) continue;
                            else dp[i][j][l-1] += dp[i-1][j2][l];
                        }
                    }else{
                        continue;
                    }
                }
                dp[i][j][l] %= 10000;
            }
        }
    }

    ll res = 0;
    rep(j,3) rep(l,2){
        res += dp[n-1][j][l];
        res %= 10000;
    }
    cout << res << endl;
}