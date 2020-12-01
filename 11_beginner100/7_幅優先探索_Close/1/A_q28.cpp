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

vector<int> to[MAX_N];
int dist[MAX_N];

void init(){
    rep(i,MAX_N) dist[i] = -1;
}

int main()
{
    int n; cin >> n;
    init();
    rep(_,n){
        int u, k; cin >> u >> k; --u;
        rep(_k, k){
            int vi; cin >> vi; --vi;
            to[u].push_back(vi);
        }
    }
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v: to[u]){
            if(dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
    rep(i,n) printf("%d %d\n", i+1, dist[i]);
}