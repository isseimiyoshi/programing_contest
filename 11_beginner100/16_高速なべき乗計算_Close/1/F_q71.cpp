#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

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

const ll M = 1000000007;

// べき乗の効率的計算アルゴリズム
ll power(ll m, ll n){
    ll res = 1;
    if(n > 0){
        res = power(m, n/2);
        if(n % 2 == 0) res = (res*res) % M;
        else res = (((res*res)%M) * m) % M;
    }
    return res;
}

int main()
{
    int N, Q; cin >> N >> Q;
    ll a[N]; int c[Q];
    rep(i,N) cin >> a[i];
    rep(i,Q) cin >> c[i], --c[i];
    // 余りの累積和を求める
    ll p[N];
    p[0] = 0;
    for(int i=1; i<N; i++){
        ll dis = power(a[i-1], a[i]);
        p[i] = p[i-1] + dis;
        p[i] = p[i] % M;
        // printf("%dの%d乗は、%d\n", a[i-1], a[i], p[i]);
    }
    ll ans = 0;
    rep(i,Q){
        if(i == 0){
            ans += p[c[i]];
        }else{
            ans += abs(p[c[i]]- p[c[i-1]]);
        }
        ans %= M;
    }
    ans += p[c[Q-1]];
    ans %= M;
    cout << ans << endl;
}