#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const int INF = 1000100100;

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
const int WHITE = 0, BLACK = 1;

vector<P> to2[MAX_N];
int color[MAX_N];
int d[MAX_N];

void dijkstra(int s){
    fill(color,color+MAX_N, WHITE);
    fill(d, d+MAX_N, INF);

    d[s] = 0;
    color[s] = BLACK;

    priority_queue<P> pq;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        color[u] = BLACK;

        for(auto pv: to2[u]){
            int v = pv.first, ev = pv.second;
            if(color[v] != BLACK && d[v]>d[u]+ev){
                d[v] = d[u]+ev;
                pq.push(make_pair(-d[v], v));
            }
        }
    }
}

int main()
{
    int n, k; cin >> n >> k;
    int c[n], r[n];
    rep(i,n){
        cin >> c[i] >> r[i];
    }

    vector<int> to[n];
    rep(i,k){
        int ai, bi; cin >> ai >> bi; --ai, --bi;
        to[ai].push_back(bi);
        to[bi].push_back(ai);
    }

    rep(i,n){
        int d2[n]; rep(j,n) d2[j] = INF;
        d2[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v: to[u]){
                if(d2[v] == INF){
                    d2[v] = d2[u]+1;
                    q.push(v);
                }
            }
        }
        rep(j,n){
            if(i == j) continue;
            if(d2[j]<=r[i]){
                to2[i].push_back(make_pair(j,c[i]));
            }
        }
    }

    dijkstra(0);

    cout << d[n-1] << endl;
}   