#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

int main()
{
    int n, m; cin >> n >> m;
    int x[m], y[m];
    rep(i,m) {cin >> x[i] >> y[i]; --x[i], --y[i];}

    int flag[(1<<n)];
    rep(i,(1<<n)){
        flag[i] = true;
        rep(j,m){
            // 観客から提示された先着順情報に矛盾する場合は、のちに計算を行わないようにする
            if((i&(1<<x[j])) == 0 && (i&(1<<y[j])) != 0) flag[i] = false;
        }
    }

    ll dp[(1<<n)];
    rep(i,(1<<n)) dp[i] = 0;
    dp[0] = 1;

    rep(i,(1<<n)){
        if(flag[i] == false) continue;

        rep(j,n){
            if((i&(1<<j)) != 0 && flag[i^(1<<j)] == true){
                dp[i] += dp[i^(1<<j)];
            }
        }
    }
    cout << dp[(1<<n)-1] << endl;
}