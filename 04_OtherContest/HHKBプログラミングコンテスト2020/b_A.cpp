#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

const int eh[2] = {0, 1};
const int ew[2] = {1, 0};

int main()
{
    int h, w; cin >> h >> w;
    int a[h][w];
    rep(i,h){
        rep(j,w){
            char moji; cin >> moji;
            if(moji == '.') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    
    int ans = 0;
    rep(i,h){
        rep(j,w){
            if(a[i][j] == 1) continue;
            rep(k,2){
                int nh = i + eh[k];
                int nw = j + ew[k];
                if(nh<0 || nw<0 || nh>=h || nw>=w) continue;
                if(a[nh][nw] == 0) ans++;
            }
        }
    }
    cout << ans << endl;
}