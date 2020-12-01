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

double angle(int h, int m){
    return M_PI*h/6 + M_PI*m/360 - M_PI*m/30;
}

int main()
{
    int a, b, h, m; cin >> a >> b >> h >> m;
    double c2 = a*a + b*b - 2*a*b*cos(angle(h,m));
    // cout << angle(h,m) << endl;
    printf("%.10lf\n", sqrt(c2));
}