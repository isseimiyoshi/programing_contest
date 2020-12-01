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

int n;
int dist[21][21];

// メモ再帰
int dp[(1<<20)+1][21];  // DPテーブルは余裕を持ったサイズにする

int rec(int bit, int v){
    // すでに探索済みであればリターン
    if(dp[bit][v] != -1) return dp[bit][v];

    // 初期値
    // この初期値処理によって、スタート地点のノードは探索済みにされる
    
    if(bit == (1<<v)){
        return dp[bit][v] = 0;
    }
    

    // 答えを格納する変数
    int res = INF;

    // bitのｖを取り除いたもの
    int prev_bit = bit & ~(1<<v);

    // vの手前のノードとして、uを全探索
    rep(u,n){
        if(!(prev_bit & (1<<u))) continue;  // u が prev_bit になければだめ 

        //　再帰的に探索
        res = min(res, rec(prev_bit,u)+dist[u][v]);
    }
    return dp[bit][v] = res;    // メモしながらリターン
}

int main()
{
    cin >> n;
    int e; cin >> e;

    rep(i,n) rep(j,n) dist[i][j] = INF;

    rep(_,e){
        int si, ti, di; cin >> si >> ti >> di;
        dist[si][ti] = di;
    }

    // テーブルを全部-1にしておく（-1でなかったところは探索済み）
    for(int bit=0; bit<(1<<n); ++bit) for(int v=0; v<n; ++v){
        dp[bit][v] = -1;
    }

    // 探索
    int res = INF;
    rep(v,n){
        res = min(res, rec((1<<n)-1, v));
    }
    cout << res << endl;
}