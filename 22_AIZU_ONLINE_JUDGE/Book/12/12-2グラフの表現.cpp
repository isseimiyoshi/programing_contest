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
    int n; cin >> n;
    int M[n][n];
    // 隣接行列の初期化
    rep(i,n) rep(j,n) M[i][j] = 0;
    // 隣接リストを読み込む
    rep(i,n){
        int u; cin >> u; u--;   // 二次元配列のインデックスに合うように頂点番号をデクリメント
        int k; cin >> k;
        rep(_,k){
            int vi; cin >> vi; vi--;
            M[u][vi] = 1;
        }
    }
    rep(i,n){
        rep(j,n){
            cout << M[i][j];
            if(j != n-1) cout << " ";
        }
        cout << endl;
    }
}