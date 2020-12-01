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

3
3 5 8
3 2 2
17

*/

int main()
{
    int n; cin >> n;
    int a[n], m[n];
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> m[i];
    int A; cin >> A;

    int dp[A+1];
    rep(i,A+1) dp[i] = -1;
    dp[0] = 0;

    rep(i,n){
        for(int j=0; j<=A; j++){
            if(dp[j] >= 0) dp[j] = m[i];
            else if(j >= a[i] && dp[j-a[i]] > 0) dp[j] = dp[j-a[i]]-1;
            else dp[j] = -1;
        }
    }

    rep(i,A+1) cout << dp[i] << " ";
    cout << endl;

    if(dp[A] >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}