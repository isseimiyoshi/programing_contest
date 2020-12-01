#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
using P = pair<ll, ll>;

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A';

/*
string s = "abcdefg"
s.substr(4) "efg"
s.substr(0,3) "abc"
s.substr(2,4) "cdef"

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/


int main()
{
    int n; cin >> n;
    int c[n];
    rep(i,n) cin >> c[i];


    vector<int> res;

    int cnt = 0;
    int ori_c = -1;
    rep(i,n){
        if(ori_c == c[i]){
            res.push_back(cnt);
            ori_c = c[i];
            cnt = 1;
        }else{
            cnt++;
            ori_c = c[i];
        }
        if(i == n-1) res.push_back(cnt);
    }

    ll ans = -1;
    if((int)res.size() == 1) ans = res[0];
    else if((int)res.size() == 2) ans = res[0]+res[1];
    else{
        rep(i,(int)res.size()-2){
            ll sum = res[i]+res[i+1]+res[i+2];
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}