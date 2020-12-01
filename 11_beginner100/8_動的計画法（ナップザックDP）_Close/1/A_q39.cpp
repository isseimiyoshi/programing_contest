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

int main()
{
    int n; cin >> n;
    ll dp[n][21];
    int a[n-1];
    rep(i,n-1) cin >> a[i];
    int A; cin >> A;

    rep(j,n) rep(i,21) dp[j][i] = 0;
    dp[0][0] = 1;

    rep(i,n-1){
        for(int j=0; j<=20; j++){
            if(dp[i][j] > 0){
                if(j-a[i] >= 0) dp[i+1][j-a[i]] += dp[i][j];
                if(j+a[i] <= 20) dp[i+1][j+a[i]] += dp[i][j];
            }
        }
    }
    cout << dp[n-1][A] << endl;
}