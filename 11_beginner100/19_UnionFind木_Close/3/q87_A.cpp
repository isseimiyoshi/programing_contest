#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const int INF = 1000100100;

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

struct DisjointSet{
    vector<ll> p;
    DisjointSet(ll n) : p(n){
        rep(i,n) p[i] = -1;
    }

    ll root(ll x){
        if(p[x] < 0) return x;
        return p[x] = root(p[x]);
    }

    ll num(ll x){
        return -p[root(x)];
    }

    void unite(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return;
        if(rx>ry) swap(rx,ry);
        p[rx] += p[ry];
        p[ry] = rx;
    }

    bool same(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
};

int main()
{
    ll n, m; cin >> n >> m;
    ll a[m], b[m];
    rep(i,m){
        cin >> a[i] >> b[i];
        --a[i], --b[i];
    }

    vector<ll> res;

    DisjointSet dis = DisjointSet(n);

    ll ans = n*(n-1)/2;
    res.push_back(ans);
    for(int i=m-1; i>0; i--){
        if(!dis.same(a[i],b[i])) ans -= dis.num(a[i])*dis.num(b[i]);
        dis.unite(a[i], b[i]);
        res.push_back(ans);
    }   
    reverse(res.begin(), res.end());
    for(ll r: res) cout << r << endl;
}