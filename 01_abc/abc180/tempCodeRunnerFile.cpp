#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

int main()
{
    ll x, y, a, b; cin >> x >> y >> a >> b;

    vector<ll> a_x;
    a_x.push_back(x);
    int i = 0;
    while(y/a_x[i]>=a){
        a_x.push_back(a_x[i]*a);
        i++;
    }
    a_x.push_back(a_x[i]*a);

    if(x>=b){
        cout << (y-x)/b << endl;
    }else{
        ll z = distance(a_x.begin(), upper_bound(a_x.begin(), a_x.end(), b));
        if(a_x[z]>a_x[z-1]+b) z -= 1;

        ll ans = z;

        y -= a_x[z];
        if(y%b == 0) ans += (y/b)-1;
        else ans += y/b;

        cout << ans << endl;
    }
}