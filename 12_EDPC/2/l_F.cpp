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

const int MAX_N = 3010;

int n;
ll a[MAX_N];

ll dp[MAX_N][MAX_N];

void init(){
    rep(i,MAX_N) rep(j,MAX_N) dp[i][j] = 0;
}

ll f(int l, int r){
    if(dp[l][r]) return dp[l][r];
    if(l == r){
        dp[l][r] = a[l];
    }else{
        dp[l][r] = max(a[l]-f(l+1,r), a[r]-f(l,r-1));
    }
    return dp[l][r];
}

int main()
{   
    cin >> n;
    rep(i,n) cin >> a[i];

    init();

    f(0,n-1);

    cout << dp[0][n-1] << endl;
}