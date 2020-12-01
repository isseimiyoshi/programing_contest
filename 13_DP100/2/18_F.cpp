#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int main()
{
    int n, p; cin >> n >> p;
    vector<P> ab;
    rep(i,n){
        int ai, bi; cin >> ai >> bi;
        ab.push_back(make_pair(ai,bi));
    }
    // 降順ソート
    sort(ab.begin(), ab.end());
    reverse(ab.begin(), ab.end());

    int dp[n+1][p+1];
    rep(i,n+1) rep(j,p+1) dp[i][j] = 0;

    int ma[n];
    ma[n-1] = ab[n-1].second;
    for(int i=n-2; i>=0; i--){
        ma[i] = max(ma[i+1], ab[i].second);
    }

    int ans = 0;
    rep(i,n){
        rep(j,p+1){
            if(j<ab[i].first) dp[i+1][j] = dp[i][j];
            else{
                dp[i+1][j] = max(dp[i][j], dp[i][j-ab[i].first]+ab[i].second);
            }
            ans = max(dp[i][j]+ma[i], ans);
        }
    }

    cout << ans << endl;


}