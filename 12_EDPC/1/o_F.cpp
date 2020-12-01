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

const int MAX_N = 25;
const int mod = 10000007;

int main()
{
    int n; cin >> n;
    int a[n][n];
    rep(i,n){
        rep(j,n) cin >> a[i][j];
    }

    ll dp[(1<<n)];
    rep(s,(1<<n)){
        bitset<MAX_N> S(s);
        int i = S.count();  // 女性の集合のうちでペアができている人数を数えることで、男性のうちペアができている人数を数えることにもなる
        rep(j,n) if(S.test(j+1) && a[i-1][j]==1) dp[s] = (dp[s]+dp[s^(1<<j)])%mod;
    }

    cout << dp[(1<<n)-1] << endl;

}