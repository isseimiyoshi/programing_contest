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
    int n, m; cin >> n >> m;
    int p[m];
    rep(i,m) cin >> p[i], --p[i];
    ll A[n-1], B[n-1], C[n-1];
    rep(i,n-1) cin >> A[i] >> B[i] >> C[i];

    ll sum[n];
    rep(i,n) sum[i] = 0;

    rep(i,m-1){
        int a = p[i], b = p[i+1];
        if(a > b) swap(a, b);
        sum[a]++;
        sum[b]--;
        // printf("%d %d\n", a, b);
    }

    rep(i,n){
        if(i == 0) continue;
        sum[i] = sum[i] + sum[i-1];
    }

    ll res = 0;
    rep(i,n-1){
        // cout << sum[i] << endl;
        res += min(A[i]*sum[i], B[i]*sum[i]+C[i]);
    }
    cout << res << endl;
}