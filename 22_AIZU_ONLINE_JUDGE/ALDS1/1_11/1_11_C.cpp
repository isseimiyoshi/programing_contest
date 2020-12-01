#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

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
*/

const int WHITE=0, GRAY=1, BLACK=2;
const int INF = 10000;
/*
void bfs(int u, int d[], int color[], int N, int M[][]){
    d[u] = 0;
    color[u] = GRAY;
    queue<int> Q;
    Q.push(u);
    while(!Q.empty()){
        int current_u = Q.front(); Q.pop();
        rep(i,N){
            if(M[current_u][i] && color[i] == WHITE){
                Q.push(i); d[i] = d[u]+1;
            }
        }
    }
    rep(i,N){
        printf("%d %d\n", i+1, d[i]);
    }
}
*/

int main()
{
    int N; cin >> N;
    int d[N], M[N][N], color[N];
    // 初期化
    rep(i, N){
        d[i] = INF;
        color[i] = WHITE;
        rep(j,N) M[i][j] = false;
    }
    // 辺の情報を読み込む
    rep(i,N){
        int id; cin >> id;
        int k; cin >> k;
        rep(j,k){
            int vj; cin >> vj;
            M[i][vj-1] = true;
        }
    }
    d[0] = 0;
    color[0] = GRAY;
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int current_u = Q.front(); Q.pop();
        // cout << current_u << endl;
        rep(i,N){
            if(M[current_u][i] && color[i] == WHITE){
                Q.push(i); d[i] = d[current_u]+1;
                color[i] = GRAY;
            }
        }
        color[current_u] = BLACK;
    }
    rep(i,N){
        if(d[i] == INF) printf("%d %d\n", i+1, -1);
        else printf("%d %d\n", i+1, d[i]);
    }
}