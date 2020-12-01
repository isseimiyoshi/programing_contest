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

const int INF = pow(10, 4);

int main()
{
    int N, X, Y; cin >> N >> X >> Y;
    int d[N][N];
    int dis[N];
    // 初期化
    rep(i,N){
        rep(j,N){
            d[i][j] = INF;
        }
    }
    rep(i, N) dis[i] = 0;
    rep(i, N){
        // cout << i << endl;
        if(i != N-1){
            d[i][i+1] = 1;
            d[i+1][i] = 1;
        }
    }
    d[X-1][Y-1] = 1; d[Y-1][X-1] = 1;
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            // if(d[i][j] == 5) cout << i << "," << j << endl;
            dis[d[i][j]]++;
        }
    }
    rep(i, N){
        if(i != 0) printf("%d\n", dis[i]);
    }
}