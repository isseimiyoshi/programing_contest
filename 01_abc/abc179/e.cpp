#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int, int>;

int main()
{
    ll n; cin >> n;
    int x, m; cin >> x >> m;

    int cnt[m];
    rep(i,m) cnt[i] = -1;

    int i = 1;
    int roop = -1;
    int start = -1;
    while(true){
        if(cnt[x] != -1){
            roop = i-cnt[x];
            start = cnt[x];
            break;
        }
        if(i > n) break;
        cnt[x] = i;
        x = x*x%m;
        i++;
    }

    if(roop == -1){
        int ans = 0;
        rep(i,m){
            if(cnt[i] != -1) ans += i;
        }
        cout << ans << endl;
        return 0;
    }else{
        ll ans = 0;
        int add = n % (roop - start);
        rep(i,m){
            if(cnt[i] == -1) continue;
            else if(cnt[i]<start){
                ans += i;
            }else{
                ans += i*((n-start)/roop);
                if(cnt[i]<=(start+add)) ans += i;
            }
        }
        cout << ans << endl;
    }
}