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
    vector<int> p;
    DisjointSet(int n): p(n){
        rep(i,n) p[i] = -1;
    }

    int root(int x){
        if(p[x]<0) return x;
        return p[x] = root(p[x]);
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        if(rx>ry) swap(rx,ry);
        p[rx] += p[ry];
        p[ry] = rx;
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main()
{
    int n; cin >> n;
    vector<P> x;
    vector<P> y;
    rep(i,n){
        int xi, yi; cin >> xi >> yi;
        x.push_back(make_pair(xi,i));
        y.push_back(make_pair(yi,i));
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    priority_queue<tuple<int,int,int> > pq;

    rep(i,n-1){
        pq.push(make_tuple(-abs(x[i].first-x[i+1].first), x[i].second, x[i+1].second));
        pq.push(make_tuple(-abs(y[i].first-y[i+1].first), y[i].second, y[i+1].second));
    }

    DisjointSet dis = DisjointSet(n);
    ll ans = 0;
    while(!pq.empty()){
        int s, t, e;
        tie(e,s,t) = pq.top(); pq.pop(); e = -e;
        if(!dis.same(s,t)){
            ans += e;
            dis.unite(s,t);
        }
    }
    cout << ans << endl;
}