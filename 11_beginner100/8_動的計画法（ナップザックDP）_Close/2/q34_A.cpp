#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
using P = pair<ll, ll>;

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

ll fib[MAX_N];

void init(){
    rep(i,MAX_N) fib[i] = -1;
}

void calc(int n){
    if(fib[n-1] != -1 && fib[n-2] != -1){
        fib[n] = fib[n-1] + fib[n-2];
    }
}


int main()
{
    int n; cin >> n;
    init();
    fib[0] = fib[1] = 1;
    for(int i=2; i<=n; i++){
        calc(i);
    }
    cout << fib[n] << endl;
}