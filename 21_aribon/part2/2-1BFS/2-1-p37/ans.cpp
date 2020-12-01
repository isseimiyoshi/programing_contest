#include<iostream>
#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;
const int MAX_N = 100, MAX_M = 100;

// 状態を表すクラスpairの場合、typedefしておくと便利
typedef pair<int, int> P;

// 入力
char maze[MAX_N][MAX_M + 1];
int N, M;
int sx, sy;     // スタートの座標
int gx, gy;     // ゴールの座標

int d[MAX_N][MAX_M];    // 各点までの最短距離の配列

// 移動４方向のベクトル
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs(){
    queue<P> que;
    // 全ての点をINFで初期化
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            d[i][j] = INF;
        }
    }
    // スタート地点をキューに入れて、その点の距離を0にする
    que.push(P(sx, sy));
    d[sx][sy] = 0;
    // キューが空になるまでループ
    /*
    ・最短経路が確定した座標ペアをキューから取り出す
    ・最短経路がまだ確定していない座標ペアをキューに入れる
    この操作をキューの個数に従って繰り返すことによって、一回の関数呼び出しで再起なしで最短経路を求めることができる
    →BFSがキューと相性が良いと呼ばれる由縁
    */
    while(que.size()){
        // キューの先頭を取り出す
        P p = que.front(); que.pop();
        // 取り出してきた状態がゴールなら止める
        if(p.first == gx && p.second == gy) break;

        // 4方向の移動をループ
        for(int i=0; i<4; i++){
            // 移動した後の点を(nx, ny)とする
            int nx = p.first + dx[i], ny = p.second + dy[i];

            // 移動が可能かの判定とすでに訪れたことがあるかの判定(d[nx][ny] != INFならすでに訪れたことがある)
            if(0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF){
                // 移動できるならキューに入れ、その点の距離をpからの距離+1で確定する
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

void solve(){
    int res = bfs();
    printf("%d\n", res);
}

int main()
{
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string maze_row;
        cin >> maze_row;
        for(int j=0; j<M; j++){
            char moji = maze_row[j];
            if(moji == 'S') sx=i, sy=j;
            if(moji == 'G') gx=i, gy=j;
            maze[i][j] = moji;
        }
    }
    // printf("%d %d\n", sx, sy);
    // printf("%d %d\n", gx, gy);
    solve();
}