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


int main()
{
    ll h, w, k, v; cin >> h >> w >> k >> v;
    ll a[h][w];
    rep(i,h) rep(j,w) cin >> a[i][j];

    ll sum[h][w];

    rep(i,h){
        rep(j,w){
            if(i == 0){
                if(j == 0) sum[i][j] = a[i][j];
                else sum[i][j] = sum[i][j-1] + a[i][j];
            }else{
                if(j == 0) sum[i][j] = sum[i-1][j] + a[i][j];
                else{
                    sum[i][j] = a[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
                }
            }
        }
    }

    ll ans = 0;
    rep(sh, h) rep(sw, w){
        for(int gh=sh; gh<h; gh++) for(int gw=sw; gw<w; gw++){
            ll toti;
            ll house = (gh-sh+1)*(gw-sw+1);
            if(sh == 0 && sw == 0){
                toti = sum[gh][gw];
            }else if(sh == 0){
                toti = sum[gh][gw] - sum[gh][sw-1];
            }else if(sw == 0){
                toti = sum[gh][gw] - sum[sh-1][gw];
            }else{
                toti = sum[gh][gw] - sum[gh][sw-1] - sum[sh-1][gw] + sum[sh-1][sw-1];
            }
            if((toti+house*k) <= v){
                ans = max(ans, house);
                // printf("%d %d\n", toti, house);
            }
        }
    }
    cout << ans << endl;
}