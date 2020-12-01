#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Vは頂点の集合、Eは辺の集合
vector<int> G[MAX_V];

int main()
{
    int V, E;
    scanf("%d %d", &V, &E); // &変数：変数のアドレスを取得
    for(int i=0; i<E; i++){
        int s, t;
        scanf("%d %d", &s, &t);
        G[s].push_back[t];
        G[t].push_back[s];
    }

    return 0;
}