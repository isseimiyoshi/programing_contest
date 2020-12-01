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

const int INF = 1000100100;

int main()
{
    int n, m; cin >> n >> m;
    int c[m];
    rep(i,m) cin >> c[i];
    int dp[n+1];
    rep(i,n+1) dp[i] = INF;
    // 初期化する、合計金額が0円のときはコインの最小枚数は0枚になる
    dp[0] = 0;
    rep(i,m){
        for(int j=c[i]; j<=n; j++){
            dp[j] = min(dp[j], dp[j-c[i]]+1);
        }
    }
    cout << dp[n] << endl;
}