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

/*
input 

5
7 5 3 1 8
12

2
7 5
6

*/

const int INF = 1000100100;

int main()
{
    int n; cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];
    int A; cin >> A;

    int dp[n+1][A+1];
    rep(i,n+1) rep(j,A+1) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,n){
        for(int j=0; j<=A; j++){
            if(j == a[i]) dp[i+1][j] = 1;
            else if(j < a[i]) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = min(dp[i][j], dp[i][j-a[i]]+1);
        }
    }

    if(dp[n][A] > 1000) cout << -1 << endl;
    else cout << dp[n][A] << endl;
}