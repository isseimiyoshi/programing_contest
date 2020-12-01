#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

int main()
{
    string s, p;
    cin >> s >> p;
    s += s;
    int p_in_s = s.find(p);
    if(p_in_s == string::npos) cout << "No" << endl;
    else cout << "Yes" << endl;
}