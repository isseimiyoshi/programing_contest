#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

const ll INF = 1000100100100100100;

int main()
{
    int n; cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];

    ll dp[n+1][2];
    dp[0][0] = 0;
    dp[0][1] = -INF;

    rep(i,n){
        dp[i+1][0] = max(dp[i][0]+a[i], dp[i][1]-a[i]);
        dp[i+1][1] = max(dp[i][0]-a[i], dp[i][1]+a[i]);
    }
    cout << dp[n][0] << endl;
}