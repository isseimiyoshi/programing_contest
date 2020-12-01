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

const int MAX_N = 100100;
const int WHITE = 0, BLACK = 1;

vector<int> to[MAX_N];
bool inov[MAX_N];
int color[MAX_N];
ll d[MAX_N];

int n;
int p, q; 

void init(){
    rep(i,MAX_N){
        inov[i] = false;
        color[i] = WHITE;
        d[i] = INF;
    }
}

void dijkstra(int s){
    d[s] = 0;
    color[s] = BLACK;

    priority_queue<P> pq;
    pq.push(make_pair(0,s));
    while(!pq.empty()){
        int u = pq.top().second;//, ue = -pq.top().first;
        pq.pop();
        color[u] = BLACK;
        for(int v: to[u]){
            int ve;
            if(v == n-1) ve = 0;
            else if(inov[v]) ve = q;
            else ve = p;
            if(color[v] != BLACK && d[v]>d[u]+ve){
                d[v] = d[u]+ve;
                pq.push(make_pair(-d[v], v));
            }
        }
    }
}

int main()
{
    int m, k, s; cin >> n >> m >> k >> s;
    cin >> p >> q;
    
    int c[k];
    rep(i,k) cin >> c[i], --c[i];
    rep(i,m){
        int ai, bi; cin >> ai >> bi; --ai, --bi;
        to[ai].push_back(bi);
        to[bi].push_back(ai);
    }
    
    rep(i,k) to[n].push_back(c[i]);

    int d2[n+1]; rep(i,n) d2[i] = INF;
    d2[n] = 0;
    queue<int> qu;
    qu.push(n);
    while(!qu.empty()){
        int u = qu.front(); qu.pop();
        for(int v: to[u]){
            if(d2[v] == INF){
                d2[v] = d2[u]+1;
                qu.push(v);
            }
        }
    }
    
    rep(i,n+1) cout << d2[i] << " ";
    cout << endl;
    

    init();
    rep(i,n){
        if(d2[i]<=s+1) inov[i] = true;
    }

    dijkstra(0);

    cout << d[n-1] << endl;
}