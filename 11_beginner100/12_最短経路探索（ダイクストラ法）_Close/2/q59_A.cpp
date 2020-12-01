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
const int MAX_N = 5050;
const int WHITE = 0, GRAY = 1, BLACK = 2;

int n, k;
vector<P> to[MAX_N];
ll d[MAX_N], color[MAX_N];

void dijkstra(int s){
    fill(d, d+MAX_N, INF);
    fill(color, color+MAX_N, WHITE);
    d[s] = 0;
    color[s] = BLACK;

    priority_queue<pair<ll,ll> > pq;
    pq.push(make_pair(-d[s], s));
    while(!pq.empty()){
        pair<ll, ll> pair_u = pq.top(); pq.pop();
        ll u  = pair_u.second; ll ucost = -pair_u.first;
        color[u] = BLACK;
        for(P pair_v: to[u]){
            ll v = pair_v.first; ll vcost = pair_v.second;
            if(color[v] != BLACK && d[v] > ucost + vcost){
                d[v] = ucost + vcost;
                pq.push(make_pair(-d[v], v));
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    int c[n], r[n];
    rep(i,n) cin >> c[i] >> r[i];
    int a[k], b[k];
    vector<int> bfs_to[n];
    rep(i,k){
        int ai, bi; cin >> ai >> bi;--ai, --bi;
        bfs_to[ai].push_back(bi);
        bfs_to[bi].push_back(ai);
    }
    int dis[n];

    rep(i,n){
        fill(dis, dis+n, INF);
        dis[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v: bfs_to[u]){
                if(dis[v] == INF){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        rep(j,n){
            if(i == j) continue;
            if(dis[j] <= r[i]){
                to[i].push_back(make_pair(j, c[i]));
            }
        }
    }

    dijkstra(0);

    cout << d[n-1] << endl;

}