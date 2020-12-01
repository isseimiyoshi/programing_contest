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

const int WHITE = 0, GRAY = 1, BLACK = 2;
const int MAX_N = 105, INF = pow(10,9);
int M[MAX_N][MAX_N]; int color[MAX_N];
int d[MAX_N], f[MAX_N];
int t = 0; int n; 

void init(){
    rep(i,MAX_N){
        rep(j,MAX_N) M[i][j] = 0;
        color[i] = WHITE;
        d[i] = INF;
    }
}

void dfs(int u){
    color[u] = GRAY;
    d[u] = ++t;
    rep(v,n){
        if(M[u][v] == 1 && color[v] == WHITE){
            dfs(v);
        }
    }
    color[u] = BLACK;
    f[u] = ++t;
}

void dfs_visit(){
    rep(i,n){
        if(d[i] == INF) dfs(i);
    }
}

int main()
{
    cin >> n;
    init();
    // 隣接リストの読み込み
    rep(i,n){
        int u; cin >> u; u--;
        int k; cin >> k;
        rep(_,k){
            int vi; cin >> vi; vi--;
            M[u][vi] = 1;    // 無向グラフと仮定する
        }
    }
    dfs_visit();
    rep(i,n){
        printf("%d %d %d\n", i+1, d[i], f[i]);
    }
}