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

ll gcd(ll a, ll b){
    while(b > 0){
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

ll pow(ll x, ll n){
    if(n == 0) return 1;
    ll res = pow(x*x, n/2);
    if(n%2 == 1){
        res *= x;
    }
    return res;
}


int main()
{
    ll n, m; cin >> n >> m;
    ll a[n];
    rep(i,n) cin >> a[i], a[i] /= 2;

    ll t = 0;
    while(true){
        if(a[0] % 2 == 1) break;
        ++t;
        a[0] /= 2;
    }

    ll t2 = pow(2,t);
    bool isok = true;
    rep(i,n-1){
        if(a[i+1] % t2 != 0) isok = false;
        a[i+1] /= t2;
        if(a[i+1] % 2 == 0) isok = false;
    }

    m /= t2;

    ll cnt = 0;
    if(isok){
        ll lcm_num = a[0];
        rep(i,n-1){
            lcm_num = lcm(lcm_num, a[i+1]);
        }
        ll bai = 1;
        while(true){
            if(lcm_num*bai > m) break;
            if(bai % 2 == 1) cnt++;
            bai++;
        }
    }
    
    cout << cnt << endl;
}