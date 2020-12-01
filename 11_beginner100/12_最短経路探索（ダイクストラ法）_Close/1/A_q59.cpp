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

const int MAX_N = 5050;
const int INF = 1000100100;
const int WHITE = 0, GRAY = 1, BLACK = 2;

// 道路網を表す隣接リスト
vector<int> to[MAX_N];
int dis1[MAX_N];

// 重み付きの有向グラフを作成するための変数
vector<pair<ll,ll>> to2[MAX_N];
ll d[MAX_N], color[MAX_N];


void init(){
    rep(i,MAX_N) dis1[i] = INF;
}

// 各頂点ごとにBFSを行うための変数
void bfs(int s){
    init();
    dis1[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v: to[u]){
            if(dis1[v] == INF){
                dis1[v] = dis1[u] + 1;
                q.push(v);
            }
        }
    }
}

void dijkstra(int s){
    rep(i,MAX_N){
        d[i] = INF;
        color[i] = WHITE;
    }
    d[s] = 0;
    priority_queue<pair<ll, ll>>  pq;
    pq.push(make_pair((-1)*d[s], s));
    while(!pq.empty()){
        pair<ll, ll> p_u = pq.top(); pq.pop();
        ll u = p_u.second; ll uh = (-1)*p_u.first;
        color[u] = BLACK;
        if(d[u] < uh) continue;
        for(auto p_v: to2[u]){
            ll v = p_v.first; ll vh = p_v.second;
            if(d[v] > d[u] + vh && color[v] != BLACK){
                d[v] = d[u] + vh;
                color[v] = GRAY;
                pq.push(make_pair((-1)*d[v], v));
            }
        }
    }
}

int main()
{
    int N, K; cin >> N >> K;
    int C[N], R[N];
    rep(i,N) cin >> C[i] >> R[i];
    rep(_,K){
        int Ai, Bi; cin >> Ai >> Bi; --Ai; --Bi;
        to[Ai].push_back(Bi);
        to[Bi].push_back(Ai);
    }
    rep(i,N){
        bfs(i);
        rep(j,N){
            if(j == i) continue;
            if(dis1[j] <= R[i]){
                to2[i].push_back(make_pair(j,C[i]));
            }
        }
    }
    dijkstra(0);
    cout << d[N-1] << endl;
}