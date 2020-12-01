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
const ll INF = 1000100100100100100;
const int MAX_N = 405;

int n;
ll a[MAX_N];

ll dp[MAX_N][MAX_N];

void init(){
    rep(i,MAX_N){
        rep(j,MAX_N){
            dp[i][j] = -1;
        }
    }
}


ll f(int l, int r){
    if(dp[l][r]>=0) return dp[l][r];
    if(l == r) return dp[l][r] = 0;

    // どこで切るか全通り試す
    ll res = INF;
    for(int m=l; m<r; m++){
        res = min(res, f(l,m)+f(m+1,r));
    }
    if(l == 0) res = res + a[r];
    else res = res + a[r]-a[l-1];
    return dp[l][r] = res;
}


int main()
{
    cin >> n;
    rep(i,n) cin >> a[i];

    rep(i,n){
        if(i == 0) continue;
        a[i] = a[i-1]+a[i];
    }

    init();

    cout << f(0,n-1) << endl;

}