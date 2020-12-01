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

const int MOD = 1000000007;

ll pow(ll m, ll n){
    if(n == 0) return 1;
    ll res = pow((m*m)%MOD, n/2);
    if(n%2 == 1){
        res = res*m % MOD;
    }
    return res;
}

int main()
{
    ll n, m; cin >> m >> n;
    ll res = pow(m, n);
    cout << res << endl;
}