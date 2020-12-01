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
    string area; cin >> area;
    vector<int> L;
    int h[area.size()+1];  // マスの高さ
    h[0] = 0;   // 初期高さ: 0
    int high_h_ind = 0;
    for(int i=0; i<area.size(); i++){
        char c = area[i];
        if(c == '\\'){
            h[i+1] = h[i]-1;
        }else if(c == '/'){
            h[i+1] = h[i]+1;
        }else{
            h[i+1] = h[i];
        }
        if(h[i+1] > high_h_ind) high_h_ind = i+1;
    }

}