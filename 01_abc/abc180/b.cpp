#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

int main()
{
    int n; cin >> n;
    ll man = 0;
    ll chebi = 0;
    double you = 0;
    ll x[n];
    rep(i,n){
        cin >> x[i];
        man += abs(x[i]);
        chebi = max(chebi, abs(x[i]));
        you += (double)x[i]*(double)x[i];
    }
    you = sqrt(you);
    cout << man << endl;
    printf("%.10f\n", you);
    cout << chebi << endl;
}