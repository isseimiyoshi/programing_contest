#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int main()
{
    ll x, y, a, b; cin >> x >> y >> a >> b;
    ll ans = 0;
    while(true){
        if(y/a<x) break;    // a*xのオーバーフロー対策
        if(a*x >= y) break;
        if(a*x>=x+b) break;
        x *= a;
        ans++;
    }
    ans += (y-x-1)/b;
    cout << ans << endl;
}