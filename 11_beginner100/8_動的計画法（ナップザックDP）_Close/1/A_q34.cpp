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

const int MAX_N = 45;

int fib[MAX_N];
int n;

void init(){
    rep(i,MAX_N) fib[i] = -1;
}

int calc_fib(int _n){
    int fib1, fib2;
    if(fib[_n-1] != -1) fib1 = fib[_n-1];
    else fib1 = calc_fib(_n-1);
    if(fib[_n-2] != -1) fib2 = fib[_n-2];
    else fib2 = calc_fib(_n-2);
    return fib[_n] = fib1 + fib2;
}

int main()
{
    cin >> n;
    init();
    fib[0] = fib[1] = 1;
    cout << calc_fib(n) << endl;
}