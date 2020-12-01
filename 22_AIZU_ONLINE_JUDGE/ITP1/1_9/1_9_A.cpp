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
    string W;
    cin >> W;
    int count = 0;
    while(true){
        string s;
        cin >> s;
        if(s == "END_OF_TEXT") break;
        for(int i=0; i<s.size(); i++){
            if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A';
        }
        if(s == W) count += 1;
    }
    cout << count << endl;

    /*
    string s = "abcdeabloab";
    int s_ab = s.find("ab");
    string p = "ab";
    while(true){
        int s_ab = s.find(p);
        if(s_ab == string::npos) break;
        cout << s_ab << endl;
        s = s.substr(s_ab + p.size());
    }
    */
}