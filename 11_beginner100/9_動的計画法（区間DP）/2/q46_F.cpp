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
    int p[n+1];
    rep(i,n){
        cin >> p[i] >> p[i+1];
    }

    int dp[n+1][n+1];

    rep(i,n+1) dp[i][i] = 0;

    for(int l=2; l<=n; l++){ // l　選択する行列の個数
        rep(i,n-l+1){
            int j=i+l-1;
            dp[i][j] = INF;
            for(int k=i; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j]);
            }
        }
    }
    cout << dp[0][n] << endl;
}