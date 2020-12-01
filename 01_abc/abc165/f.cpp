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

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

int N; vector<int> A;
const int MAX_N = pow(10,6);
const int INF = pow(10,7);
const int WHITE = 0, GRAY = 1, BLACK = 2;

int color[MAX_N];
int M[MAX_N][MAX_N];
int d[MAX_N];
int p[MAX_N];


void dijkstra(int s){
    rep(i,N){
        color[i] = WHITE; d[i] = INF;
    }
    d[s] = 0;
    p[s] = -1;
    int u;
    while(true){
        int mincost = INF;
        rep(i,N){
            if(color[i] != BLACK && d[i] < mincost){
                mincost = d[i];
                u = i;
            }
        }
        if(mincost == INF) break;   // 
        color[u] = BLACK;
        rep(v,N){
            if(color[v] != BLACK && M[u][v]){
                if(d[u] + M[u][v] < d[v]){
                    d[v] = d[u] + M[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }

    // 出力(最長増加部分列を計算して出力する処理を実装する)
    rep(i,N){
        vector<int> B; B.push_back(A[i]);
        int pi = p[i];
        while(pi != -1){
            B.push_back(A[pi]);
            pi = p[pi];
        }
        B.push_back(A[s]);
        reverse(B.begin(), B.end());
        int lon_n = 0; int min_a = 0;
        rep(j,B.size()){
            cout << B[j] << " ";
        }cout << endl;
    }
}


int main()
{
    cin >> N;
    A = vector<int>(N);
    rep(i,N) cin >> A[i];
    rep(i,N)rep(j,N) M[i][j] = INF;
    rep(_,N-1){
        int u, v; cin >> u >> v;
        M[u-1][v-1] = M[v-1][u-1] = 1;
    }
    dijkstra(0);
}