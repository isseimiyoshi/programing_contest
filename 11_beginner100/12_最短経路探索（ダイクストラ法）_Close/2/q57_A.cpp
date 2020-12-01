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
const int MAX_N = 105;
const int WHITE = 0, GRAY = 1, BLACK = 2;

int n;
vector<P> to[MAX_N];
ll dis[MAX_N], color[MAX_N];

void dijkstra(int s){
    fill(dis, dis+MAX_N, INF);
    fill(color, color+MAX_N, WHITE);

    dis[s] = 0;
    color[s] = BLACK;

    priority_queue<P> pq;
    pq.push(make_pair(-dis[s], s));
    while(!pq.empty()){
        P pair_u = pq.top(); pq.pop();
        int u = pair_u.second, ud = -pair_u.first;

        color[u] = BLACK;

        for(P pair_v: to[u]){
            int v = pair_v.first, vcost = pair_v.second;
            if(color[v] != BLACK && dis[v] > ud + vcost){
                dis[v] = ud + vcost;
                pq.push(make_pair(-dis[v], v));
            }
        }
    }
}

int main()
{
    cin >> n;
    int k; cin >> k;
    rep(_,k){
        int com; cin >> com;
        if(com == 0){
            int a, b; cin >> a >> b; --a, --b;
            dijkstra(a);

            if(dis[b] == INF) cout << -1 << endl;
            else cout << dis[b] << endl;
        }else{
            int c, d, e; cin >> c >> d >> e;
            --c, --d;
            to[c].push_back(make_pair(d, e));
            to[d].push_back(make_pair(c, e));
        }
    }
}