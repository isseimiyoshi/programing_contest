#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

const ll max_x = 1000000000;

int main()
{
    ll n, d, a; cin >> n >> d >> a;
    vector<pair<ll,ll> > c;
    vector<pair<ll,ll> > cnt_min;
    rep(i,n){
        ll xi, hi; cin >> xi >> hi;
        c.push_back(make_pair(hi,xi));
        cnt_min.push_back(make_pair(hi,0));
    }

    sort(c.begin(), c.end());
    sort(cnt_min.begin(), cnt_min.end());

    rep(i,n){
        ll hi = c[i].first;
        ll xi = c[i].second;

        ll cnt;
        if(xi%a == 0) cnt = xi/a;
        else cnt = xi/a + 1;

        cnt_min[i].second += cnt;
        auto itr = lower_bound(cnt_min.begin(), cnt_min.end(), hi+2*d);
        ll ind = distance(cnt_min.begin(), itr);
        cnt_min[ind+1].second = cnt_min[ind+1].second - cnt;
    }

    rep(i,n){
        if(i == 0) continue;
        cnt_min[i].second = cnt_min[i].second + cnt_min[i-1].second;
    }

    ll ans = 0;
    rep(i,n){
        ll hi = c[i].first;
        ll xi = c[i].second;

        ll cnt;
        if(xi%a == 0) cnt = xi/a;
        else cnt = xi/a + 1;


    }
}