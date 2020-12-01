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

const int MAX_N = 10100;
const int WHITE = 0, GRAY = 1;

int indeg[MAX_N], color[MAX_N];
vector<int> adl[MAX_N], out;
int n;

void init(){
    rep(i,MAX_N){
        color[i] = WHITE;
        indeg[i] = 0;
    }
}

void bfs(int u){
    queue<int> Q;
    Q.push(u);
    color[u] = GRAY;

    while(!Q.empty()){
        u = Q.front(); Q.pop();
        out.push_back(u);
        for(auto v: adl[u]){
            indeg[v]--;
            if(indeg[v] == 0 && color[v] == WHITE){
                Q.push(v);
                color[v] = GRAY;
            }
        }
    }
}

void topologicalSort(){
    rep(u,n){
        if(indeg[u] == 0 && color[u] == WHITE){
            bfs(u);
        }
    }
}

int main()
{
    cin >> n;
    int e; cin >> e;
    init(); // 初期化
    rep(_,e){
        int u, v; cin >> u >> v;
        adl[u].push_back(v);
        indeg[v]++;
    }
    topologicalSort();
    rep(i,n) cout << out[i] << endl;
}