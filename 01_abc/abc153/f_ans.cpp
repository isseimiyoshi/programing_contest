#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int main()
{
    int n; cin >> n;
    ll d, a; cin >> d >> a;
    vector<P> p(n);
    rep(i,n) cin >> p[i].first >> p[i].second;

    sort(p.begin(), p.end());

    queue<pair<ll,ll> > q;
    ll tot = 0;
    ll ans = 0;
    rep(i,n){
        ll x = p[i].first;
        ll h = p[i].second;
        while(q.size() && q.front().first < x){
            tot -= q.front().second;
            q.pop();
        }
        h -= tot;
        if(h>0){
            ll cnt = (h-1)/a + 1;
            ans += cnt;
            ll damage = cnt*a;
            tot += damage;
            q.emplace(x+2*d, damage);
        }
    }
    cout << ans << endl;
}