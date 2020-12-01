#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

// https://atcoder.jp/contests/keyence2020/tasks/keyence2020_c

int main()
{
    int n, k, s; cin >> n >> k >> s;
    rep(i,k){
        cout << s << endl;
    }
    rep(j,n-k){
        if(s == 1000000000) cout << 1 << endl;
        else cout << s+1 << endl;
    }
}