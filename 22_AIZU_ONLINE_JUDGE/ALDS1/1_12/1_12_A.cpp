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

const int WHITE=0, GRAY=1, BLACK=1;
const int INF = pow(10,8);

int main()
{
    int N; cin >> N;
    int M[N][N];
    rep(i,N){
        rep(j, N){
            int Mij; cin >> Mij;
            M[i][j] = Mij;
        }
    }
    // primのアルゴリズム
    int color[N], d[N], p[N];
    rep(i,N){
        color[i]=WHITE; d[i]=INF;
    }
    d[0]=0; p[0]=-1;
    int u;
    while(true){
        int mincost = INF;
        rep(i,N){
            if(color[i]!=BLACK && d[i]<mincost){
                mincost=d[i];
                u=i;
            }
        }

        if(mincost == INF) break;

        color[u] = BLACK;

        rep(v, N){
            if(color[v]!=BLACK && M[u][v] != -1){
                if(M[u][v] < d[v]){
                    d[v]=M[u][v];
                    p[v]=u;
                    color[v]=GRAY;
                }
            }
        }
    }
    // 出力
    int sum = 0;
    rep(i,N){
        if(p[i] != -1) sum += M[i][p[i]];
    }
    cout << sum << endl;
}