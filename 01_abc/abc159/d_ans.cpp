#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

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

ll choose2(ll x){
    return x*(x-1)/2;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) a[i]--;
    vector<int> cnt(n);
    rep(i,n) cnt[a[i]]++;
    ll tot = 0;
    rep(i,n){
        tot += choose2(cnt[i]);
    }

    rep(i,n){
        ll ans = tot;
        ans -= choose2(cnt[a[i]]);
        ans += choose2(cnt[a[i]]-1);
        cout << ans << endl;
    }


}