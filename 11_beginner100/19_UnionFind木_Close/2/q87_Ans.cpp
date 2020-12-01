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

struct DisjointSet{
    vector<int> p;
    DisjointSet(int n) : p(n){
        rep(i,n) p[i] = -1;
    } 

    int root(int x){
        if(p[x] < 0) return x;
        return p[x] = root(p[x]);
    }

    int size(int x){
        return -p[root(x)];
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        if(size(rx) < size(ry)) swap(rx, ry);
        p[rx] += p[ry]; // 親になるノードに子がもともと保持していたグループ数をプラスする
        p[ry] = rx; // 子ノードを親にくっつける
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main()
{
    ll n, m; cin >> n >> m;
    int a[m], b[m];
    rep(i,m){
        cin >> a[i] >> b[i];
        --a[i], --b[i];
    }
    reverse(a, a+m);
    reverse(b, b+m);    

    DisjointSet dis = DisjointSet(n);

    ll ans[m];
    ans[0] = n*(n-1)/2;

    rep(i,m-1){
        if(dis.same(a[i], b[i])){
            ans[i+1] = ans[i];
            continue;
        }
        ans[i+1] = ans[i] - dis.size(a[i])*dis.size(b[i]);
        dis.unite(a[i], b[i]);
    }

    reverse(ans, ans+m);
    rep(i,m) cout << ans[i] << endl;
}