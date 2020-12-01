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
    map<char, int> c_count;
    for(char c='a'; c<='z'; c++){
        c_count[c] = 0;
        for(int i=0; i<p.size(); i++){
            if(c == (char)p[i]) c_count[c] += 1;
        }
    }
    // cout << c_count['d'] << endl;
    for(int i=0; i<s.size(); i++){
        char s_ch = (char)s[i];
        c_count[s_ch] -= 1;
    }
    cout << c_count['d'] << endl;
    bool ok = true;
    for(char c='a'; c<='z'; c++){
        if(c_count[c] > 0) ok = false;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}