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

const int MAX_N = 50;
ll f[MAX_N];

ll fibo(int i){
    if(i == 0 || i == 1) return 1;
    if(f[i]) return f[i];
    return f[i] = fibo(i-1)+fibo(i-2);
}

int main()
{
    int n; cin >> n;
    rep(i,n) f[i] = 0;
    cout << fibo(n) << endl;
}