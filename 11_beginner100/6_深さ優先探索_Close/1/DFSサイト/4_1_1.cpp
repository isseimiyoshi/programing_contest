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

const int MAX_H = 510, MAX_W = 510;
const int WHITE = 0, BLACK = 1;

int M[MAX_H][MAX_W], color[MAX_H][MAX_W];
int H, W;

void init(){
    rep(i,MAX_H){
        rep(j,MAX_W){
            M[i][j] = 0;
            color[i][j] = WHITE;
        }
    }
}

void dfs(P u){
    color[u.first][u.second] = BLACK;
    for(int hi=u.first-1; hi<=u.first+1; hi++){
        for(int wi=u.second-1; wi<=u.second+1; wi++){
            if((hi==u.first-1&&wi==u.second-1) || (hi==u.first-1&&wi==u.second+1) || (hi==u.first+1&&wi==u.second-1) || (hi==u.first+1&&wi==u.second+1)) continue;
            if(hi>=0 && hi<H && wi>=0 && wi<W && color[hi][wi] == WHITE && M[hi][wi]){
                P v; v.first = hi; v.second = wi;
                dfs(v);
            }
        }
    }
}

int main()
{
    cin >> H >> W;
    P s, g;
    init(); // 初期化
    rep(i,H){
        rep(j,W){
            char cij; cin >> cij;
            if(cij == 's'){
                s.first = i; s.second = j;
                M[i][j] = 1;
            }else if(cij == 'g'){
                g.first = i; g.second = j;
                M[i][j] = 1;
            }else if(cij == '.'){
                M[i][j] = 1;
            }else{
                continue;
            }
        }
    }
    dfs(s);
    if(color[g.first][g.second] == BLACK) cout << "Yes" << endl;
    else cout << "No" << endl;
}