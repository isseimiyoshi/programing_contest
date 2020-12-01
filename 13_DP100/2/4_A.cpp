#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;


int main()
{
    int n, k; cin >> n >> k;
    int r, s, p; cin >> r >> s >> p;

    map<char, int> m;
    m['r'] = p;
    m['s'] = r;
    m['p'] = s;

    string t; cin >> t;

    int no[n];
    rep(i,n) no[i] = 0;

    int ans = 0;
    rep(i,n){
        if(i<k) ans += m[t[i]];
        else{
            if(t[i] == t[i-k] && no[i-k] == 0){
                no[i] = 1;
            }else{
                ans += m[t[i]];
            }
        }
    }
    cout << ans << endl;
}