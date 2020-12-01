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
int t, N;
const int MAX_N = 110;
int M[MAX_N][MAX_N], color[MAX_N], d[MAX_N], f[MAX_N];


void dfs(int u){
    color[u] = GRAY;
    t++;
    d[u] = t;
    rep(v,N){
        if(M[u][v] && color[v] == WHITE){
            dfs(v);
        }
    }
    color[u] = BLACK;
    t++;
    f[u] = t;
}

void dfs_init(){
    rep(i,N){
        color[i] = WHITE;
        d[i] = 0; f[i] = 0;
    }
    dfs(0);
}

int main()
{
    cin >> N;
    // 初期化
    t = 0;
    rep(i, N){
        rep(j, N) M[i][j] = false;
    }
    rep(i, N){
        int id; cin >> id;
        int k; cin >> k;
        rep(j, k){
            int Mj; cin >> Mj;
            M[i][Mj-1] = true;
        }
    }
    dfs_init();
    rep(i, N){
        printf("%d %d %d\n", i+1, d[i], f[i]);
    }
}