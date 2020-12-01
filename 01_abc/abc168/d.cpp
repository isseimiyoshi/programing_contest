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

const int MAX_N = 100100;
const int WHITE = 0, GRAY = 1, BLACK = 2;
const int INF = 1000000000;

int n, color[MAX_N], d[MAX_N], p[MAX_N];
vector<int> M[MAX_N];

void init(){
    rep(i,MAX_N){
        color[i] = WHITE;
        d[i] = INF;
    }
}

void dijkstra(){
    d[0] = 0;
    color[0] = GRAY;
    int u, minv;
    while(true){
        rep(i,n){
            if(minv > d[i] && color[i] != BLACK){
                u = i;
                minv = d[i];
            }
        }
        if(minv == INF) break;
        color[u] = BLACK;
        for(int v: M[u]){
            if(color[v] != BLACK){
                if(d[v] > d[u] + 1){
                    d[v] = d[u] + 1;
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    int m; cin >> m;
    init();
    rep(_,m){
        int x,y; cin >> x >> y; x--; y--;
        M[x].push_back(y);
        M[y].push_back(x);
    }
    dijkstra();
    rep(i,n) cout << d[i] << endl;
}