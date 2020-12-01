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
    int ng[301];
    rep(i,301) ng[i] = 0;

    rep(_,3){
        int ngi; cin >> ngi;
        ng[ngi] = 1;
    }

    if(ng[n] == 1){
        cout << "NO" << endl;
        return 0;
    }

    int dp[n+1];
    rep(i,n+1) dp[i] = INF;
    dp[n] = 0;

    for(int i=n; i>0; i--){
        rep(j,3){
            if(i-j-1 < 0) continue;
            if(ng[i-j-1]) continue;

            dp[i-j-1] = min(dp[i-j-1], dp[i]+1);
        }
    }

    if(dp[0]<=100) cout << "YES" << endl;
    else cout << "NO" << endl;
}