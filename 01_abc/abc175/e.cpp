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

int main()
{
    int r, c, n; cin >> r >> c >> n;
    int mass[r][c];
    rep(i,n){
        int ri, ci, vi;
        cin >> ri >> ci >> vi;
        --ri, --ci;
        mass[ri][ci] = vi;
    }

    int dp[r][c][4];    // 3次元目はその行でアイテムを保有している状態を持っている
    rep(i,r) rep(j,c){
        
    }
}