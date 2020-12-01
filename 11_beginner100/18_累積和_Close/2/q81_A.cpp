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
    int a[n], b[n];
    rep(i,n) cin >> a[i] >> b[i];

    int kn = 1000002;
    int k[kn];
    rep(i,kn) k[i] = 0;

    rep(i,n){
        k[a[i]]++;
        k[b[i]+1]--;
    }
    rep(i,kn){
        if(i == 0) continue;
        k[i] = k[i] + k[i-1];
    }

    int res = 0;
    int ans = 0;
    rep(i,kn){
        if(ans < k[i]){
            res = i;
            ans = k[i];
        }
    }
    cout << ans << endl;
}