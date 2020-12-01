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
    int q; cin >> q;
    rep(_,q){
        string X, Y; cin >> X >> Y;
        int n = X.length();
        int m = Y.length();
        int dp[n+1][m+1];
        rep(i,n+1) dp[i][0] = 0;
        rep(i,m+1) dp[0][i] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(X[i] == Y[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        cout << dp[n][m] << endl;
    }
}