#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

const int MAX_N = 5005;

int dp[MAX_N][MAX_N];

int main()
{
    int n; cin >> n;
    string s; cin >> s;

    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(s[i] != s[j]) continue;
            dp[i][j] = dp[i+1][j+1]+1;
        }
    }

    int res = 0;
    rep(i,n) rep(j,n){
        if(i>=j) continue;  // i > j
        int ans = min(j-i, dp[i][j]);
        res = max(ans, res);
    }
    cout << res << endl;
}