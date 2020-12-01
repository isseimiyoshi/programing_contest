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

const ll MAX_N = 100100;

ll n;
ll h[MAX_N], s[MAX_N];

int main()
{
    cin >> n;
    rep(i,n) cin >> h[i] >> s[i];

    // 2分探索で、風船を割ることのできる限界の高さを探っていく
    ll l = 0;
    ll r = 1000100100100100100;

    
    while(true){
        if(l+1 == r) break;
        ll mid = (l + r) / 2;
        bool isok = true;
        vector<ll> lim;
        rep(i,n){
            // cout << "ok" << endl;
            if(mid < h[i]) isok = false;
            lim.push_back((mid-h[i])/s[i]);
        }
        sort(lim.begin(), lim.end());
        rep(i,n){
            if(lim[i] < i) isok = false;
        }
        // cout << mid << endl;
        if(isok) r = mid;
        else l = mid+1;

    }
    
    cout << l << endl;
}