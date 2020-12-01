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

struct DisjointSet{
    vector<ll> p;
    DisjointSet(ll n) : p(n){
        rep(i,n) p[i] = i;
    }

    ll root(ll x){
        if(p[x] == x) return x;
        return p[x] = root(p[x]);
    }

    void unite(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return;
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
    ll v, e; cin >> v >> e;
    vector<tuple<ll, ll, ll> > edges;
    rep(i, e){
        ll s, t, w; cin >> s >> t >> w;
        edges.push_back(make_tuple(w, s, t));
    }
    sort(edges.begin(), edges.end());

    DisjointSet dis = DisjointSet(v);

    ll ans = 0;
    rep(i,e){
        ll w, s, t;
        tie(w, s, t) = edges[i];
        if(!dis.same(s, t)){
            ans += w;
            dis.unite(s, t);
        }
    }   
    cout << ans << endl;
}