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
    int n; cin >> n;
    int a[n][3];
    rep(i,n) cin >> a[i][0] >> a[i][1] >> a[i][2];

    int dp[n][3];
    rep(i,n) rep(j,3) dp[i][j] = 0;
    dp[0][0] = a[0][0];
    dp[0][1] = a[0][1];
    dp[0][2] = a[0][2];

    for(int i=1; i<n; i++){
        rep(j,3){
            rep(k,3){
                if(j==k) continue;
                dp[i][j] = max(dp[i-1][k]+a[i][j], dp[i][j]);
            }
        }
    }

    int res = 0;
    rep(j,3) res = max(res, dp[n-1][j]);
    cout << res << endl;
}