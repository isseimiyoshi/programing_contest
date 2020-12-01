#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_V = 1000;
vector<int> G[MAX_V];   // グラフ
int V, E;                  // 頂点数

int color[MAX_V];       // 頂点iの色

// dfs 深さ優先探索
// 隣接リストを用いて、一つの頂点が隣接している頂点から順々に遡り交互に異なる色を塗っていく
bool dfs(int v, int c){
    color[v] = c;   // 頂点vをcで塗る
    for(int i=0; i<G[v].size(); i++){
        // 隣接している頂点が同じ色ならfalse
        if(color[G[v][i]] == c) return false;
        // 隣接している頂点がまだ塗られていないのなら-cで塗る
        if(color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
    }
    return true;    // すべての頂点を塗れたらtrue
}

void solve(){
    for(int i=0; i<V; i++){
        if(color[i] == 0){
            if(!dfs(i, 1)){
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");
}

/*

3 3
0 1
1 2
2 0

4 4
0 1
1 2
2 3
3 0


*/

int main()
{
    //cin >> V >> E;
    scanf("%d %d", &V, &E); // &変数：変数のアドレスを取得
    // cout << V << E << endl;
    for(int i=0; i<E; i++){
        int s, t;
        scanf("%d %d", &s, &t);
        // cout << s << t << endl;
        G[s].push_back(t);
        G[t].push_back(s);
    }
    solve();   
}