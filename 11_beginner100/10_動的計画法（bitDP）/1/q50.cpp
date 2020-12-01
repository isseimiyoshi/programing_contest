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

const int MAX_N = 17;
const int INF = 1000100100;

int n;
int d[MAX_N][MAX_N];
int ti[MAX_N][MAX_N];

int cnt;

int dp[(1<<MAX_N)][MAX_N];  // メモ化テーブル

// すでに訪れた頂点集合がS、現在位置がv
int rec(int S, int v){
    if(dp[S][v] >= 0) return dp[S][v];  // すでに探索済み

    if(S == (1 << n)-1 && v == 0) return dp[S][v] = 0;  // すべての頂点を訪れて戻ってきた

    int res = INF;

    rep(u,n){
        if(!(S >> u & 1)){
            int ori_res = rec(S | 1 << u, u) + d[v][u];
            if(ti[v][u] < ori_res){
                continue;
            }
            if(res > ori_res){
                res = ori_res;
                if(S == 0 && v == 0) cnt = 1;
            }else{
                if(S == 0 && v == 0) cnt++;
            }
            
        }
    }

    return dp[S][v] = res;
}

int main()
{
    int E; cin >> n >> E;

    // 隣接行列を大きな値で初期化
    rep(i,n) rep(j,n) d[i][j] = ti[i][j] = INF;

    // 各頂点間の情報を読み取る
    rep(i,E){
        int s, t, dis, time; cin >> s >> t >> dis >> time;
        s--; t--;
        d[s][t] = dis;
        ti[s][t] = time;
    }
    memset(dp, -1, sizeof(dp));

    cout << rec(0,0) << endl;
    cout << cnt << endl;

}