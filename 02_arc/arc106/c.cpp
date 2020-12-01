#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

const int INF = 1000000;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> l, r;
    if(n == 1 && m == 0){
        cout << 2 << " " << 3 << endl;
        return 0;
    }
    if(m>=0){
        if(m>=n-1){
            cout << -1 << endl;
            return 0;
        }
        l.push_back(1); r.push_back(INF);
        for(int i=n-1; i>=1; i--){
            l.push_back(2*i);
        }
        rep(i,n-m-1){
            r.push_back(INF+i+1);
        }
        for(int i=n-m-1+1; i<n; i++){
            r.push_back(l[i]+1);
        }

        rep(i,n){
            cout << l[i] << " " << r[i] << endl;
        }
    }else{
        cout << -1 << endl;
    }
}