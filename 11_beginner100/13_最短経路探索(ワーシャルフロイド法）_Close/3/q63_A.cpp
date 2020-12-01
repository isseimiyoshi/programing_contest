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
    ll d[n][n];
    rep(i,n) rep(j,n) cin >> d[i][j];

    rep(k,n){
        rep(i,n){
            rep(j,n){
                if(d[i][j] > d[i][k]+d[k][j]){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    rep(k,n){
        rep(i,n){
            if(i == k) continue;
            rep(j,n){
                if(j == k || i == j) continue;
                if(d[i][j] == d[i][k]+d[k][j]){
                    d[i][j] = INF;
                }
            }
        }
    }
    ll ans = 0;
    rep(i,n){
        for(int j=i+1; j<n; j++){
            if(d[i][j] != INF) ans += d[i][j];
        }
    }
    cout << ans << endl;
}