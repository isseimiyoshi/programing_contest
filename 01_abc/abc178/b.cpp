#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

const ll INF = 1000100100100100100;

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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(b<d){
        swap(a,c);
        swap(b,d);
    }
    ll ma = -INF;
    ma = max(a*c, ma);
    ma = max(a*d, ma);
    ma = max(b*c, ma);
    ma = max(b*d, ma);

    cout << ma << endl;
}