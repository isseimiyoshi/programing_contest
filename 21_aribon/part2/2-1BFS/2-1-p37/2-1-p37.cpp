#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int N, M;
int MAX_N=100; int MAX_M=100;
vector<vector<char>> meiro(MAX_N, vector<char>(MAX_M));
vector<vector<int>> shortest_path(MAX_N, vector<int>(MAX_M, 100000));
vector<pair<int,int>> roop(4);


/*
input

10
10

#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#
*/

// deepの初期値はゼロ
void shortest(int i, int j, int deep){
    shortest_path[i][j] = deep;
    for(int k=0; k<4; k++){
        int l = roop[k].first;
        int m = roop[k].second;
        if((i == 0 && l == -1) || (j == 0 && m == -1)) continue;
        if((meiro[i+l][j+m] == '.') || (meiro[i+l][j+m] == 'G')){
            if(shortest_path[i+l][j+m] <= deep){
                continue;
            }else{
                shortest_path[i+l][j+m] = deep+1;
                shortest(i+l, j+m, deep+1);
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    int start_i;
    int start_j;
    int goal_i;
    int goal_j;
    roop[0] = make_pair(-1, 0);
    roop[1] = make_pair(0, -1);
    roop[2] = make_pair(0, 1);
    roop[3] = make_pair(1, 0);
    for(int i=0; i<N; i++){
        string meiro_row;
        cin >> meiro_row;
        for(int j=0; j<M; j++){
            char mas = meiro_row[j];
            if(mas == 'S'){
                start_i = i;
                start_j = j;
            }else if(mas == 'G'){
                goal_i = i;
                goal_j = j;
            }
            meiro[i][j] = mas;
        }
    }
    shortest(start_i, start_j, 0);
    cout << shortest_path[start_i][start_j] << endl;
    cout << shortest_path[goal_i][goal_j] << endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << shortest_path[i][j] << " ";
        }
        cout << endl;
    }
}