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

const int INF = 1000100100;
const int MAX_V = 10100;
const int WHITE = 0, GRAY = 1, BLACK = 2;

vector<P> to[MAX_V];
int color[MAX_V], d[MAX_V], p[MAX_V];

int V, E;

void prim(){
    rep(i,MAX_V){
        color[i] = WHITE;
        d[i] = INF;
    }
    d[0] = 0;
    p[0] = -1;
    while(true){
        int mincost = INF;
        int u;
        rep(i,V){
            if(color[i] != BLACK && d[i] < mincost){
                mincost = d[i];
                u = i;
            }
        }
        // もし最小コストが更新されていなければ、最小全域木が完成しているので抜ける
        if(mincost == INF) break;
        color[u] = BLACK;
        for(auto p_v: to[u]){
            int v = p_v.first; int w = p_v.second;
            if(color[v] != BLACK && d[v] > w){
                d[v] = w;
                p[v] = u;
                color[v] = GRAY;
            }
        }
    }
}

int main()
{
    cin >> V >> E; 
    rep(_, E){
        int s, t, w; cin >> s >> t >> w;
        to[s].push_back(make_pair(t, w));
        to[t].push_back(make_pair(s, w));
    } 
    prim();
    int sum = 0;
    rep(i,V){
        sum += d[i];
    }
    cout << sum << endl;
}