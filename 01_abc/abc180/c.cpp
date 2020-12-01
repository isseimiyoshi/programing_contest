#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

int main()
{
    ll n; cin >> n;
    set<ll> ans;
    ans.insert(1);
    ans.insert(n);
    
    for(ll i=2; i*i<=n; i++){
        if(n%i == 0){
            ans.insert(i);
            ans.insert(n/i);
            
        }
    }
    for(ll res: ans){ cout << res << endl;}
}