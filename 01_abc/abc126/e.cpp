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

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

int main()
{
    int N, M; cin >> N >> M;
    bool rev[N];
    rep(i,N) rev[i] = false;
    int cost = 0;
    rep(i,M){
        int X, Y, Z; cin >> X >> Y >> Z;
        if((!rev[X-1]) && (!rev[Y-1])) cost++;
        rev[X-1] = true;
        rev[Y-1] = true;
    }
    rep(i,N){
        if(!rev[i]) cost++;
    }
    cout << cost << endl;
}