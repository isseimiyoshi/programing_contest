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

const int MAX_N = 100100;

int n;
ll h[MAX_N], s[MAX_N];

int calc(ll l, ll r){
    if(abs(r-l) <= 1) return l;

    ll mid = (l + r) / 2;

    ll lim[n];
    rep(i,n){
        lim[i] = (mid-h[i]) / s[i];
    }
    sort(lim, lim+n);

    bool isok = true;
    rep(i,n){
        if(i > lim[i]){
            isok = false;
        }
    }

    if(isok) return calc(l, mid);
    else return calc(mid+1, r);
}

int main()
{
    cin >> n;
    rep(i,n) cin >> h[i] >> s[i];

    cout << calc(0,INF2) << endl;
}