#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

const int MAX_N = 20;
const int INF = 1000100100;

int d[MAX_N][MAX_N];
int n;
int dp[(1<<MAX_N)][20];

int rec(int bit, int v){
    if(dp[bit][v] != -1) return dp[bit][v];

    if(bit == (1<<v)) return dp[bit][v] = 0;

    int res = INF;
    int prev_bit = bit & ~(1<<v);

    rep(u,n){
        if(!(prev_bit & (1<<u))) continue;

        res = min(res, rec(prev_bit, u)+d[u][v]);
    }
    return dp[bit][v] = res;
}

int main()
{
    cin >> n;
    int x[n], y[n], z[n];
    rep(i,n) cin >> x[i] >> y[i] >> z[i];

    rep(i,n){
        rep(j,n){
            if(i == j) d[i][j] = 0;
            else{
                d[i][j] = abs(x[j]-x[i]) + abs(y[j]-y[i]) + max(0,z[j]-z[i]);
            }
        }
    }

    rep(bit, (1<<n)){
        rep(i,n){
            dp[bit][i] = -1;
        }
    }

    int res = INF;
    rep(v,n){
        res = min(res, rec((1<<n)-1,v));
    }
    cout << res << endl;
}