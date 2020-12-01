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
    int a, b, C;
    cin >> a >> b >> C;
    double S, L, h;
    double C_rad = C*M_PI/180.0;
    S = a*b*sin(C_rad)/2.0;
    double c = sqrt(a*a + b*b - 2*a*b*cos(C_rad));
    L = a + b + c;
    h = 2*S / a;
    printf("%.5lf %.5lf %.5lf\n", S, L, h);
}