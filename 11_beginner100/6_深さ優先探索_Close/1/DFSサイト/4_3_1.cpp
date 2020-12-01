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

struct Node{ 
    int v; int w;

    Node() {}

    // コンストラクタ
    Node(int _v, int _w){
        v = _v;
        w = _w;
    }
};

vector<Node> to[MAX_N];
int color[MAX_N];
int n;

void init(){
    rep(i,MAX_N){
        color[i] = NONE;
    }
}

bool dfs(int u, int cur = WHITE){
    color[u] = cur;
    for(Node node: to[u]){
        // 隣接頂点の色がすでに確定していた場合
        if(color[node.v] != NONE){
            if((color[node.v] == cur && node.w % 2 == 1) || (color[node.v] != cur && node.w % 2 == 0)) return false;
            continue;
        }
        // 辺の重みを2で割った値に合わせて隣接頂点に色を塗る
        if(node.w % 2 == 1) if(!dfs(node.v, 1-cur)) return false;
        if(node.w % 2 == 0) if(!dfs(node.v, cur)) return false;
    }
    return true;
}

int main()
{
    cin >> n;   
    init();     // 初期化
    rep(_,n-1){
        int u, v, w; cin >> u >> v >> w;
        --u; --v;
        Node node1(v, w);
        Node node2(u, w);
        to[u].push_back(node1);
        to[v].push_back(node2);
    }
    if(dfs(0)){
        rep(i,n){
            cout << color[i] << endl;
        }
    }
    // cout << to[0][0].v << "," << to[0][0].w << endl;
}