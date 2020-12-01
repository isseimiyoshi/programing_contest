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
    int d, n; cin >> d >> n;
    int t[d];
    rep(i,d) cin >> t[i];
    vector<tuple<int, int, int> > cloth;
    rep(i,n){
        int ai, bi, ci; cin >> ai >> bi >> ci;
        cloth.push_back(make_tuple(ai, bi, ci));
    }

    ll dp[d][n];
    rep(i,d) rep(j,n) dp[i][j] = 0;

    rep(j,n){
        int a, b, c; tie(a, b, c) = cloth[j];
        if(t[0] < a || b < t[0]) dp[0][j] = -1;
    }

    for(int i=1; i<d; i++){
        rep(j,n){
            int a, b, c; tie(a, b, c) = cloth[j];
            if(t[i] < a || b < t[i]){
                dp[i][j] = -1;
                continue;
            }
            rep(k,n){
                int ak, bk, ck; tie(ak, bk, ck) = cloth[k];
                if(dp[i-1][k] == -1) continue;
                dp[i][j] = max(dp[i][j], dp[i-1][k] + abs(c-ck));
            }
        }
    }
    
    
    ll ans = 0;
    rep(i,n) if(dp[d-1][i] != -1) ans = max(ans, dp[d-1][i]);
    cout << ans << endl;
}