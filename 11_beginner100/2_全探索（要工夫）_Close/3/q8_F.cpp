#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const int INF = 1000100100;

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

const ll INF2 = 1000100100100100100;

int main()
{
    int n; cin >> n;
    vector<ll> ab;
    ll a[n], b[n];
    rep(i,n){
        int ai, bi; cin >> ai >> bi;
        --ai, --bi;
        a[i] = ai, b[i] = bi;
        ab.push_back(ai);
        ab.push_back(bi);
    }

    ll ans = INF2;
    rep(i,(int)ab.size()){
        rep(j,(int)ab.size()){
            ll res = 0;
            rep(k,n){
                res += abs(a[k]-ab[i]) + b[k]-a[k] + abs(b[k]-ab[j]);
            }
            ans = min(res, ans);
        }
    }
    cout << ans << endl;
}