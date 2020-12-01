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

const double eps = 0.0001;

int main()
{
    double a, b, x; cin >> a >> b >> x;
    double res;
    if(x - a*a*b/2.0 > eps){
        res = (180.0/M_PI)*atan(2.0*b/a-2.0*x/(a*a*a));
    }else if(a*a*b/2.0 - x > eps){
        res = (180.0/M_PI)*(M_PI/2.0-atan(2.0*x/(a*b*b)));
    }else{
        res = (180.0/M_PI)*atan(b/a);
    }
    printf("%.6f\n", res);
}