#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const ll INF = 1000100100100100100;

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

const int MAX_N = 410;

int n; 
ll a[MAX_N];
ll dp[MAX_N][MAX_N];
ll ruiseki[MAX_N];

void init(){
    rep(i,MAX_N){
        rep(j,MAX_N){
            dp[i][j] = INF;
        }
    }
}

ll f(int l, int r){
    if(dp[l][r] != INF) return dp[l][r];

    if(l == r) return dp[l][r] = 0;

    ll res = INF;
    for(int m=l; m<r; m++){
        res = min(res, f(l,m)+f(m+1,r));
    }
    return dp[l][r] = res + ((l == 0) ? ruiseki[r] : (ruiseki[r]-ruiseki[l-1]));
}

int main()
{
    cin >> n;
    rep(i,n) cin >> a[i];

    rep(i,n){
        if(i == 0) ruiseki[i] = a[i];
        else{
            ruiseki[i] = ruiseki[i-1]+a[i];
        }
    }

    init();

    f(0,n-1);

    /*
    rep(i,n){
        rep(j,n){
            cout << dp[i][j] << " ";
        }cout << endl;
    }
    */

    cout << dp[0][n-1] << endl;
}