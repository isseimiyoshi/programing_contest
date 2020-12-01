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

// string型からint型への変換（char ⇨　intは不明）
string c1 = "1";
string c2 = "2";
int i1 = stoi(c1);
int i2 = stoi(c2);
*/

int main()
{
    stack<string> S;
    while(true){
        string x; cin >> x;
        if(cin.eof()) break;
        cout << x << endl;
    }
}