#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int H, W;
    cin >> H >> W;
    // 各々の頂点からの最短経路を計算することができる
    int dist[10][10];
    // 経路距離の初期値を無限大に近い値に設定する
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            dist[i][j] = 999999;        
        }
    }
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin >> dist[i][j];
        }
    }
    vector <vector<int>> walls(H, vector<int>(W));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> walls[i][j];
        }
    }
    // 最短経路計算
    for(int k=0; k<10; k++){
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    // 必要となる合計コストを格納する変数
    int sum_cost = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            // cout << walls[i][j] << endl;
            if((walls[i][j] == -1) || (walls[i][j] == 1)){
                continue;
            }else{
                sum_cost += dist[walls[i][j]][1];
            }
        }
    }
    cout << sum_cost << endl;
}