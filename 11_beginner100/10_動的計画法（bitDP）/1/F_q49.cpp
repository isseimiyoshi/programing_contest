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

4
0 8 7 3
8 0 9 1
7 9 0 4
3 1 4 0

*/

const int INF = 1000100100; // 十分に大きな値

int N;
int dist[21][21];

// メモ化再帰
int dp[(1<<20) + 1][21];    // dpテーブルは余裕を持ったサイズにする

int rec(int bit, int v){
    // すでに探索済みであればリターン
    if(dp[bit][v] != -1) return dp[bit][v];

    // 初期値
    if(bit == (1<<v)){
        return dp[bit][v] = 0;
    }

    // 答えを格納する変数
    int res = INF;

    // bitのvを除いたもの
    int prev_bit = bit & ~(1<<v);

    // vの手前のノードとしてuを全探索
    for(int u=0; u<N; u++){
        if(!(prev_bit & (1<<u))) continue;  // uがprev_bitになかったらだめ

        // 再帰的に探索
        // (三好)このようにトップダウンで再帰をかけていく。再帰途中ではこれまで訪れたことのない点だけを訪れることができるようになっている
        if(res > rec(prev_bit, u) + dist[u][v]){
            res = rec(prev_bit, u) + dist[u][v];
        }
    }

    return dp[bit][v] = res;    // メモしながらリターン
}

int main()
{
    int E; cin >> N >> E;
    rep(i,N){
        rep(j,N){
            dist[i][j] = INF;
        }
    }
    rep(i,E){
        int s, t, d; cin >> s >> t >> d;
        dist[s][t] = d;
    }

    // テーブルを全部-1にしておく（-1でなかったところは探索済み)
    for(int bit=0; bit<(1<<N); bit++) for(int v=0; v<N; v++) dp[bit][v] = -1;

    // 探索
    int res = INF;
    rep(v, N){
        if(res > rec((1<<N)-1, v)){
            res = rec((1<<N)-1, v);
        }
    }
    cout << res << endl;
}