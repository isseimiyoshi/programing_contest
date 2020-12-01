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
    ll n, m, k; cin >> n >> m >> k;
    priority_queue<tuple<ll,ll,ll> > pq;
    DisjointSet dis = DisjointSet(n);

    rep(i,m){
        int a, b, c; cin >> a >> b >> c;
        --a, --b;
        pq.push(make_tuple(-c, a, b));
    }

    ll ans = 0;
    vector<ll> selected;
    while(!pq.empty()){
        int a, b, c;
        tie(c, a, b) = pq.top(); pq.pop();
        c = -c;
        if(!dis.same(a, b)){
            dis.unite(a,b);
            ans += c;
            selected.push_back(c);
        }
    }
    sort(selected.begin(), selected.end());
    int i = selected.size()-1;
    rep(_,k-1){
        ans -= selected[i];
        i--;
    }
    cout << ans << endl;
}

/*

5 6 2
1 2 5
1 3 3
2 3 4
2 5 7
3 4 6
4 5 5

*/