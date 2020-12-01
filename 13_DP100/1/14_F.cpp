#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

// 文字列sをある位置で区切ってL,Rと分けたときの最長共通部分列が答え

const int INF = 1000100100;

int f(string L, string R){
    int ln = L.size();
    int rn = R.size();

    int dp[ln+1][rn+1];
    rep(i,ln+1) rep(j,rn+1) dp[i][j] = 0;

    rep(i,ln){
        rep(j,rn){
            if(L[i] == R[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    return dp[ln][rn];
}

int main()
{
    int n; cin >> n;
    string s; cin >> s;

    int ans = INF;
    rep(i,n){
        string L = "";
        string R = "";
        rep(j,i) L += s[j];
        for(int k=i; k<n; k++) R += s[k];

        ans = min(ans, n-2*f(L, R));
    }
    cout << ans << endl;
}