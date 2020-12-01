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

const int MAX = 100100;

vector<int> G[MAX];
int N;
bool visited[MAX];
int prenum[MAX], parent[MAX], lowest[MAX], timer;

void dfs(int current, int prev){
    // ノードcurrentを訪問した直後の処理
    prenum[current] = lowest[current] = timer;
    timer++;

    visited[current] = true;
    int next;
    for(auto next: G[current]){
        if(!visited[next]){
            // ノードcurrentからノードnextへ訪問する直前の処理
            parent[next] = current;
            dfs(next, current);
            // ノードnextの探索が終了した直後の処理
            lowest[current] = min(lowest[current], lowest[next]);   // 条件3
        }else if(next != prev){
            // エッジ current --> next がBack-edgeの場合の処理
            lowest[current] = min(lowest[current], prenum[next]);
        }
    }
}

void art_points(){
    rep(i,N) visited[i] = false;
    timer = 1;
    // lowestの計算
    dfs(0,-1);  // 0 == root

    set<int> ap;
    int np = 0;
    for(int i=1; i<N; i++){
        int p = parent[i];
        if(p == 0) np++;
        else if(prenum[p] <= lowest[i]) ap.insert(p);
    }
    if(np > 1) ap.insert(0);
    for(auto itr = ap.begin(); itr!=ap.end(); itr++){
        cout << *itr << endl;
    }
}

int main()
{
    int m;
    cin >> N >> m;
    rep(_,m){
        int s, t; cin >> s >> t;
        G[s].push_back(t);
        G[t].push_back(s);  // Gは隣接リスト
    }
    art_points();

    return 0;
}