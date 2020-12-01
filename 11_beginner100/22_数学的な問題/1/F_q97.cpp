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

ll N, M;

ll f(int x){
    ll res = 0;
    while(x % 2 == 0){
        res++;
        x /= 2;
    }
    return res;
}

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a/gcd(a, b)*b;
}

int main()
{
    cin >> N >> M;
    int a[N];
    rep(i,N){
        int ai; cin >> ai;
        if(ai % 2 == 1){
            cout << 0 << endl;
            return 0;
        }
        ai /= 2;
        a[i] = ai;
    }
    int t = f(a[0]);
    rep(i,N){
        if(f(a[i]) != t){
            cout << 0 << endl;
            return 0;
        }
        a[i] >>= t;
    }
    M >>= t;
    ll lc = 1;
    rep(i,N){
        lc = lcm(lc, a[i]);
        if(lc > M){
            cout << 0 << endl;
            return 0;
        }
    }
    // cout << lc << endl;
    ll m_lc = M / lc;
    if(m_lc % 2 == 0){
        cout << m_lc / 2 << endl;
    }else{
        cout << (m_lc+1)/2 << endl;
    }

}