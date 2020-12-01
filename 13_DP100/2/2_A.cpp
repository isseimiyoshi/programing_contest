#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int f(int x){
    int ans = x;
    while(x>0){
        ans += x%10;
        x /= 10;
    }
    return ans;
}


int main()
{
    int n; cin >> n;

    int dp[n+1];
    rep(i,n+1) dp[i] = 0;
    dp[n] = 1;

    for(int i=n-1; i>0; i--){
        int res = f(i);
        if(res>n || dp[res] == 0) continue;
        dp[i] = 1;
    }

    int ans = 0;
    rep(i,n+1) ans += dp[i];
    cout << ans << endl;
}