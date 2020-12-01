#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

/*

This is a pen.
I have a pencil.

*/

int main()
{
    string line_s;
    string s;
    for(int i=0; i<3; i++){
        getline(cin, s);
        cout << s << endl;
    }
    // これでchar型の文字列がa to zまでループする
    for(char c='a'; c<='z'; c++){
        char lower = c;
        char upper = toupr(c);
        int c_count = 0;
        for(int i=0; i<line_s.size(); i++){
            char s_i = (char)line_s[i];
            if(s_i == lower || s_i == upper){
                c_count += 1;
            }
        }
        printf("%c : %d\n", lower, c_count);
    }
}