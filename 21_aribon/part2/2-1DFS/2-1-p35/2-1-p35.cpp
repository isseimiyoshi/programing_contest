#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int N;
int M;
int MAX_N = 100;
int MAX_M = 100;

vector<vector<char>> yards(MAX_N, vector<char> (MAX_M));

void dfs(int i, int j){
    yards[i][j] = '.';
    for(int k=-1; k<=1; k++){
        if(i == 0 && k == -1) continue;
        for(int l=-1; l<=1; l++){
            if(j == 0 && l == -1) continue;
            if(yards[i+k][j+l] == 'W') dfs(i+k, j+l);
            yards[i+k][j+l] = '.';
        }
    }
}

/*
入力

10
12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
*/


int main()
{
    // グローバル変数の入力値をスコープ外で配列の要素数に指定しているとセグフォが起こる
    cin >> N >> M;
    for(int i=0; i<N; i++){
        string yard_row;
        cin >> yard_row;
        for(int j=0; j<M; j++){
            char yard = yard_row[j];
            yards[i][j] = yard;
        }
    }
    // cout << yards.size() << " " << yards[0].size() << endl;
    int count = 0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(yards[i][j] == 'W'){
                dfs(i, j);
                count += 1;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}