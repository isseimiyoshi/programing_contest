#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

const ll mod = 998244353;

int main()
{
    int n; cin >> n;
    int k; cin >> k;

    int l[k], r[k];
    rep(i,k){
        cin >> l[i] >> r[i];
    }   

    ll dp[n+1];
    rep(i,n+1) dp[i] = 0;
    dp[0] = 1;

    rep(i,n){
        rep(j,k){
            if(i+1<l[j]) continue;
            else if(i+1>=l[j] && i+1<=r[j]) dp[i+1] += dp[i+1-l[j]];
            else{
                int ma = i+1 - l[j];
                int mi = i+1 - r[j] - 1;
                dp[i+1] += (dp[ma] - dp[mi]);
            }
            dp[i+1] %= mod;
        }
        dp[i+1] += dp[i];
        dp[i+1] %= mod;
    }
    /*
    cout << endl;
    rep(i,n+1) cout << dp[i] << endl;
    cout << endl;
    */
    ll ans = (dp[n-1] - dp[n-2] + mod) % mod;
    cout << ans << endl;
}