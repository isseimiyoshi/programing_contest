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
    int a[m];
    vector<int> c[m];
    rep(i, m){
        int ai, bi; cin >> ai >> bi;
        a[i] = ai;
        rep(_,bi){
            int ci; cin >> ci; --ci;
            c[i].push_back(ci);
        }
    }

    int dp[(1<<n)];
    rep(i,(1<<n)) dp[i] = INF;
    dp[0] = 0;

    rep(i,m){
        rep(j,(1<<n)){
            int nxt = j;
            for(auto ci: c[i]){
                nxt = (nxt | (1<<ci));
            }
            dp[nxt] = min(dp[nxt], dp[j]+a[i]);
        }
    }

    

    if(dp[(1<<n)-1] == INF) cout << -1 << endl;
    else cout << dp[(1<<n)-1] << endl;
}