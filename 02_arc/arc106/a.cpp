#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

const ll MAX_N = 1000100100100100100;

int main()
{
    ll n; cin >> n;
    vector<ll> n3;
    vector<ll> n5;
    n3.push_back(3);
    n5.push_back(5);

    int i3 = 0;
    while(n/n3[i3]>=3){
        n3.push_back(n3[i3]*3);
        i3++;
    }    
    int i5 = 0;
    while(n/n5[i5]>=5){
        n5.push_back(n5[i5]*5);
        i5++;
    }


    rep(j3, i3+1){
        rep(j5, i5+1){
            if(MAX_N-n3[j3] < n5[j5]){
                cout << -1 << endl;
                return 0;
            }
            if(n == n3[j3]+n5[j5]){
                cout << (j3+1) << " " << (j5+1) << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}