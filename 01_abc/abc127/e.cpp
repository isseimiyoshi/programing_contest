#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

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

ll kaizyo(int x){
    if(x == 0) return 1;
    return x*kaizyo(x-1);
}

ll comb(ll x, ll y){
    ll x_kai, y_kai, x_y_kai;
    x_kai = kaizyo(x);
    y_kai = kaizyo(y);
    x_y_kai = kaizyo(x-y);
    return (x_kai / (y_kai*x_y_kai));
}

const ll prime = pow(10,9)+7;


int main()
{
    int N, M, K; cin >> N >> M >> K;
    ll pat = comb(N*M-2, K-2);
    ll ans = 0;
    rep(i,M){
        ans += i*(M-i)*(N*N) % prime;
    }
    rep(i,N){
        ans += i*(N-i)*(M*M) % prime;
    }
    ans *= (pat % prime);
    ans %= prime;
    cout << ans << endl;
}