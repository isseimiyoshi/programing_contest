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
    string S; cin >> S;
    int N = S.length();
    // cout << N << endl;

    bool ok = true;

    for(int i=0; i<(N/4); i++){
        if(S[i] != S[N/2-1-i]) ok = false;
        if(S[N/2+1+i] != S[N-1-i]) ok = false;
    }
    for(int i=0; i<N/2; i++){
        if(S[i] != S[N-1-i]) ok = false;
    }
    

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}