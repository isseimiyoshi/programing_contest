#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int main()
{
    int n; cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];

    ll dp[n];
    rep(i,n) dp[i] = 0;
    dp[0] = 1000;

    for(int i=1; i<n; i++){
        rep(j,i){
            ll res = (dp[j]/a[j])*a[i] + dp[j]%a[j];
            dp[i] = max(res, dp[i]);
        }
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n-1] << endl;
}