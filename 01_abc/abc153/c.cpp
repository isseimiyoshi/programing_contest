#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

int main()
{
    int n, k; cin >> n >> k;
    int h[n];
    rep(i,n) cin >> h[i];
    sort(h,h+n);
    ll ans = 0;
    rep(i,n-k){
        ans += h[i];
    }
    cout << ans << endl;
}