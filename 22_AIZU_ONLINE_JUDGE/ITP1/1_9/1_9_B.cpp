#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A'; 

int main()
{
    while(true){
        string s; cin >> s;
        if(s == "-") break;
        int m; cin >> m;
        for(int i=0; i<m; i++){
            int h; cin >> h;
            s = s.substr(h) + s.substr(0, h);
            // cout << s << endl;
        }
        cout << s << endl;
    }
}