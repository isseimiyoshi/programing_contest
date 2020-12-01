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

const int INF = 1000100100, MAX_N = 16;
int dp[(1<<MAX_N)][MAX_N];  // メモ化テーブル　1次元目：訪れた頂点の状態の組み合わせ　2次元目：現在位置

int v, e, s;
int dist[MAX_N][MAX_N];

void init(){
    rep(i,MAX_N){
        rep(j,MAX_N){
            dist[i][j] = INF;
        }
    }
}

int rec(int S, int x){
    if(dp[S][x] >= 0) return dp[S][x];  // 探索済み（これこそメモ化）

    if(S == (1 << v) -1 && x == s) return dp[S][x] = 0;

    int res = INF;

    rep(u, v){
        if(!(S>>u & 1)) res = min(res, rec((1<<u) | S, u) + dist[x][u]);
    }
    
    return dp[S][x] = res;
}

int main()
{
    cin >> v >> e;
    init();
    rep(_,e){
        int s, t, d; cin >> s >> t >> d;
        dist[s][t] = d;
    }

    // cout << "ok" << endl;
    // メモ化テーブルの初期化
    rep(i,(1<<MAX_N)) rep(j,MAX_N) dp[i][j] = -1;
    // cout << "ok" << endl;
    // 状態数をbitで保持して、すべてのbitが1になったときにリターンする
    int ans = INF;

    rep(i,v){
        s = i;
        ans = min(ans, rec(0, s));
    }
    
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}