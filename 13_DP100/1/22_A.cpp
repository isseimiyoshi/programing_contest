#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

const int INF = 1000100100;

int main()
{
    int n, m; cin >> n >> m;
    pair<int,int> key[m];
    rep(i,m){
        int ai, bi; cin >> ai >> bi;
        key[i].first = ai;
        int s = 0;
        rep(j,bi){
            int ci; cin >> ci; --ci;
            s |= (1<<ci); 
        }
        key[i].second = s;
    }

    int dp[(1<<n)];
    rep(i,(1<<n)) dp[i]= INF;
    dp[0] = 0;

    rep(s,(1<<n)){
        rep(i,m){
            int t = s | key[i].second;
            int cost = dp[s] + key[i].first;
            dp[t] = min(dp[t], cost);
        }
    }

    // rep(i,(1<<n)) cout << dp[i] << endl;
    if(dp[(1<<n)-1] == INF) cout << -1 << endl;
    else cout << dp[(1<<n)-1] << endl;
}