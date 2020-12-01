#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_V = 1000;

int cost[MAX_V][MAX_V]; // cost[u][v]は辺e=(u,v)のコスト（存在しない場合はINF）
int d[MAX_V];           // 頂点sからの最短距離
bool used[MAX_V];       // すでに使われたかのフラグ
int prev_v[MAX_V];        // 最短経路を辿るための配列
int V;                  // 頂点数

const int INF = 1000000;

// 始点sから各頂点への最短距離を求める
void dijkstra(int s){
    fill(d, d+V, INF);  // fill(配列の先頭アドレス, 配列の先頭アドレス＋要素数, 埋め込む値)
    fill(used, used+V, false);
    fill(prev_v, prev_v+V, -1);     // 直前の頂点が確定しないものは-1とする
    d[s] = 0;
    prev_v[s] = s;

    while(true){
        int v = -1;
        // まだ使われていない頂点のうち距離が最小のものを探す
        for(int u=0; u<V; u++){
            if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }
        if(v == -1) break;
        used[v] = true;

        for(int u=0; u<V; u++){
            int prev_u = d[u];
            d[u] = min(d[u], d[v]+cost[v][u]);
            if(prev_u > d[u]) prev_v[u] = v;
        }
    }
}


/*

7 10
0 2 5
0 1 2
1 2 4
1 3 6
2 3 2
1 4 10
3 5 1
4 5 3
4 6 5
5 6 9

*/

int main()
{
    int E;
    cin >> V >> E;
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            cost[i][j] = INF;
        }
    }
    for(int i=0; i<E; i++){
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        cost[s][t] = c;
        cost[t][s] = c;
    }
    cout << endl;
    dijkstra(0);
    cout << d[3] << endl;   // 7
    int prev_n = prev_v[3];
    while(true){
        cout << prev_n << " ";
        if(prev_n == 0){
            break;
        }else{
            prev_n = prev_v[prev_n];
        }
    }
    cout << endl << endl;
    cout << d[6] << endl;
    prev_n = prev_v[6];
    while(true){
        cout << prev_n << " ";
        if(prev_n == 0){
            break;
        }else{
            prev_n = prev_v[prev_n];
        }
    }
    cout << endl;
}