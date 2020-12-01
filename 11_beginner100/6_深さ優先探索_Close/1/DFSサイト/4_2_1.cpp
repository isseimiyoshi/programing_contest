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

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
const int MAX_W = 10, MAX_H = 10;
const int WHITE = 0, BLACK = 1;

int M[MAX_H][MAX_W], color[MAX_H][MAX_W];

void init(){
    rep(i,MAX_H){
        rep(j,MAX_W){
            M[i][j] = 0;
            color[i][j] = WHITE;
        }
    }
}

void color_init(){
    rep(i,MAX_H){
        rep(j,MAX_W){
            color[i][j] = WHITE;
        }
    }
}

void dfs(int uh, int uw){
    color[uh][uw] = BLACK;
    rep(i,4){
        int vh, vw;
        vh = uh + dy[i]; vw = uw + dx[i];
        if(vh>=0 && vh<MAX_H && vw>=0 && vw<MAX_W && M[vh][vw] && color[vh][vw] == WHITE){
            dfs(vh, vw);
        }
    }
}

int main()
{
    init();
    rep(i,MAX_H){
        rep(j,MAX_W){
            char aij; cin >> aij;
            if(aij == 'o') M[i][j] = 1;
            else continue;
        }
    }
    /*
    rep(i,MAX_H){
        rep(j,MAX_W){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    */
    bool isComp = false;
    
    rep(i,MAX_H){
        rep(j,MAX_W){
            if(M[i][j] == 0){
                color_init();
                M[i][j] = 1;    // 陸地を1つ増やす
                // dfsして、すべて隣接しているか確認する
                dfs(i, j);
                bool isOK = true;
                rep(k,MAX_H){
                    rep(l,MAX_W){
                        if(M[k][l] && color[k][l] == WHITE){
                            isOK = false;
                            break;
                        }
                    }
                }
                if(isOK){
                    isComp = true;
                    break;
                }
                M[i][j] = 0;    // 増やした陸地を海に戻す
            }else{
                continue;
            }
        }
        if(isComp) break;
    }
    
    if(isComp) cout << "YES" << endl;
    else cout << "NO" << endl;
}