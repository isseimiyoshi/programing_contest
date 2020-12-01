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
        rep(i,n) p[i] = -1;
    }

    ll root(ll x){
        if(p[x] < 0) return x;
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

/*

4 3 1
1 2 2
2 3 9
2 4 5

*/


int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    DisjointSet dis = DisjointSet(n);

    vector<tuple<ll, ll, ll> > eds;

    rep(i,m){
        ll s, t, w; cin >> s >> t >> w;
        --s, --t;
        eds.push_back(make_tuple(w, s, t));
    }
    sort(eds.begin(), eds.end());

    vector<ll> min_eds;

    ll ans = 0;

    rep(i,m){
        ll w, s, t;
        tie(w, s, t) = eds[i];
        if(!dis.same(s,t)){
            min_eds.push_back(w);
            ans += w;
            dis.unite(s, t);
        }
    }
    sort(min_eds.begin(), min_eds.end());
    ll size_min = min_eds.size();
    rep(i,k-1){
        ans -= min_eds[size_min-1-i];
    }
    cout << ans << endl;
}