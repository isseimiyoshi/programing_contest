#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

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
    int N; cin >> N;
    if(N%10 == 2 || N%10 == 4 || N%10 == 5 || N%10 == 7 || N%10 == 9)cout << "hon" << endl;
    else if(N%10 == 0 || N%10 == 1 || N%10 == 6 || N%10 == 8) cout << "pon" << endl;
    else cout << "bon" << endl;
}