#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

const int pmax = 200005;

int main()
{
    vector<int> p;
    rep(i,pmax) p.push_back(i);

    int n; cin >> n;
    rep(_,n){
        int pi; cin >> pi;
        auto itr = lower_bound(p.begin(), p.end(), pi);
        if(*itr == pi){
            int i = distance(p.begin(), itr);
            p.erase(p.begin()+i);
        }
        cout << p[0] << endl;
    }
}