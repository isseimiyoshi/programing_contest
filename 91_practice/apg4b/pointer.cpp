#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    int x = 123;
    int y = 123;

    int *p = &x;    // xのアドレスをpに格納する
    int *q = &y;    // yのアドレスはqに格納する
    if(p == q) cout << "p == q" << endl;
    else cout << "p != q" << endl;
    if(*p == *q) cout << "*p == *q" << endl;
    else cout << "*p != *q" << endl;
}