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

const int MAX_AB = 200100;

const ll MOD = 1000000007;

// mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll pow(ll x, ll n){
    if(n == 0) return 1;
    ll res = pow(x*x%MOD, n/2);
    if(n%2 == 1) res = res*x%MOD;
    return res;
}

int main()
{
    ll n, a, b; cin >> n >> a >> b;
    ll coma, comb;
    ll current = n;
    for(ll i=1; i<=MAX_AB; i++){
        if(i == 1){
            if(i == a) coma = current, printf("a=%d: nCa=%d\n", i, coma);
            else if(i == b) comb = current;
            continue;
        }else{

            current = current * (n-i+1) % MOD;
            current = current * modinv(i,MOD) % MOD;
            if(i == a){
                coma = current;
                printf("a=%d: nCa=%d\n", i, coma);
            }
            else if(i == b){
                comb = current;
                printf("b=%d: nCb=%d\n", i, comb);
            }
        }
    }
    ll res = 0;
    res += pow(2,n);
    res -= 1;
    res -= coma;
    res -= comb;
    res %= MOD;
    cout << res << endl;
}