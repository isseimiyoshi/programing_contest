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

3
7 5 3
10

2
9 7
6
*/

int main()
{
    // データ読み込み
    int n; cin >> n;
    int a[n]; rep(i,n) cin >> a[i];
    int A; cin >> A;
    
    bool dp[n][A+1];
    // dp初期値：選ぶ数字の個数が0の場合、合計0のみ実現可能なのでTrueとなる
    rep(i,n) rep(ai, A+1) dp[i][ai] = false;
    dp[0][0] = false;

    rep(i,n){
        rep(ai, A+1){
            
            if(ai>=a[i]){
                if(dp[i][ai-a[i]] || dp[i][a[i]]) dp[i+1][ai] = true;
            }
            else dp[i+1][ai] = dp[i][ai];
        }
    }
    if(dp[n][A]) cout << "Yes" << endl;
    else cout << "No" << endl;
}