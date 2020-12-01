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

const int INF = 1000100100;

int main()
{
    int n, m; cin >> n >> m;
    int d[n][n];
    rep(i,n) rep(j,n){
        if(i == j) d[i][j] = 0;
        else d[i][j] = INF;
    }
    rep(i,m){
        int ai, bi, t; cin >> ai >> bi >> t; --ai, --bi;
        d[ai][bi] = t;
        d[bi][ai] = t;
    }

    rep(k,n){
        rep(i,n){
            if(d[i][k] == INF) continue;
            rep(j,n){
                if(d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }

    int ans = INF;
    rep(i,n){
        int res = -1;
        rep(j,n){
            if(i == j) continue;
            res = max(res, d[i][j]);
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
}