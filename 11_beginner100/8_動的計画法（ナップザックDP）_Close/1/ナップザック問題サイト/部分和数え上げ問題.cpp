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

*/

const int MOD = 1000000009;

int main()
{
    int n; cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];
    int A; cin >> A;

    int dp[n+1][A+1];
    rep(i,n+1) rep(j,A+1) dp[i][j] = 0;
    dp[0][0] = 1;

    rep(i,n){
        for(int j=0; j<=A; j++){
            (dp[i+1][j] += dp[i][j]) %= MOD;
            if(j >= a[i]) (dp[i+1][j] += dp[i][j-a[i]]) %= MOD;
        }
    } 

    cout << dp[n][A] << endl;
}