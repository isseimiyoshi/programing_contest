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

const int MAX_N = 105;
const int MAX_K = 100010;

int n, k; 
int a[MAX_N];
int dp[MAX_N][MAX_K];

void init(){
    rep(i,MAX_N){
        rep(j,MAX_K){
            dp[i][j] = 0;
        }
    }
}

ll f(int i, int j){
    if(i>=n) return 0;

    rep(l,a[i]+1){
        
    }
}

int main()
{
    cin >> n >> k;
    rep(i,n) cin >> a[i];

    rep(i,n) rep(i,k+1) dp[i][j] = 0;

    rep(i,n){
        rep(j,a[i]+1){
            if()
        }
    }
}