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
    int a[n], b[n], c[n];
    rep(i,n) cin >> a[i] >> b[i] >> c[i];

    int dp[n][3];
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    for(int i=1; i<n; i++){
        rep(j,3){
            if(j == 0) dp[i][j] = max(dp[i-1][1]+a[i], dp[i-1][2]+a[i]);
            else if(j == 1) dp[i][j] = max(dp[i-1][0]+b[i], dp[i-1][2]+b[i]);
            else dp[i][j] = max(dp[i-1][0]+c[i], dp[i-1][1]+c[i]);
        }
    }
    int ans = 0;
    rep(j,3){
        ans = max(ans, dp[n-1][j]);
    }
    cout << ans << endl;
}