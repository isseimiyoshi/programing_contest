#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
using P = pair<ll, ll>;

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
    int n, m, Q; cin >> n >> m >> Q;
    int l[m], r[m];
    rep(i,m){
        cin >> l[i] >> r[i];
        --l[i], --r[i];
    }

    int c[n][n];
    rep(i,n) rep(j,n) c[i][j] = 0;
    rep(i,m) c[r[i]][l[i]]++;

    rep(i,n){
        rep(j,n){
            if(i == 0){
                if(j == 0) continue;
                c[i][j] = c[i][j-1] + c[i][j];
            }else{
                if(j == 0){
                    c[i][j] = c[i-1][j] + c[i][j];
                }else{
                    c[i][j] = c[i][j] + c[i-1][j] + c[i][j-1] - c[i-1][j-1];
                }
            }
        }
    }

    rep(_,Q){
        int p, q; cin >> p >> q;
        --p, --q;

        if(p == 0 && q == 0) cout << c[p][q] << endl;
        else if(p == 0) cout << c[q][q] << endl;
        else if(q == 0) continue;
        else{
            cout << (c[q][q]-c[q][p-1]-c[p-1][q]+c[p-1][p-1]) << endl;
        }
    }
}