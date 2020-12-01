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

const int MOD = 1000000009;
const int MAX_N = 105, MAX_A = 10010;
int dp[MAX_N][MAX_A];

void init(){
    rep(i,MAX_N) rep(j,MAX_A) dp[i][j] = 0;
}

/*
5
7 5 3 1 8
12

4
4 1 1 1
5

*/

int main()
{
    int n; cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];
    int A; cin >> A;
    init();
    // 動的計画法の初期値：選択する数字の個数がゼロのとき、合計が0の場合は1通り、他は0通りとなる
    rep(i,MAX_N){
        if(i == 0) dp[0][i] = 1;
        else dp[0][i] = 0;
    }
    rep(i,n){
        rep(j,A+1){
            if(j<a[i]) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = dp[i][j-a[i]] + dp[i][j];
        }
    }
    cout << dp[n][A] << endl;
}