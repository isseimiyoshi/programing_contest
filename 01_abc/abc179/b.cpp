#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

int main()
{
    int n; cin >> n;
    int d1[n], d2[n];
    rep(i,n) cin >> d1[i] >> d2[i];

    int cnt = 0;
    bool ok = false;
    rep(i,n){
        if(d1[i] == d2[i]) cnt++;
        else cnt = 0;
        if(cnt == 3) ok = true;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}