#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

const int INF = 1000000000;

int main()
{
    int n; cin >> n;
    int p[n];
    rep(i,n) cin >> p[i];

    int minn = INF;

    int ans = 0;
    rep(i,n){
        minn = min(p[i], minn);
        if(p[i]<=minn){
            ans++;
        }
    }
    cout << ans << endl;
}