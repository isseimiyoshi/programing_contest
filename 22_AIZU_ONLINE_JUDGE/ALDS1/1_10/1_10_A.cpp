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
*/

const int NIL = -1;
const int MAX_N = 50;
vector<ll> fib(MAX_N);

int fibonach(vector<ll> &fib, int i){
    if(i == 0) return fib[0];
    if(i == 1) return fib[1];
    if(fib[i] != NIL) return fib[i];
    fib[i] = fibonach(fib, i-1) + fibonach(fib, i-2);
    return fib[i];
}

int main()
{
    int n; cin >> n;
    rep(i, MAX_N) fib[i] = NIL;
    fib[0] = 1;
    fib[1] = 1;
    ll res = fibonach(fib, n);
    cout << res << endl;
}