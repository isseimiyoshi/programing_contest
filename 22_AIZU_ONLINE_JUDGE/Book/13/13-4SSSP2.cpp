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

struct Node { 
    int v; int c;
    // コンストラクタ
    Node(){}
    Node(int _v, int _c){
        v = _v;
        c = _c;
    }
    // 演算子オーバーロード
    bool operator>(const Node& nd1){
        return c > nd1.c;
    }
    bool operator>=(const Node& nd1){
        return c >= nd1.c;
    }
    bool operator<(const Node& nd1){
        return c < nd1.c;
    }
    bool operator<=(const Node& nd1){
        return c <= nd1.c;
    }
};

const int MAX_N = 10100;
ll INF = pow(10,10);
const int WHITE = 0, GRAY = 1, BLACK = 2;

int n;
int color[MAX_N], p[MAX_N];
ll d[MAX_N];
vector<pair<int,int>> A[MAX_N];

void init(){
    rep(i,n){
        color[i] = WHITE;
        d[i] = INF;
    }
}

void dijkstra(int u_){
    priority_queue<Node, vector<Node>, greater<Node>> pq;  // 最小の要素を取り出す優先度付きキュー
    pq.push(Node(u_,0));
    Node u;
    while(!pq.empty()){
        u = pq.top(); pq.pop(); // 次に更新する頂点を決定
        color[u.v] = BLACK;     // 更新頂点を決定集合へ移動
        if(d[u.v] < u.c) continue;  // 最小値を取り出し、それが最短でなければ無視
        // uに隣接する頂点vが存在する限り
        for(auto u_v: A[u.v]){
            if(color[u_v.first] != BLACK){
                if(d[u_v.first] > d[u.v] + u_v.second){
                    d[u_v.first] = d[u.v] + u_v.second;
                    color[u_v.first] = GRAY;
                    pq.push(Node(u_v.first, d[u_v.first]));
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    rep(i,n){
        int u; cin >> u;
        int k; cin >> k;
        rep(_,k){
            int v,c; cin >> v >> c;
            A[u].push_back(make_pair(v,c));    // 隣接リスト作成
        }
    }
    dijkstra(0);
    rep(i,n){
        printf("%d %d\n", i, d[i]);
    }
}