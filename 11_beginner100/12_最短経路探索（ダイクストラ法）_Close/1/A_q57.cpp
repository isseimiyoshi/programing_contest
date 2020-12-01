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

const int MAX_N = 105;
const int WHITE = 0, GRAY = 1, BLACK = 2;
const int INF = 1000100100;

vector<P> to[MAX_N];
int color[MAX_N], dis[MAX_N];

void init(){
    rep(i,MAX_N){
        color[i] = WHITE;
        dis[i] = INF;
    }
}

void dijkstra(int s){
    init();
    dis[s] = 0;
    priority_queue<P> pq;
    pq.push(make_pair((-1)*dis[s], s));
    while(!pq.empty()){
        P pair_u = pq.top(); pq.pop();
        int u = pair_u.second; int uh = (-1)*pair_u.first;
        color[u] = BLACK;
        if(uh > dis[u]) continue;
        for(auto pair_v: to[u]){
            int v = pair_v.first; int vh = pair_v.second;
            if(dis[v] > dis[u] + vh && color[v] != BLACK){
                dis[v] = dis[u] + vh;
                color[v] = GRAY;
                pq.push(make_pair((-1)*dis[v], v));
            }
        }
    }
}

int main()
{
    int n, k; cin >> n >> k;
    rep(_,k){
        int z; cin >> z;
        if(z == 0){
            int a, b; cin >> a >> b; --a, --b;
            dijkstra(a);
            if(dis[b] == INF) cout << -1 << endl;
            else cout << dis[b] << endl;
        }else if(z == 1){
            int c, d, e; cin >> c >> d >> e;
            --c; --d;
            bool isAl = false;
            rep(i, to[c].size()){
                P v = to[c][i];
                if(v.first == d && v.second > e) to[c][i].second = e, isAl = true;
            }
            rep(i, to[d].size()){
                P v = to[d][i];
                if(v.first == c && v.second > e) to[d][i].second = e, isAl = true;
            }
            if(!isAl){
                to[c].push_back(make_pair(d, e));
                to[d].push_back(make_pair(c, e));
            }
        }
    }
}