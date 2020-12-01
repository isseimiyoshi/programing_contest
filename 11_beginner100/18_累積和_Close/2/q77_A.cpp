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


int main()
{
    int n, m; cin >> n >> m;
    int dis[n];
    dis[0] = 0;
    rep(i,n-1){
        int si; cin >> si;
        dis[i+1] = dis[i] + si;
    }

    int move[m];
    rep(i,m) cin >> move[i];

    int now = 0;
    ll ans = 0;
    rep(i,m){
        int res = dis[now+move[i]] - dis[now];
        if(res < 0) res *= -1;
        ans += res;
        ans %= 100000;
        now += move[i];
    }
    cout << ans << endl;
}