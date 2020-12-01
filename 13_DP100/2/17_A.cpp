#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int main()
{
    int x, y; cin >> x >> y;
    int n; cin >> n;
    int t[n], h[n];
    rep(i,n) cin >> t[i] >> h[i];

    int dp[n+1][x+y+1][x+1];
    rep(i,n+1) rep(j,x+y+1) rep(k,x+1) dp[i][j][k] = 0;

    rep(i,n) rep(j,x+y+1) rep(k,x+1){
        if(j<t[i] || k == 0) dp[i+1][j][k] = dp[i][j][k];
        else{
            dp[i+1][j][k] = max(dp[i][j][k], dp[i][j-t[i]][k-1] + h[i]);
        }
    }

    cout << dp[n][x+y][x] << endl;
}