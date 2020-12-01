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


int main()
{
    ll n; cin >> n;
    vector<tuple<ll, ll, ll> > sortx;
    vector<tuple<ll, ll, ll> > sorty;
    rep(i,n){
        ll x, y; cin >> x >> y;
        sortx.push_back(make_tuple(x, y, i));
        sorty.push_back(make_tuple(y, x, i));
    }
    // cout << "ok" << endl;
    sort(sortx.begin(), sortx.end());
    sort(sorty.begin(), sorty.end());

    vector<tuple<ll, ll, ll> > eds;
    // cout << "ok2" << endl;
    rep(i,n-1){
        ll x_i0, y_i0, i0;
        ll x_i1, y_i1, i1;
        tie(x_i0, y_i0, i0) = sortx[i];
        tie(x_i1, y_i1, i1) = sortx[i+1];
        eds.push_back(make_tuple(x_i1-x_i0, i0, i1));
        tie(y_i0, x_i0, i0) = sorty[i];
        tie(y_i1, x_i1, i1) = sorty[i+1];
        eds.push_back(make_tuple(y_i1-y_i0, i0, i1));
    }
    // cout << "ok3" << endl;
    sort(eds.begin(), eds.end());

    ll size_eds = eds.size();

    DisjointSet dis = DisjointSet(n);
    // cout << "ok4" << endl;
    ll ans = 0;

    rep(i,size_eds){
        ll w, s, t;
        tie(w, s, t) = eds[i];
        if(!dis.same(s, t)){
            ans += w;
            dis.unite(s, t);
        }
    }
    // cout << "ok5" << endl;
    cout << ans << endl;
}