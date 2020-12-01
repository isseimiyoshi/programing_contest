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

const int MAX_N = 1000100;
const int WHITE = 0, GRAY = 1, BLACK = 2;
const int INF = 1000100100;

vector<P> to[MAX_N];
int d[MAX_N], p[MAX_N], color[MAX_N];
int N, M, K; 

void prim(){
    rep(i,MAX_N){
        d[i] = INF;
        color[i] = WHITE;
    }
    d[0] = 0;
    p[0] = -1;
    while(true){
        int mincost = INF;
        int u;
        rep(i,N){
            if(mincost > d[i] && color[i] != BLACK){
                mincost = d[i];
                u = i;
            }
        }
        if(mincost == INF) break;
        color[u] = BLACK;
        for(auto p_v: to[u]){
            int v = p_v.first; int w = p_v.second;
            if(color[v] != BLACK && d[v] > w){
                d[v] = w;
                p[v] = u;
                color[v] = GRAY;
            }
        }
    }
}

/*

5 6 2
1 2 5
1 3 3
2 3 4
2 5 7
3 4 6
4 5 5

12

*/

int main()
{
    cin >> N >> M >> K;
    rep(_,M){
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        to[a].push_back(make_pair(b, c));
        to[b].push_back(make_pair(a, c));
    }
    prim();
    ll sum = 0;
    sort(d, d+N);
    rep(i,N-K+1){
        sum += d[i];
        // cout << d[i] << endl;
    }
    cout << sum << endl;

}