#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
using P = pair<ll,ll>;

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

const ll MOD = 1000000007;

int main()
{
    int n; cin >> n;
    ll a[n];
    rep(i,n) cin >> a[i];

    ll sum[n];
    rep(i,n){
        if(i == 0) sum[i] = a[i];
        else{
            sum[i] = sum[i-1] + a[i];
        }
    }
    rep(i,n){
        sum[i] %= MOD;
    }

    ll res = 0;
    rep(i,n-1){
        res += a[i] * (sum[n-1] - sum[i]);
        res %= MOD;
    }
    cout << res << endl;
}