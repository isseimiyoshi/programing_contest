#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

int main()
{
    int h, n; cin >> h >> n;
    int a[n];
    rep(i,n) cin >> a[i];

    rep(i,n){
        h -= a[i];
    }
    if(h<=0) cout << "Yes" << endl;
    else cout << "No" << endl;
}