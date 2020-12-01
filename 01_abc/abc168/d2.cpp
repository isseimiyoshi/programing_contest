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

const int MAX_N = 100100;
const int INF = 1001001000;
const int WHITE = 0, GRAY = 1, BLACK = 2;

vector<int> M[MAX_N];
int p[MAX_N], d[MAX_N], color[MAX_N];

void init(){
    rep(i,MAX_N){
        d[i] = INF;
        color[i] = WHITE;
    }
}

void bfs(){
    d[0] = 0;
    color[0] = GRAY;
    queue<int> Q;
    Q.push(0);
    int u;
    while(!Q.empty()){
        u = Q.front(); Q.pop();
        for(int v: M[u]){
            if(color[v] == WHITE){
                color[v] = GRAY;
                d[v] = d[u] + 1;
                p[v] = u; p[v]++;
                Q.push(v);
            }
        }
        color[u] = BLACK;
    }
}

int main()
{
    int n, m; cin >> n >> m;
    init();
    rep(_,m){
        int x, y;
        cin >> x >> y;
        x--; y--;
        M[x].push_back(y);
        M[y].push_back(x);
    }
    bfs();
    bool isOK = true;
    rep(i,n){
        if(d[i] == INF){
            isOK = false;
        }
    }
    if(isOK){
        cout << "Yes" << endl;
        rep(i,n){
            if(i != 0) cout << p[i] << endl;
        }
    }else{
        cout << "No" << endl;
    }

}