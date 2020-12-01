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
    int n, k; cin >> n >> k;
    int a[n];
    rep(i,n) cin >> a[i];

    int dp[k+1];
    rep(i,k+1) dp[i] = 0;

    for(int i=1; i<=k; i++){
        rep(j,n){
            if(i-a[j]>=0 && dp[i-a[j]] == 0) dp[i] = 1;
        }
    }
    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;

}