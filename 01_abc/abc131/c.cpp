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

int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

int lcm(int a, int b)
{
   return a * b / gcd(a, b);
}

int main()
{
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll C_n = (B/C) - ((A-1)/C);
    ll D_n = (B/D) - ((A-1)/D);
    ll CD_n = (B/lcm(C, D)) - ((A-1)/lcm(C, D));
    ll res = (B - A + 1) - (C_n + D_n - CD_n);
    cout << res << endl;
}