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

const int MAX_N = 100100, MAX_M = 200200, MAX_K = 100100, MAX_S = 100100;
const int INF = 1000100100;
const int WHITE = 0, GRAY  = 1, BLACK = 2;

int n, m, k, s; 
int p, q; 
int c[MAX_K];

ll dis[MAX_N], dis2[MAX_N];
int color[MAX_N];

vector<P> to[MAX_N];
vector<int> to2[MAX_N];

void dijkstra(int s){
    fill(dis, dis+MAX_N, INF);
    fill(color, color+MAX_N, WHITE);

    dis[s] = 0;
    color[s] = BLACK;

    priority_queue<pair<ll, ll> > pq;
    pq.push(make_pair(-dis[s], s));
    while(!pq.empty()){
        pair<ll, ll> pair_u = pq.top(); pq.pop();
        ll u = pair_u.second; ll ucost = -pair_u.first;
        color[u] = BLACK;
        for(auto pair_v: to[u]){
            ll v = pair_v.first, vcost = pair_v.second;
            if(color[v] != BLACK && dis[v] > ucost + vcost){
                dis[v] = ucost + vcost;
                pq.push(make_pair(-dis[v], v));
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k >> s;
    cin >> p >> q;
    rep(i,k) cin >> c[i], --c[i];
    int a[m], b[m];
    rep(i,m){
        int ai, bi; cin >> ai >> bi;
        --ai, --bi;
        a[i] = ai, b[i] = bi;
        to2[ai].push_back(bi);
        to2[bi].push_back(ai);
    }

    rep(i,k){
        to2[n].push_back(c[i]);
        to2[c[i]].push_back(n);
    }
    fill(dis2, dis2+MAX_N, INF);
    dis2[n] = 0;
    queue<int> q2;
    q2.push(n);
    while(!q2.empty()){
        int u = q2.front(); q2.pop();
        for(int v: to2[u]){
            if(dis2[v] == INF){
                q2.push(v);
                dis2[v] = dis2[u] + 1;
            }
        }
    }

    rep(i,m){
        if(dis2[a[i]] == 1 || dis2[b[i]] == 1) continue;

        if(a[i] == n-1) to[b[i]].push_back(make_pair(a[i], 0));
        else if(dis2[a[i]] <= s+1) to[b[i]].push_back(make_pair(a[i], q));
        else to[b[i]].push_back(make_pair(a[i], p));

        if(b[i] == n-1) to[a[i]].push_back(make_pair(b[i], 0));
        else if(dis2[b[i]] <= s+1) to[a[i]].push_back(make_pair(b[i], q));
        else  to[a[i]].push_back(make_pair(b[i], p));
    }

    dijkstra(0);

    cout << dis[n-1] << endl;
}