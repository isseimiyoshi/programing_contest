#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int main()
{
    int n, t, s; cin >> n >> t >> s;
    int a[n], b[n];
    rep(i,n) cin >> a[i] >> b[i];

    int dp[n+1][s+1];
    int dp2[n+1][t-s+1];

    rep(i,n+1) rep(j,s+1) dp[i][j] = 0;
    rep(i,n+1) rep(j,t-s+1) dp2[i][j] = 0;

    rep(i,n){
        rep(j,s+1){
            if(j<b[i]) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = max(dp[i][j], dp[i][j-b[i]]+a[i]);
        }
    }

    rep(i,n){
        rep(j,t-s+1){
            if(j<b[n-i-1]) dp2[i+1][j] = dp2[i][j];
            else dp2[i+1][j] = max(dp2[i][j], dp2[i][j-b[n-i-1]]+a[n-i-1]);
        }
    }
    /*
    rep(i,n+1){
        rep(j,s+1){
            cout << dp[i][j] << " ";
        }cout << endl;
    }

    cout << endl;

    rep(i,n+1){
        rep(j,t-s+1){
            cout << dp2[i][j] << " ";
        }cout << endl;
    }
    */

    int ans = 0;
    rep(i,n+1){
        int res;
        res = dp2[n-i][t-s] + dp[i][s];
        ans = max(res, ans);
    }
    cout << ans << endl;   
}