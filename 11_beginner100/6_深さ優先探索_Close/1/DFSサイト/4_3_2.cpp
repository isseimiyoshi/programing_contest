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
const int NONE = -1, WHITE = 0, BLACK = 1;

int n, color[MAX_N];
vector<int> to[MAX_N];

void init(){
    rep(i,MAX_N) color[i] = NONE;
}

// 二部グラフかどうか判定するときには深さ優先探索を用いる方法が効率的である
bool dfs(int u, int cur=WHITE){
    color[u] = cur;
    for(int v: to[u]){
        if(color[v] != NONE){
            if(color[v] == cur) return false;
            continue;
        }
        // 隣接頂点の色がまだ確定していない場合は確定させる
        if(!dfs(v,1-cur)) return false; // 先々の探索で二部グラフ条件に反する頂点が発見された場合はfalseを返す
    }
    return true;
}

int main()
{
    int m; cin >> n >> m;
    init();
    int a, b;
    rep(_,m){
        cin >> a >> b;
        --a; --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    if(dfs(a)){
        int Wn=0, Bn=0;
        rep(i,MAX_N){
            if(color[i] == WHITE) ++Wn;
            else if(color[i] == BLACK) ++Bn;
            else continue;
        }
        cout << Wn*Bn - m << endl;
    }else{
        cout << n*(n-1)/2 - m << endl;
    }
}