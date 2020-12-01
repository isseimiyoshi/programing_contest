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

const int MAX_S = 100100;

int main()
{
    int n; cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];

    ll dp[n];
    rep(i,n) dp[i] = 0;
    dp[0] = 1000;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            ll res = (dp[j]/a[j])*a[i] + dp[j]%a[j];
            dp[i] = max(dp[i], res);
        }
        dp[i] = max(dp[i], dp[i-1]);
    }

    cout << dp[n-1] << endl;
}