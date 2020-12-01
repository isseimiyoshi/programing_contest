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

const int MAX_N = 110;
const int WHITE = 0, BLACK = 1;

vector<P> to[MAX_N];
int color[MAX_N];
int d[MAX_N];

void init(){
    rep(i,MAX_N){
        d[i] = INF;
        color[i] = WHITE;
    }
}

void dijkstra(int s){
    init();

    d[s] = 0;
    color[s] = BLACK;

    priority_queue<P> q;
    q.push(make_pair(0,s));

    while(!q.empty()){
        int u = q.top().second, du = q.top().first;
        q.pop();
        color[u] = BLACK;

        for(auto pv: to[u]){
            int v = pv.first, e = pv.second;
            if(color[v] == WHITE && d[v]>d[u]+e){
                d[v] = d[u]+e;
                q.push(make_pair(-d[v], v));
            }
        }
    }
}



int main()
{
    int n, k; cin >> n >> k;
    rep(_,k){
        int q; cin >> q;
        if(q == 0){
            int a, b; cin >> a >> b; --a, --b;
            dijkstra(a);
            if(d[b] == INF) cout << -1 << endl;
            else cout << d[b] << endl;
        }else{
            int s, t, e; cin >> s >> t >> e;
            --s, --t;
            to[s].push_back(make_pair(t,e));
            to[t].push_back(make_pair(s,e));
        }
    }
}