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
    int h, w; cin >> h >> w;
    int d[10][10];
    // rep(i,10) rep(j,10) d[i][j] = INF;
    rep(i,10){
        rep(j,10){
            cin >> d[i][j];
        }
    }

    rep(k,10){
        rep(i,10){
            rep(j,10){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }


    int ans = 0;
    rep(_,h) rep(_,w){
        int i; cin >> i;
        if(i != -1) ans += d[i][1];
    }
    cout << ans << endl;
}