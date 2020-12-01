#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
void chmin(int& x, int y) { x = min(x,y); }

const int INF = 1000100100;

int main()
{
    int n; cin >> n;
    vector<int> x(n), y(n), z(n);
    rep(i,n) cin >> x[i] >> y[i] >> z[i];
    int n2 = 1<<n;  // すごく使うので定義
    vector<vector<int> > dp(n2, vector<int> (n, INF));  // 初期値を簡単に含めるためにこの書き方にしている

    vector<vector<int> > dist(n,vector<int>(n));    // 初期値はゼロ
    rep(i,n){
        rep(j,n){
            int now = abs(x[i]-x[j]);
            now += abs(y[i]-y[j]);
            now += max(0,z[j]-z[i]);
            dist[i][j] = now;
        }
    }

    // 都市1から1つ進んだ場所にいる
    rep(i,n){
        if(i == 0) continue;
        dp[1<<i][i] = dist[0][i];   // 初期位置の距離は都市1から他の都市への距離
    }

    rep(i,n2) rep(j,n){
        // jからkに向かうため、状態にはjが含まれていて、kが含まれていない場合に処理を続行する
        if(~i>>j&1) continue;   // 状態にjが含まれていない場合  // ~(チルダ)はbitを反転　反転したビットをシフトして、1と比較し、1となればjが存在しなかったことになる
        rep(k,n){   // jからkに向かう処理
            if(i>>k&1) continue;    // 状態にkが含まれている場合
            chmin(dp[i | 1<<k][k], dp[i][j]+dist[j][k]);
        }
    }
    cout << dp[n2-1][0] << endl;

    return 0;
}