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
    int h, n; cin >> h >> n;
    int a[n], b[n];
    rep(i,n) cin >> a[i] >> b[i];

    int dp[n+1][h+1];
    rep(i,n+1) rep(j,h+1) dp[i][j] = INF;
    dp[0][0] = 0;

    rep(i,n){
        rep(j,h+1){
            if(j<a[i]) dp[i+1][j] = min(dp[i][j], min(dp[i+1][0]+b[i], dp[i][0]+b[i]));
            else{
                dp[i+1][j] = min(dp[i][j], min(dp[i+1][j-a[i]]+b[i], dp[i][j-a[i]]+b[i]));
            }
        }
    }

    cout << dp[n][h] << endl;
}