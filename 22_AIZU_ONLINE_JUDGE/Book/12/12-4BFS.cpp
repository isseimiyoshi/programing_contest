#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

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

const int WHITE = 0, GRAY = 1, BLACK = 2;
const int MAX_N = 105, INF = pow(10,9);
int M[MAX_N][MAX_N]; int color[MAX_N];
int d[MAX_N]; int n;
queue<int> Q;

void init(){
    rep(i,MAX_N){
        rep(j,MAX_N) M[i][j] = 0;
        color[i] = WHITE;
        d[i] = INF;
    }
}

void bfs(int u){
    color[u] = GRAY;
    d[u] = 0;
    Q.push(u);

    while(!Q.empty()){
        u = Q.front(); Q.pop();
        rep(i,n){
            if(M[u][i] == 1 && color[i] == WHITE){
                d[i] = d[u]+1;
                color[i] = GRAY;
                Q.push(i);
            }
        }
        color[u] = BLACK;
    }
}

int main()
{
    cin >> n;
    init(); // 初期化
    rep(i,n){
        int u; cin >> u; u--;
        int k; cin >> k;
        rep(_,k){
            int vi; cin >> vi; vi--;
            M[u][vi] = 1;
        }
    }
    bfs(0);
    rep(i,n){
        if(d[i] == INF) printf("%d %d\n", i+1, -1);
        else printf("%d %d\n", i+1, d[i]);
    }
}