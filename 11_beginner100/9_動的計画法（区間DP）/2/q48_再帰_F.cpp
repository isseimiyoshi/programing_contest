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

const int MAX_N = 305;

int dp[MAX_N][MAX_N];
int w[MAX_N];

void init(){
    rep(i,MAX_N){
        w[i] = -1;
        rep(j,MAX_N){
            dp[i][j] = -1;
        }
    }
}

//　メモ化再帰はトップダウン（広い幅　→　狭い幅）で深く計算していき、計算結果を上流に返す方法である
int rec(int l, int r){
    if(dp[l][r] != -1) return dp[l][r]; // すでにdp[l][r]が計算済みの場合

    if(abs(l-r) <= 1) return 0; // もうこれ以上取り除けない

    int res = 0;
    // パターン１（両端の差が１以下　かつ　間のブロックが全てはじき出せる場合）
    if(abs(w[l]-w[r-1]) <= 1 && rec(l+1, r-1) == r-l-2){
        res = r-l;
    }

    // パターン２（対象区間全てのブロックは取り出せなさそうなので、その区間で取り出せるブロック数の最大値を計算する)
    for(int mid=l+1;mid<=r-1; mid++){
        res = max(rec(l,mid) + rec(mid,r), res);
    }
    return dp[l][r] = res;
}

int main()
{
    while(true){
        int n; cin >> n;
        if(n == 0) break;

        init();

        rep(i,n) cin >> w[i];

        cout << rec(0,n) << endl;
    }
}