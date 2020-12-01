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

const ll MAX_H = 1000100100100100100;

const ll MAX_N = 1000100;

ll n;
ll h[MAX_N], s[MAX_N];

bool islimit(ll x){
    ll lim[n];
    rep(i,n){
        if(x-h[i] < 0) return false;
        lim[i] = (x-h[i])/s[i];
    }

    sort(lim, lim+n);

    rep(i,n) if(i > lim[i]) return false;
    return true;
}

ll binary_search(){
    ll l = 0, r = MAX_H;
    while(l < r){
        ll mid = (l + r) / 2;
        if(islimit(mid)) r = mid;
        else l = mid+1;
    }
    return l;
}

int main()
{  
    cin >> n;
    rep(i,n) cin >> h[i] >> s[i];

    cout << binary_search() << endl;
}