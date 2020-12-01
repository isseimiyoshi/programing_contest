#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int main()
{
    int n; cin >> n;
    int t; cin >> t;
    int a[n], b[n];
    rep(i,n){
        cin >> a[i] >> b[i];
    }

    int dp[n+1][t+1];
    rep(i,n+1) rep(j,t+1) dp[i][j] = 0;

    rep(i,n){
        rep(j,t+1){
            if(j<a[i]) dp[i+1][j] = dp[i][j];
            else{
                dp[i+1][j] = max(dp[i][j], dp[i][j-a[i]]+b[i]);
            }
        }
    }

    int res = 0;
    rep(i,n){
        res = max(dp[i][t-1]+b[i], res);
    }

    cout << res << endl;
}