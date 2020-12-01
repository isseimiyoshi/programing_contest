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
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();

    int dp[3][n][10];
    rep(i,3) rep(j,n) rep(l,10) dp[i][j][l] = 0;

    rep(i,3) rep(j,n) rep(l,10){
        if(i == 0){
            if(j == 0){
                if(l == 0) dp[i][j][l] = 0;
                else dp[i][j][l] = 1;
            }else{
                if(l == 0) for(int l2=1; l2<10; l2++) dp[i][j][l] += dp[i][j-1][l2];
                else dp[i][j][l] = dp[i][j-1][0]+1;
            }
        }else{
            if(i>j) continue;
            if(l == 0) for(int l2=1; l2<10; l2++) dp[i][j][l] += dp[i][j-1][l2];
            else{
                rep(l2,10) dp[i][j][l] += dp[i-1][j-1][l2];
            }
        }
    }
    /*
    rep(i,3) rep(j,n) rep(l,10){
        if(l == 0) continue;
        dp[i][j][l] = dp[i][j][l] + dp[i][j][l-1];
    }
    */

    rep(i,n){
        int si = s[i]-'0';

    }

    rep(i,10){
        rep(j,n){
            cout << dp[0][j][i] << " ";
        }cout << endl;
    }
}