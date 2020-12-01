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

const int INF = 1000100100;

int main()
{
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;

    ll ans = INF;

    ll sim = a*x + b*y;
    for(int i=1; i<=max(x, y); i++){
        ll sum = sim;
        if(i>x) sum -= x*a;
        else sum -= a*i;
        if(i>y) sum -= b*y;
        else sum -= b*i;
        sum += 2*c*i;
        
        ans = min(ans, sum);
    }
    ans = min(ans, sim);
    cout << ans << endl;
}