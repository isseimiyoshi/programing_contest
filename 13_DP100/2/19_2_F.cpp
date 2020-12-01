#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int main()
{
    int n, t; cin >> n >> t;
    P p[n];
    rep(i,n) cin >> p[i].first >> p[i].second;
    sort(p,p+n);

    int dp[n+1][t+1];
    rep(i,n+1) rep(j,t+1) dp[i][j] = 0;

    rep(i,n){
        rep(j,t+1){
            if(j<p[i].first) dp[i+1][j] = dp[i][j];
            else{
                dp[i+1][j] = max(dp[i][j], dp[i][j-p[i].first]+p[i].second);
            }
        }
    }

    int ans = 0;
    rep(i,n-1){
        ans = max(ans, dp[i+1][t-1]+p[i+1].second);
    }
    cout << ans << endl;
}