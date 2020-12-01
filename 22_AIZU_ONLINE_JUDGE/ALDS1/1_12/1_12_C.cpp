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

static const int MAX = 10000;
static const int INFTY = (1<<20);   // pow(10,19);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
vector<pair<int, int> > adj[MAX];   // 重み付き有向グラフの隣接リストを表現

void dijkstra(){
    priority_queue<pair<int, int> > PQ;
    int color[MAX], d[MAX];
    rep(i, n){
        d[i] = INFTY;
        color[i] = WHITE;
    }
    d[0] = 0; color[0] = GRAY;
    PQ.push(make_pair(0, 0));

    while(!PQ.empty()){
        pair<int, int> f = PQ.top(); PQ.pop();
        int u = f.second;

        color[u] = BLACK;

        // 最小値を取り出し、それが最短でなければ無視
        if(d[u] < f.first*(-1)) continue;

        rep(j,adj[u].size()){
            int v = adj[u][j].first;
            if(color[v] == BLACK) continue;
            if(d[v] > d[u] + adj[u][j].second){
                d[v] = d[u] + adj[u][j].second;
                // priority_queueは、デフォルトで大きい値を優先するため-1をかける
                PQ.push(make_pair(d[v]*(-1), v));
                color[v] = GRAY;
            }
        }
    }
    rep(i,n){
        cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
    }
}

int main()
{
    int k, u, v, c;
    cin >> n;
    rep(i,n){
        cin >> u >> k;
        rep(j,k){
            cin >> v >> c;
            adj[u].push_back(make_pair(v, c));
        }
    }

    dijkstra();

    return 0;
}