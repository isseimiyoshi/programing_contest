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
    char ch;
    map<char, int> c_count;
    for(char c='a'; c<='z'; c++){
        c_count['a'] = 0;
    }
    while(cin >> ch){
        for(char c='a'; c<='z'; c++){
            char lower = c;
            char upper = toupr(c);
            if(ch == lower || ch == upper) c_count[c] += 1;
        }
    }
    for(char c='a'; c<='z'; c++){
        printf("%s : %d\n", c, c_count[c]);
    }
}