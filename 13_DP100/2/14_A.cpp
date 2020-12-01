#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

const int INF = 1000100100;

int main()
{
    int n; cin >> n;
    string s; cin >> s;

    int ans = INF;

    rep(i,n){
        string t = "";
        string u = "";
        rep(j,i) t += s[j];
        for(int j=i; j<n; j++) u += s[j];

        int tn = t.size();
        int un = u.size();

        int dp[tn+1][un+1];
        rep(j,tn+1) rep(k,un+1) dp[j][k] = 0;
        rep(j,tn) rep(k,un){
            if(t[j] == u[k]) dp[j+1][k+1] = dp[j][k]+1;
            else dp[j+1][k+1] = max(dp[j+1][k], dp[j][k+1]);
        }

        int res = n - dp[tn][un]*2;

        ans = min(ans, res);
    }

    cout << ans << endl;
}