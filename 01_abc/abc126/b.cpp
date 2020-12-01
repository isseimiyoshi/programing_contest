#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

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

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

int main()
{
    string S; cin >> S;
    string F = "";
    F += S[0]; F += S[1];
    string B = "";
    B += S[2]; B += S[3];

    bool isYYMM = false;
    bool isMMYY = false;

    if("01" <= F && F <= "12"){
        if("00" <= B && B <= "99"){
            isMMYY = true;
        }
    }
    if("01" <= B && B <= "12"){
        if("00" <= F && F <= "99"){
            isYYMM = true;
        }
    }
    if(isMMYY && isYYMM) cout << "AMBIGUOUS" << endl;
    else if(isMMYY) cout << "MMYY" << endl;
    else if(isYYMM) cout << "YYMM" << endl;
    else cout << "NA" << endl;
}