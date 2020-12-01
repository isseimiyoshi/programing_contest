#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

const int MAX_N = 2010;
const int INF = 1000100100;

int n;
int a[MAX_N];
int dp[MAX_N][2];

void init(){
    rep(i,MAX_N){
        rep(j,2){
            dp[i][j] = -1;
        }
    }
}

int f(int id, int turn, int x, int y){
    if(id == n) return abs(x-y);

    if(dp[id][turn]>=0) return dp[id][turn];

    if(turn == 0){
        int ma = -1;
        for(int i=id; i<n; i++) ma = max(ma, f(i+1, 1-turn, a[i], y));
        return dp[id][turn] = ma;
    }else{
        int mi = INF;
        for(int i=id; i<n; i++) mi = min(mi, f(i+1, 1-turn, x, a[i]));
        return dp[id][turn] = mi;
    }
}

int main()
{
    cin >> n;
    int x, y; cin >> x >> y;
    rep(i,n) cin >> a[i];

    init();

    f(0,0,x,y);

    cout << dp[0][0] << endl;
}