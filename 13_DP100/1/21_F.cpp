#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int main()
{
    ll n, d; cin >> n >> d;

    ll cnt[3] = {0, 0, 0};
    ll wv[3] = {2, 3, 5};
    rep(i,3){
        ll w = wv[i];
        while(n%w == 0){
            n /= w;
            cnt[i]++;
        }
    }

    if(n!=1){
        cout << 0 << endl;
        return 0;
    }

    
}