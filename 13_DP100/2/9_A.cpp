#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

const char com[4] = {'A', 'B', 'X', 'Y'};

const int INF = 1000100100;

int main()
{
    int n; cin >> n;
    string s; cin >> s;

    int ans = INF;
    rep(j1,4) rep(j2,4){
        string com1 = "";
        com1 += com[j1];
        com1 += com[j2];
        rep(k1,4) rep(k2,4){
            string com2 = "";
            com2 += com[k1];
            com2 += com[k2];
            if(com1 == com2) continue;

            int dp[n+1];
            rep(i,n+1) dp[i] = 0;
            rep(i,n){
                if(i == 0){dp[i+1] = 1;continue;}
                string str = ""; str += s[i-1]; str += s[i];
                if(str == com1 || str == com2){
                    dp[i+1] = dp[i-1]+1;
                }else{
                    dp[i+1] = dp[i] + 1;
                }
            }

            ans = min(ans, dp[n]);
        }
    }
    cout << ans << endl;

}