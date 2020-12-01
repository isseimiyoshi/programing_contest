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

const int MAX_W = 55, MAX_H = 55;
const int WHITE = 0, BLACK = 1;

int w, h;
bool c[MAX_W][MAX_H];
int color[MAX_W][MAX_H];

void init(){
    rep(i,MAX_H){
        rep(j,MAX_W) c[i][j] = false, color[i][j] = WHITE;
    }
}

void dfs(int si, int sj){
    color[si][sj] = BLACK;
    for(int i=si-1; i<=si+1; si++){
        for(int j=sj-1; j<=sj+1; sj++){
            if(i>=0 && i<h && j>=0 && j<w){
                if(color[i][j] == WHITE && c[i][j] == true) dfs(i,j);
            }
        }
    }
}

int dfs_init(){
    int n = 0;
    rep(i,h){
        rep(j,w){
            if(c[i][j] == true && color[i][j] == WHITE){
                dfs(i,j);
                n++;
            }
        }
    }
    return n;
}

int main()
{
    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0) break;
        init();
        rep(i,h){
            rep(j,w){
                int cij; cin >> cij;
                if(cij == 1) c[i][j] = true;
            }
        }
        int n = dfs_init();
        cout << n << endl;
    }   
}