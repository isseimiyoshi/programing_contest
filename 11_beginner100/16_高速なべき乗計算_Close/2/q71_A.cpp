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

const ll MOD = 1000000007;

// 繰り返し自乗法で計算回数をlogn回に短縮する
ll pow(ll x, ll n){
    if(n == 0) return 1;
    ll res = pow(x*x % MOD, n/2);
    if(n%2 == 1){
        res = res * x % MOD;
    }
    return res;
}


int main()
{
    ll n, q; cin >> n >> q;
    ll a[n], c[q];
    rep(i,n) cin >> a[i];
    rep(i,q) cin >> c[i], c[i]--;

    ll sum[n];
    rep(i,n) sum[i] = 0;
    sum[0]++;
    sum[c[0]]--;
    rep(i,q){
        if(i == q-1){
            sum[0]++;
            sum[c[i]]--;
        }else{
            ll a = c[i], b = c[i+1];
            if(a > b) swap(a, b);
            sum[a]++;
            sum[b]--;
        }
    }

    rep(i,n){
        if(i == 0) continue;
        sum[i] = sum[i] + sum[i-1];
    }

    ll dis[n-1];
    rep(i,n-1){
        dis[i] = pow(a[i], a[i+1]);
    }

    ll ans = 0;
    rep(i,n-1){
        ans += dis[i]*sum[i]%MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}