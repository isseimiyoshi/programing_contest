#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int main()
{
    int n, t; cin >> n >> t;
    int maxa = 0;
    int a[n], b[n];
    rep(i,n){
        cin >> a[i] >> b[i];
        maxa = max(maxa, a[i]);
    }

    int dp[n+1][t+maxa+1];
    rep(i,n+1) rep(j,t+maxa+1) dp[i][j] = 0;

    rep(i,n){
        rep(j,t+maxa+1){
            if(j<a[i]) dp[i+1][j] = dp[i][j];
            else{
                if(j-a[i]>=t) dp[i+1][j] = dp[i][j];
                else{
                    dp[i+1][j] = max(dp[i][j], dp[i][j-a[i]]+b[i]);
                }
            }
        }
    }

    int ans = 0;
    rep(i,n+1){
        rep(j,t+maxa+1){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
}