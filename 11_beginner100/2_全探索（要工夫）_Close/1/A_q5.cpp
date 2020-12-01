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
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    ll min_cost;
    if( a+b < 2*c){
        min_cost = a*x + b*y;
    }else{
        if(x == y) min_cost = x*c*2;
        else if(x > y){
            min_cost = y*c*2;
            if(a > 2*c) min_cost += 2*c*(x-y);
            else min_cost += a*(x-y);
        }else{
            min_cost = x*c*2;
            if(b > 2*c) min_cost += 2*c*(y-x);
            else min_cost += b*(y-x);
        }
    }
    cout << min_cost << endl;
}