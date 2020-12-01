#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

const int mod = 1000000007;

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    string t[n];
    rep(i,n) cin >> t[i];

    int sn = s.size();

    int dp[sn+1];
    rep(i,sn+1) dp[i] = 0;
    dp[0] = 1;

    rep(i,sn){
        rep(j,n){
            string tj = t[j];
            if(i+1>=(int)tj.length() && s.compare(i+1-(int)tj.length(), (int)tj.length(), tj) == 0){
                dp[i+1] += dp[i+1-(int)tj.length()];
                dp[i+1] %= mod;
            }
        }
    }

    cout << dp[sn] << endl;
}