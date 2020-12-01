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

int main()
{
    string s, t; cin >> s >> t;
    int ss = s.size();
    int ts = t.size();

    ll ans = 0;
    rep(i,ss-ts+1){
        ll cnt = 0;
        rep(j,ts){
            if(s[i+j] == t[j]) cnt++;
        }
        ans = max(cnt, ans);
    }
    cout << ts-ans << endl;
}