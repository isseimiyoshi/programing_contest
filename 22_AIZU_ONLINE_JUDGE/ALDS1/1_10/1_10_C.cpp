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

int LCS(string s1, string s2){
    int c[s1.size()+1][s2.size()+1];
    rep(i,s1.size()+1) rep(j, s2.size()+1) c[i][j] = 0;
    for(int i=1; i<=s1.size(); i++){
        for(int j=1; j<=s2.size(); j++){
            if(s1[i-1] == s2[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
            }else{
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }
    return c[s1.size()][s2.size()];
}

int main()
{
    int q; cin >> q;
    rep(i,q){
        string s1, s2;
        cin >> s1 >> s2;
        cout << LCS(s1, s2) << endl;
    }
}