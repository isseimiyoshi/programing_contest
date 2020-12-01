#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

int main()
{
    ll h; cin >> h;
    ll add = 1;
    ll ans = 0;
    while(h > 1){
        ans += add;
        h /= 2;
        add *= 2;
    }
    ans += add;
    cout << ans << endl;
}