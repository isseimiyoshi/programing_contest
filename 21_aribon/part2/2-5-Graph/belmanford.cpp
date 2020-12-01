#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 頂点fromから頂点toへのコストの辺
struct edge{int from, to, cost;};   // 構造体の末尾にはセミコロン（;）をつける

edge es[MAX_V]; // 辺

int d[MAX_V];   // 最短距離
int V, E;       // Vは頂点数、Eは辺数
const int INF = 1000000;

// s番目の頂点から各頂点への最短距離を求める
void shortest_path(int s){
    for(int i=0; i<V; i++) d[i] = INF;
    d[s] = 0;
    while(true){
        bool update = false;
        for(int i=0; i<E; i++){
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(!update) break;
    }
}

int main()
{
    
}