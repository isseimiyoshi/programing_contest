#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

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

4 4
abcd
becd

*/

const int MAX_N = 1050, MAX_M = 1050;

int dp[MAX_N][MAX_M];   // n,mの最大値よりMAX_NおよびMAX_Mを50も多く取っているので+1が必要ない

int main()
{
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    rep(i,n){
        rep(j,m){
            if(s[i] == t[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    printf("%d\n", dp[n][m]);
}