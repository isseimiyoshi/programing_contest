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

int main()
{
    int H, W; cin >> H >> W;
    bool obs[H][W]; // 1次元目：行数、縦　2次元目：列数、横
    rep(i,H){
        string Si; cin >> Si;
        rep(j,W){
            if(Si[j] == '#') obs[i][j] = true;
            else obs[i][j] = false;
        }
    }
    int L[H][W];
    int R[H][W];
    int U[H][W];
    int D[H][W];
    rep(i,H){
        for(int j=0; j<W; j++){
            if(obs[i][j]){
                L[i][j] = 0;
            }else{
                if(j == 0) L[i][j] = 1;
                else L[i][j] = L[i][j-1] + 1;
            }
        }
        for(int j=W-1; j>=0; j--){
            if(obs[i][j]){
                R[i][j] = 0;
            }else{
                if(j == W-1) R[i][j] = 1;
                else R[i][j] = R[i][j+1] + 1;
            }
        }
    }
    rep(j,W){
        for(int i=0; i<H; i++){
            if(obs[i][j]){
                U[i][j] = 0;
            }else{
                if(i == 0) U[i][j] = 1;
                else U[i][j] = U[i-1][j]+1;
            }
        }
        for(int i=H-1; i>=0; i--){
            if(obs[i][j]){
                D[i][j] = 0;
            }else{
                if(i == H-1) D[i][j] = 1;
                else D[i][j] = D[i+1][j]+1;
            }
        }
    }
    int max_l = 0;
    /*
    rep(i,H){
        rep(j,W){
            cout << L
        }
    }
    */
    rep(i,H){
        rep(j,W){
            int light = L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3;
            if(max_l < light) max_l = light;
        }
    }
    cout << max_l << endl;
}