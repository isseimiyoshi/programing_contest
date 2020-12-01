#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

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
        if(p[rx]>p[ry]) swap(rx,ry);
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
    int n, m, W; cin >> n >> m >> W;
    int w[n], v[n];
    rep(i,n) cin >> w[i] >> v[i];

    DisjointSet dis = DisjointSet(n);

    rep(i,m){
        int ai, bi; cin >> ai >> bi;
        --ai, --bi;
        dis.unite(ai,bi);
    }

    int w2[n], v2[n];
    rep(i,n) w2[i] = v2[i] = 0;
    rep(i,n){
        w2[dis.root(i)] += w[i];
        v2[dis.root(i)] += v[i];
    }
    
    // rep(i,n) printf("%d %d\n", w2[i], v2[i]);

    int dp[n+1][W+1];
    rep(i,n+1) rep(j,W+1) dp[i][j] = 0;

    rep(i,n){
        rep(j,W+1){
            if(w2[i] == 0 && v2[i] == 0){
                dp[i+1][j] = dp[i][j];
            }else if(j<w2[i]){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = max(dp[i][j], dp[i][j-w2[i]]+v2[i]);
            }
        }
    }

    cout << dp[n][W] << endl;

}