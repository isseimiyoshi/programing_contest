#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

const int d2[6] = {0, 1, 0, 2, 0, 1};
const int d3[6] = {0, 0, 1, 0, 0, 1};
const int d5[6] = {0, 0, 0, 0, 1, 0};

int main()
{
    ll n, d; cin >> n >> d;

    vector<int> cnt;
    for(auto const v: {2, 3, 5}){
        int c = 0;
        while(d % v == 0){
            d /= v;
            c++;
        }
        cnt.push_back(c);
    }
    

    // Dの倍数がサイコロの目の積に存在しないことが確定した場合
    if(d != 1){
        cout << 0 << endl;
        return 0;
    }

    int cnt2 = cnt[0];
    int cnt3 = cnt[1];
    int cnt5 = cnt[2];

    double dp[cnt2+1][cnt3+1][cnt5+1];
    rep(i,cnt2+1) rep(j,cnt3+1) rep(k,cnt5+1) dp[i][j][k] = 0.0;

    dp[0][0][0] = 1;

    rep(lp, n){
        double nxt[cnt2+1][cnt3+1][cnt5+1];
        rep(i,cnt2+1) rep(j,cnt3+1) rep(k,cnt5+1) nxt[i][j][k] = 0.0;

        rep(x,cnt2+1){
            rep(y,cnt3+1){
                rep(z,cnt5+1){
                    rep(i,6){
                        // インプットDを素因数分解した要素以上に素因数を追加する場合はすでにDの倍数になっているので、数を足していく運用にする
                        const int nx = min(cnt2, x + d2[i]);
                        const int ny = min(cnt3, y + d3[i]);
                        const int nz = min(cnt5, z + d5[i]);
                        nxt[nx][ny][nz] += dp[x][y][z]/6;
                    }
                }
            }
        }
        // DPテーブルを一時的なものから更新する
        rep(i,cnt2+1) rep(j,cnt3+1) rep(k,cnt5+1) dp[i][j][k] = nxt[i][j][k];
    } 

    cout << dp[cnt2][cnt3][cnt5] << endl;
}