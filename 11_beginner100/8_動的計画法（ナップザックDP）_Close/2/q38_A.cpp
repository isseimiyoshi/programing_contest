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
    int q; cin >> q;
    rep(_,q){
        string x, y; cin >> x >> y;
        int xs = (int)x.size();
        int ys = (int)y.size();

        int dp[ys+1][xs+1];
        rep(i,ys+1) rep(j,xs+1) dp[i][j] = 0;

        rep(i,ys){
            rep(j,xs){
                if(x[j] == y[i]){
                    dp[i+1][j+1] = max(dp[i+1][j], max(dp[i][j]+1, dp[i][j+1]));
                }else{
                    dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        cout << dp[ys][xs] << endl;
    }
}