#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

const int mod = 10000;

int main()
{
    int n,k; cin >> n >> k;

    int p[n];
    rep(i,n) p[i] = -1;
    rep(i,k){
        int ai, bi; cin >> ai >> bi; --ai,--bi;
        p[ai] = bi;
    }

    ll dp[n][3][2];
    rep(i,n) rep(j,3) rep(k,2) dp[i][j][k] = 0;
    if(p[0] != -1) dp[0][p[0]][0] = 1;
    else{
        rep(j,3) dp[0][j][0] = 1;
    }

    for(int i=1; i<n; i++){
        if(p[i] == -1){
            rep(j,3){
                dp[i][j][1] = dp[i-1][j][0];
                rep(k,3){
                    if(j != k){
                        rep(l,2){
                            dp[i][j][0] += dp[i-1][k][l];
                        }
                    }
                }
            }
        }else if(p[i] == 0){
            dp[i][0][1] = dp[i-1][0][0];
            rep(j,2){
                dp[i][0][0] += dp[i-1][1][j];
                dp[i][0][0] += dp[i-1][2][j];
            }
        }else if(p[i] == 1){
            dp[i][1][1] = dp[i-1][1][0];
            rep(j,2){
                dp[i][1][0] += dp[i-1][0][j];
                dp[i][1][0] += dp[i-1][2][j];
            }
        }else{
            dp[i][2][1] = dp[i-1][2][0];
            rep(j,2){
                dp[i][2][0] += dp[i-1][0][j];
                dp[i][2][0] += dp[i-1][1][j];
            }
        }
        rep(j,3) rep(k,2) dp[i][j][k] %= mod;
    }
    ll ans = 0;
    rep(j,3){
        rep(k,2){
            ans += dp[n-1][j][k];
            ans %= mod;
        }
    }
    cout << ans << endl;
}
    