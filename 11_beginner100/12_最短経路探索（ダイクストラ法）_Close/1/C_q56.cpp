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

const int MAX_V = 100100;
const int WHITE = 0, GRAY = 1, BLACK = 2;
const int INF = 1000100100;

int color[MAX_V], d[MAX_V];
vector<pair<int, int>> to[MAX_V];

void init(){
    rep(i,MAX_V){
        color[i] = WHITE;
        d[i] = INF;
    }
}

void dijkstra(int r){
    d[r] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair((-1)*d[r], r));
    while(!pq.empty()){
        P u = pq.top(); pq.pop();
        color[u.second] = BLACK;
        //　最小値を取り出し、それが最短でなければ無視
        if(d[u.second] < (-1)*u.first) continue;
        for(auto v: to[u.second]){
            if(d[v.first] > d[u.second] + v.second && color[v.first] != BLACK){
                d[v.first] = d[u.second] + v.second;
                color[v.first] = GRAY;
                pq.push(make_pair((-1)*d[v.first], v.first));
            }
        }
    }
}

int main()
{
    int V, E, r; cin >> V >> E >> r;
    rep(_,E){
        int s, t, d; cin >> s >> t >> d;
        to[s].push_back(make_pair(t, d));
    }
    init();
    dijkstra(r);
    rep(i,V){
        if(d[i] == INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}