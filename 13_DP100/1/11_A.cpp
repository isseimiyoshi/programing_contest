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
    int p[n];
    int sump = 0;
    rep(i,n){
        cin >> p[i];
        sump += p[i];
    }

    int dp[n+1][sump+1];
    rep(i,n+1) rep(j,sump+1) dp[i][j] = 0;
    dp[0][0] = 1;

    rep(i,n){
        rep(j,sump+1){
            if(j<p[i]) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = max(dp[i][j], dp[i][j-p[i]]);
        }
    }

    int ans = 0;
    rep(j,sump+1){
        if(dp[n][j]>0) ans++;
    }
    cout << ans << endl;
}