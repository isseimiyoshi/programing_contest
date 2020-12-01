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

void insert(set<string> &dict, string s){
    dict.insert(s);
}

void find(set<string> dict, string s){
    if(dict.count(s)) cout << "yes" << endl;
    else cout << "no" << endl;
}

int main()
{
    int n; cin >> n;
    set<string> dict;
    for(int i=0; i<n; i++){
        string command, s;
        cin >> command >> s;
        if(command == "insert") insert(dict, s);
        else find(dict, s);
    }
}