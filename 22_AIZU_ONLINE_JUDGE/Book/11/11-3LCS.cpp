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

int lcs(string X, string Y){
    int n = X.size(), m = Y.size();
    int lcsv[n+1][m+1];
    rep(i,n+1) lcsv[i][0] = 0;
    rep(j,m+1) lcsv[0][j] = 0;
    rep(i,n){
        rep(j,m){
            if(X[i] == Y[j]){
                lcsv[i+1][j+1] = lcsv[i][j]+1;
            }else{
                lcsv[i+1][j+1] = max(lcsv[i+1][j], lcsv[i][j+1]);
            }
        }
    }
    return lcsv[n][m];
}

int main()
{
    int n; cin >> n;
    rep(_,n){
        string X, Y; cin >> X >> Y;
        cout << lcs(X, Y) << endl;
    }
}