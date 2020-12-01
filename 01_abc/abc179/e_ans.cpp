#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int main()
{
    ll n, x, m; cin >> n >> x >> m;
    vector<int> id(m,-1);
    vector<int> a;
    int len = 0;
    ll tot = 0;
    while(id[x] == -1){
        a.push_back(x);
        id[x] = len;
        len++;
        tot += x;
        x = (x*x)%m;
    }
    // ループ周期
    int c = len - id[x];
    // ループ周期内の要素のトータル
    ll s = 0;
    for(int i = id[x]; i<len; ++i) s += a[i];

    ll ans = 0;
    if(n<=len){
        rep(i,n) ans += a[i];
    }else{
        ans += tot;
        n -= len;
        ans += s*(n/c);
        n %= c;
        rep(i,n) ans += a[id[x]+i];
    }
    cout << ans << endl;
    return 0;
}