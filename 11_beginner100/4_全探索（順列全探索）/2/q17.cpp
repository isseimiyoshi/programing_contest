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

const int FREE = 0, NOT_FREE = 1;

map<int, int> m;

int main()
{
    int k;
    rep(i,8) m[i] = -1;
    rep(i,k){
        int r, c; cin >> r >> c;
        m[r] = c;
    }

    int mass[8][8];
    rep(i,8) rep(j,8) mass[i][j] = FREE;
    rep(i,8){
        if(m[i] != -1){
            rep(j,8) mass[i][j] = NOT_FREE;
            rep(j,8) mass[j][m[i]] = NOT_FREE;
            rep(k1,8) rep(k2,8) if(k1+k2 == i+m[i]) m[k1][k2] = NOT_FREE;
            rep(k1,8) rep(k2,8) if(k1-k2 == i-m[i]) m[k1][k2] = NOT_FREE;
        }
    }
}