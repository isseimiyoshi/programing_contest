#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

const ll INF = 1000100100100100100;

int main()
{
    ll n, z, w; cin >> n >> z >> w;
    ll a[n];
    rep(i,n) cin >> a[i];

    ll res = -INF;
    if(n-2>=0) res = max(res, abs(a[n-1]-a[n-2]));
    res = max(res, abs(a[n-1]-w));

    cout << res << endl;
}