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
    int N, M, cost;
    int source, target;

    cin >> N >> M;

    vector<Edge> edges;
    rep(i,M){
        cin >> source >> target >> cost;
        edges.push_back(Edge(source, target, cost));
    }
    cout << kruskal(N, edges) << endl;

    return 0;
}