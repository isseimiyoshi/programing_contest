#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* 大文字を小文字に変換 */
char tolower(char c) {
  return (c + 0x20);
}

/* 小文字を大文字に変換 */
char toupr(char c) {
  return (c - 0x20);
}

int main()
{
    string s;
    getline(cin, s);
    for(int i=0; i<s.size(); i++){
        char moji = (char)s[i];
        if('a' <= moji && moji <= 'z') moji = toupr(moji);
        else if('A' <= moji && moji <= 'Z') moji = tolower(moji);
        else moji = moji;
        cout << moji;
    }
    cout << endl;
}