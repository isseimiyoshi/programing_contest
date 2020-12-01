#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

struct DisjointSet{
    vector<int> p;
    DisjointSet(int n) : p(n){
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
    int n, m; cin >> n >> m;
    ll a[n], b[n];
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];

    DisjointSet dis = DisjointSet(n);
    rep(i,m){
        int ci, di; cin >> ci >> di; --ci, --di;
        dis.unite(ci,di);
    }

    ll root_sum[n];
    ll root_sum2[n];
    rep(i,n) root_sum[i] = 0;
    rep(i,n) root_sum2[i] = 0;
    rep(i,n){
        root_sum[dis.root(i)] += a[i];
        root_sum2[dis.root(i)] += b[i];
    }
    /*
    rep(i,n){
        cout << root_sum[i] << " ";
    }cout << endl;

    rep(i,n){
        cout << root_sum2[i] << " ";
    }cout << endl;
    */

    bool isok = true;
    rep(i,n){
        if(root_sum[i] != root_sum2[i]){
            isok = false;
            break;
        }
    }
    if(isok) cout << "Yes" << endl;
    else cout << "No" << endl;


}