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
    string s; cin >> s;
    int ss = s.size();
    ll res = 0;
    rep(i,ss){
        int j;
        if(s[i] == '0') j = 0;
        else if(s[i] == '1') j=1;
        else if(s[i] == '2') j=2;
        else if(s[i] == '3') j=3;
        else if(s[i] == '4') j=4;
        else if(s[i] == '5') j=5;
        else if(s[i] == '6') j=6;
        else if(s[i] == '7') j=7;
        else if(s[i] == '8') j=8;
        else if(s[i] == '9') j=9;
        res += j;
    }
    if(res % 9 == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}