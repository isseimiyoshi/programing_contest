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

const int MAX_N = 105;
const int INF = 1000;

vector<int> to[MAX_N];
int d[MAX_N], f[MAX_N]; // d：発見時刻、f：完了時刻
int t = 0; int n; 

void init(){
    rep(i,MAX_N){
        d[i] = INF, f[i] = INF; // 各頂点番号の色（Color）を設定しているのと同義
    }
}

void dfs(int u){
    if(d[u] == INF) d[u] = ++t;
    for(auto v: to[u]){
        if(d[v] == INF) dfs(v); // *もう訪問が完了している頂点には不要に寄らない
    }
    if(f[u] == INF) f[u] = ++t;
}

void dfs_init(){
    rep(i,n){
        if(d[i] == INF) dfs(i);
    }
}

int main()
{
    cin >> n;
    init();
    rep(i,n){
        int u, k; cin >> u >> k; --u;
        rep(_,k){
            int v; cin >> v; --v;
            to[u].push_back(v);
        }
    }
    dfs_init();
    rep(i,n){
        printf("%d %d %d\n", i+1, d[i], f[i]);
    }
}