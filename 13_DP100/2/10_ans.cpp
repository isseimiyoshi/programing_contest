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

    int dp[n][2];
    rep(i,n){
        dp[i][0] = dp[i][1] = 1;
        rep(j,i){
            if(a[j]>a[i]) dp[i][0] = max(dp[j][0], dp[j][1]+1);
            if(a[j]<a[i]) dp[i][1] = max(dp[j][0]+1, dp[j][1]);
        }
    }
    int ans = max(dp[n-1][0], dp[n-1][1]);
    if(ans<3) cout << 0 << endl;
    else cout << ans << endl;
}