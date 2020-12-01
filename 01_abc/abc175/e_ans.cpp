#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

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

#define chmax(x,y) x = max(x,y)

int a[3005][3005];
ll dp[3005][3005][4];

int main()
{
    int R, C, n;
    cin >> R >> C >> n;

    rep(i,n){
        int r,c,v; cin >> r >> c >> v;
        a[r-1][c-1] = v;
    }

    rep(i,R) rep(j,C) {
        for(int k=2; k>=0; k--){
            chmax(dp[i][j][k+1], dp[i][j][k]+a[i][j]);
        }
        rep(k,4){
            chmax(dp[i+1][j][0], dp[i][j][k]);
            chmax(dp[i][j+1][k], dp[i][j][k]);
        }
    }

    ll ans = 0;
    rep(k,4) chmax(ans, dp[R-1][C-1][k]);
    cout << ans << endl;

    return 0;
}