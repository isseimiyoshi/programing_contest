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

int main()
{
    int n, q; cin >> n >> q;
    DisjointSet ds = DisjointSet(n);    // コンストラクタが呼び出される
    rep(_,q){
        int com, xi, yi; cin >> com >> xi >> yi;
        if(com == 0){
            ds.unite(xi,yi);
        }else if(com == 1){
            if(ds.same(xi, yi)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}