#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

const int maxsum = 10000;

int main()
{
    int isP[maxsum+1];
    rep(i,maxsum+1) isP[i] = 0;
    isP[0] = 1;

    int n; cin >> n;
    int p[n];
    rep(i,n) cin >> p[i];

    rep(i,n){
        for(int j=maxsum; j>=0; j--){
            if(j>=p[i] && isP[j-p[i]] == 1){
                isP[j] = 1;
            }
        }
    }
    int ans = 0;
    rep(i,maxsum+1){
        if(isP[i] == 1) ans++;
    }
    cout << ans << endl;
}