#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

int main()
{
    int n; cin >> n;
    ll ans = 0;
    for(int i=1; i<=n; i++){
        if(n%i == 0) ans += n/i-1;
        else ans += n/i;
    }
    cout << ans << endl;
}