#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
using P = pair<ll, ll>;

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A';

/*
string s = "abcdefg"
s.substr(4) "efg"
s.substr(0,3) "abc"
s.substr(2,4) "cdef"

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

const int INF = 1000100100;

int main()
{
    while(true){
        int n, m; cin >> n >> m;
        if(n == 0 && m == 0) break;
        int c[m];
        rep(i,m) cin >> c[i];
        int x[n];
        rep(i,n) cin >> x[i];

        ll dp[n][m];
        rep(i,n) rep(j,m) dp[i][j] = INF;

        int y[m];
        rep(i,m) y[i] = 128;

        rep(i,n){
            int ori_y[m];
            if(i != 0) rep(j,m) ori_y[j] = y[j];
            rep(j,m){
                if(i == 0){
                    y[j] = 128 + c[j]; y[j] = max(0, y[j]); y[j] = min(255, y[j]);
                    dp[0][j] = (x[0]-y[j])*(x[0]-y[j]);
                }else{
                    rep(k,m){
                        int newy = ori_y[k] + c[j]; newy = max(0, newy); newy = min(255, newy);
                        if(dp[i][j] > dp[i-1][k] + (x[i]-newy)*(x[i]-newy)){
                            dp[i][j] = dp[i-1][k] + (x[i]-newy)*(x[i]-newy);
                            y[j] = newy;
                        }
                    }
                }
            }
        }
        /*
        rep(i,n){
            rep(j,m){
                cout << dp[i][j] << " ";
            }cout << endl;
        }
        */
        ll ans = INF;
        rep(j,m) ans = min(dp[n-1][j], ans);
        cout << ans << endl;
    }
    
}