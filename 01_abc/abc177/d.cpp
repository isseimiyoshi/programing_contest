#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
using P = pair<ll,ll>;

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
    vector<int> p;
    DisjointSet(int n) : p(n){
        rep(i,n) p[i] = -1;
    }

    ll root(int x){
        if(p[x] < 0) return x;
        return p[x] = root(p[x]);
    }

    ll size(int x){
        return -p[x];
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx > ry) swap(rx, ry);
        if(rx == ry) return;
        p[rx] += p[ry];
        p[ry] = rx;
    }
};

int main()
{
    int n, m; cin >> n >> m;
    int a[m], b[m];
    rep(i,m){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
    }

    DisjointSet dis = DisjointSet(n);
    rep(i,m){
        if(dis.same(a[i], b[i])) continue;
        dis.unite(a[i], b[i]);
    }

    ll maxg = 0;
    rep(i,n){
        maxg = max(maxg, dis.size(i));
        // cout << dis.size(i) << endl;
    }

    cout << maxg << endl;
}