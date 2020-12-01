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
    int N;
    cin >> N;
    bool yes = false;
    for(int i=0; i<3; i++){
        if(N % 10 == 7) yes = true;
        else N /= 10;
    }
    if(yes) cout << "Yes" << endl;
    else cout << "No" << endl;
}