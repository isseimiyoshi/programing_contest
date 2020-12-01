#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int main()
{
    int n, k; cin >> n >> k;
    int a[n];
    rep(i,n) cin >> a[i];

    bool dp[k+1];
    rep(i,k+1) dp[i] = false;

    rep(j,k+1){
        rep(i,n) if(j-a[i]>=0 && dp[j-a[i]] == false) dp[j] = true;
    }

    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
}