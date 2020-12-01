#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

const ll mod = 1000000007;

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    string t[n];
    rep(i,n){
        cin >> t[i];
    }

    int sn = s.size();
    ll dp[sn+1];
    rep(i,sn+1) dp[i] = 0;
    dp[0] = 1;

    for(int i=1; i<=sn; i++){
        rep(j,n){
            string tj = t[j];
            if(i>=tj.length() && s.compare(i-tj.length(), tj.length(), tj) == 0){
                dp[i] += dp[i-tj.length()];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[sn] << endl;
}