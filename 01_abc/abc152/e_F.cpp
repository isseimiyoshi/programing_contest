#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

ll gcd(ll a, ll b){
    if(a%b == 0) return b;
    else return  gcd(b,a%b);
}

ll lcm(ll a, ll b){
    return a*b / gcd(a, b);
}

const ll mod = 1000000007;

int main()
{
    int n; cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];

    ll lcm_n = a[0];
    for(int i=1; i<n; i++){
        lcm_n = lcm(lcm_n, a[i]);
    }
    ll ans = 0;
    rep(i,n){
        ans += lcm_n / a[i];
        ans %= mod;
    }
    cout << ans << endl;
}