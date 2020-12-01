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

struct Point{ double x; double y; };

void printPoint(Point p){
    printf("%.5lf %.5lf\n", p.x, p.y);
}

void koch(int d, Point p1, Point p2){
    if(d == 0) return;
    // s, u, tをそれぞれ計算
    Point s, t, u;
    s.x = (2*p1.x + p2.x) / 3; s.y = (2*p1.y + p2.y) / 3;
    t.x = (p1.x + 2*p2.x) / 3; t.y = (p1.y + 2*p2.y) / 3;
    u.x = (t.x-s.x)*cos(60*M_PI/180) - (t.y-s.y)*sin(60*M_PI/180) + s.x;
    u.y = (t.x-s.x)*sin(60*M_PI/180) + (t.y-s.y)*cos(60*M_PI/180) + s.y;
    // 出力
    koch(d-1, p1, s);
    printPoint(s);
    koch(d-1, s, u);
    printPoint(u);
    koch(d-1, u, t);
    printPoint(t);
    koch(d-1, t, p2);
}


int main()
{
    int n; cin >> n;
    Point p1, p2;
    p1.x = 0; p1.y = 0;
    p2.x = 100; p2.y = 0;
    printPoint(p1);
    koch(n, p1, p2);
    printPoint(p2);
}