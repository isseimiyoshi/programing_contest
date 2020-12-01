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

    ll dp[t+1][2];
    rep(j,t+1) rep(k,2) dp[j][k] = 0;

    rep(i,n){
        rep(j,t+1){
            if(j<b[i]){
                dp[j][0] = max(dp[j][0], (ll)0);
                dp[j][1] = max(dp[j][1], (ll)0);
            }
            else{
                if(j-b[i] == s || j-b[i]+1 == s){
                    dp[j][1] = max(dp[j][1], dp[j-b[i]][0]+a[i]);
                }else{
                    dp[j][0] = max(dp[j][0], dp[j-b[i]][0]+a[i]);
                }
            }
        }
    }

    rep(j,t+1){
        cout << dp[j][0] << endl;
    }


    cout << dp[t][1] << endl;
}