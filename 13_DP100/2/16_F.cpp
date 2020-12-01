#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int main()
{
    int n; cin >> n;
    string s; cin >> s;

    int dp[n][n];

    rep(j,n){
        if(s[n-1] == s[j]) dp[n-1][j] = 1;
        else dp[n-1][j] = 0;
    }

    for(int i=n-2; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(s[i] == s[j]){
                if(j+1 == n) dp[i][j] = 1;
                else dp[i][j] = dp[i+1][j+1]+1;
            }else{
                dp[i][j] = 0;
            }
        }
    }

    int ans = 0;
    rep(i,n){
        rep(j,n){
            int res = min(abs(i-j), dp[i][j]);
            ans = max(res, ans);
        }
    }
    cout << ans << endl;
}