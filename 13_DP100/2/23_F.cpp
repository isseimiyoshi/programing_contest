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
    rep(i,m){ cin >> x[i] >> y[i]; --x[i], --y[i];}

    /*
        観客情報の使い方
        観客情報に矛盾する状況を飛ばすようなフラグを作成するため
        あとは普通のDPをすれば、場合の数を数えることができる
    */
    int flag[(1<<n)];
    rep(i,(1<<n)){
        flag[i] = true;
        rep(j,m){
            // 観客情報に矛盾、のちの計算を行わないようフラグを取り下げる
            if((i&(1<<x[j])) == 0 && (i&(1<<y[j])) != 0) flag[i] = false;
        }
    }

    ll dp[(1<<n)];
    rep(i,(1<<n)) dp[i] = 0;
    dp[0] = 1;

    rep(i,(1<<n)){
        // 観客情報に矛盾したBIT状態
        if(flag[i] == false) continue;

        rep(j,n){
            /*
                現在の状況ですでにj番目のうさぎがゴールしており、
                現在の状況からj番目のうさぎがまだゴールしていない状況がありえる場合、
                現在の状況にj番目のうさぎがまだゴールしていない場合の数を足す
            */
            if((i&(1<<j)) != 0 && flag[i^(1<<j)] == true){
                dp[i] += dp[i^(1<<j)];
            }
        }
    }
    cout << dp[(1<<n)-1] << endl;
}