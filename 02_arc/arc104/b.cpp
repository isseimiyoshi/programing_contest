#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

int main()
{
    int n; cin >> n;
    string s; cin >> s;

    // A, T, C, Gの個数を数える
    int ruiseki[n][4];
    rep(i,n) rep(j,4) ruiseki[i][j] = 0;

    rep(i,n){
        if(s[i] == 'A') ruiseki[i][0]++;
        else if(s[i] == 'G') ruiseki[i][1]++;
        else if(s[i] == 'C') ruiseki[i][2]++;
        else ruiseki[i][3]++;
    }

    rep(i,n){
        if(i == 0) continue;
        rep(j,4){
            ruiseki[i][j] += ruiseki[i-1][j];
        }
    }

    /*
    rep(i,n){
        rep(j,4){
            cout << ruiseki[i][j] << " ";
        }cout << endl;
    }
    */

    int cnt = 0;
    rep(i,n){
        for(int j=i+1; j<n; j++){
            if(i == 0){
                if(ruiseki[j][0] == ruiseki[j][3] && ruiseki[j][1] == ruiseki[j][2]) cnt++;
            }else{
                int an =ruiseki[j][0]-ruiseki[i-1][0];
                int gn =ruiseki[j][1]-ruiseki[i-1][1];
                int cn =ruiseki[j][2]-ruiseki[i-1][2];
                int tn =ruiseki[j][3]-ruiseki[i-1][3];
                if(an == tn && gn == cn) cnt++;
            }
        }
    }
    cout << cnt << endl;
}