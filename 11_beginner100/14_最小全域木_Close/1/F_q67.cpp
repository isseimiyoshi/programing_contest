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
const int WHITE = 0, GRAY = 1, BLACK = 2;
const int INF = 1000100100;

vector<P> to[MAX_N];
int d[MAX_N], p[MAX_N], color[MAX_N];
int N; 

class DisjointSet{
    public:
        vector<int> rank, p;
        // コンストラクタ
        DisjointSet(){}
        DisjointSet(int size){
            rank.resize(size,0);    // vectorのサイズを変更して、デフォルト値として0を代入している
            p.resize(size, 0);
            rep(i,size) makeSet(i);
        }

        // 入力値xのみの集合を作成する
        void makeSet(int x){
            p[x] = x;
            rank[x] = 0;
        }
        // ２つの入力要素が同じ集合か否かを判別する
        bool same(int x, int y){
            return findSet(x) == findSet(y);
        }
        // 2つの集合を結合する
        void unite(int x, int y){
            link(findSet(x), findSet(y));
        }

        void link(int x, int y){
            if(rank[x]>rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }

        int findSet(int x){
            if(x != p[x]){
                // 経路圧縮をしている
                p[x] = findSet(p[x]);
            }
            // 親要素と自分の要素が一致したときに親を返す
            return p[x];
        }
};


class Edge {
    public:
        int source, target, cost;
        // コンストラクタ
        Edge(int source=0, int target=0, int cost=0):
        source(source), target(target), cost(cost) {}
        bool operator < (const Edge &e) const {
            return cost < e.cost;
        }
};

int kruskal(int N, vector<Edge> edges){
    int totalCost = 0;
    sort(edges.begin(), edges.end());

    DisjointSet dset = DisjointSet(N+1);

    rep(i,N) dset.makeSet(i);

    int source, target;
    rep(i,edges.size()){
        Edge e = edges[i];
        if(!dset.same(e.source, e.target)){
            //MST.push_back(e);
            totalCost += e.cost;
            dset.unite(e.source, e.target);
        }
    }
    return totalCost;
}

int main()
{
    cin >> N;
    vector<P> p_x(N);
    vector<P> p_y(N);
    rep(i,N){
        int x, y; cin >> x >> y;
        // xまたはy座標と点の番号を格納する（ソートしてもわからなくならないため）
        p_x[i] = make_pair(x, i);
        p_y[i] = make_pair(y, i);
    }
    sort(p_x.begin(), p_x.end());
    sort(p_y.begin(), p_y.end());
    vector<Edge> edges;
    for(int i=1; i<N; i++){
        /*
        to[p_x[i].second].push_back(make_pair(p_x[i-1].second, p_x[i].first - p_x[i-1].first));
        to[p_x[i-1].second].push_back(make_pair(p_x[i].second, p_x[i].first - p_x[i-1].first));
        to[p_y[i].second].push_back(make_pair(p_y[i-1].second, p_y[i].first - p_y[i-1].first));
        to[p_y[i-1].second].push_back(make_pair(p_y[i].second, p_y[i].first - p_y[i-1].first));
        */
        edges.push_back(Edge(p_x[i].second, p_x[i-1].second, p_x[i].first - p_x[i-1].first));
        edges.push_back(Edge(p_x[i-1].second, p_x[i].second, p_x[i].first - p_x[i-1].first));
        edges.push_back(Edge(p_y[i].second, p_y[i-1].second, p_y[i].first - p_y[i-1].first));
        edges.push_back(Edge(p_y[i-1].second, p_y[i].second, p_y[i].first - p_y[i-1].first));

    }

    cout << kruskal(N, edges) << endl;
    return 0;
}