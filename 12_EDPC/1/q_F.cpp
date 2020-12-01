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

const int MAX_N = 200200;

ll n;
ll h[MAX_N];
ll a[MAX_N];

ll dp[MAX_N];

void init(){
    rep(i,MAX_N){
        dp[i] = 0;
    }
}

ll f(ll l, ll nex_h){
    if(l<0) return 0;
    if(dp[l]>0) return dp[l];

    ll res = 0;
    if(h[l]>nex_h){
        res = f(l-1, nex_h);
    }else{
        res = max(f(l-1,nex_h), f(l-1, h[l])+a[l]);
    }
    return dp[l] = res;
}

int main()
{   
    cin >> n;
    rep(i,n) cin >> h[i];
    rep(i,n) cin >> a[i];

    init();
    f(n-1,INF);
    cout << dp[n-1] << endl;
}