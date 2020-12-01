#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

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
*/

int main()
{
    int n; cin >> n;
    int mat[n][n];
    rep(i,n) rep(j,n) mat[i][j] = 0;
    rep(i, n){
        int u; cin >> u;
        int k; cin >> k;
        rep(j,k){
            int vj; cin >> vj;
            mat[u-1][vj-1] = 1;
        }
    }
    // 出力
    rep(i,n){
        rep(j,n){
            cout << mat[i][j];
            if(j != n-1) cout << " ";
        }
        cout << endl;
    }
}