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
    int N; string S;
    cin >> N >> S;
    for(int i=0; i<N; i++){
        for(j=i+1; j<N; j++){
            string p_s = s.substr(j);
            p_s.erase(j-i, 1);
            if((char)S[i] == 'R' && (char)S[j] == 'G') count(p_s.cbegin())
        }
    }   
}