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

const int MAX_H = 55, MAX_W = 55;
const int INF = 1000100100;

int color[MAX_H][MAX_W], c[MAX_H][MAX_W];
int w, h;


void init(){
    rep(i,MAX_H){
        rep(j,MAX_W){
            color[i][j] = INF;
            c[i][j] = 0;
        }
    }
}

void dfs(int hi, int wi, int col){
    if(color[hi][wi] == INF) color[hi][wi] = col;

    for(int i=-1; i<=1; i++){   // 高さ
        for(int j=-1; j<=1; j++){   // 幅
            int nh = hi+i, nw = wi+j;
            if(nh<0 || nw<0 || nh>=h || nw>=w) continue;
            if(c[nh][nw] == 1 && color[nh][nw] == INF) dfs(nh, nw, col);
        }
    }
}

int main()
{
    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        init();

        rep(i,h){
            rep(j,w){
                cin >> c[i][j];
            }
        }

        int col = 0;
        rep(i,h){
            rep(j,w){
                if(color[i][j] == INF && c[i][j] == 1){
                    dfs(i, j, col);
                    ++col;
                }
            }
        }
        set<int> s;
        rep(i,h){
            rep(j,w){
                if(color[i][j] != INF) s.insert(color[i][j]);
            }
        }
        cout << s.size() << endl;
    }
}