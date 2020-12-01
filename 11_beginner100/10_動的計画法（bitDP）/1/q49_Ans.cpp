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

/*

5 8
0 1 3
1 2 5
2 3 5
3 4 3
4 0 7
0 3 4
2 0 4
4 1 6

*/

const int MAX_N = 18;
const int INF = 1000100100;

int n;
int d[MAX_N][MAX_N];

int dp[1 << MAX_N][MAX_N];  // メモ化テーブル

int s;

// すでに訪れた頂点集合がS、現在位置がv
int rec(int S, int v){
    if(dp[S][v] >= 0) return dp[S][v];  // すでに探索済み

    // すべて訪れた状態　かつ　現在位置がスタート地点の場合
    if(S == (1 << n)-1 && v == s) return dp[S][v] = 0;  // すべての頂点を訪れて戻ってきた

    int res = INF;

    rep(u,n){
        if(!(S >> u & 1)){  // まだ位置uに訪れていなければ
            // 現在位置からどの点に訪れることで最終的にコストが小さくなるか計算している
            res = min(res, rec(S | 1 << u, u) + d[v][u]);   // 次にuに移動する  // S | 1<<u これはビットOR演算を行っている
        }
    }

    return dp[S][v] = res;
}

int main()
{
    int E; cin >> n >> E;
    rep(i,MAX_N) rep(j,MAX_N) d[i][j] = INF;
    rep(i,E){
        int s, t, dis; cin >> s >> t >> dis;
        d[s][t] = dis;
    }
    memset(dp, -1, sizeof(dp));

    int res = INF;

    // cout << rec(0,0) << endl;

    rep(i,n){
        s = i;
        res = min(res, rec(0, s));
    }


    if(res > 100000000) cout << -1 << endl;
    else cout << res << endl;
}