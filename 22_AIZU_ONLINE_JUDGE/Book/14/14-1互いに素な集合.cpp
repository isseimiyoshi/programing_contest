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

class DisjointSet {
    // アクセシビリティ
    // public以下は、公開される
    public:
        vector<int> rank, p;

        // コンストラクタ
        DisjointSet(){}
        DisjointSet(int size){
            rank.resize(size, 0);
            p.resize(size, 0);
            rep(i,size) makeSet(i);
        }

        void makeSet(int x){
            p[x] = x;
            rank[x] = 0;
        }

        bool same(int x, int y){
            return findSet(x) == findSet(y);
        }

        void unite(int x, int y){
            link(findSet(x), findSet(y));
        }

        void link(int x, int y){
            if(rank[x] > rank[y]){
                p[y] = x;
            }else{ 
                // お互いの集合のランクが同じ場合は、yを親にする
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }

        int findSet(int x){
            if(x != p[x]){
                p[x] = findSet(p[x]);
            }
            return p[x];
        }
};  //　クラスの定義終了

int main()
{
    int n, q; cin >> n >> q;
    DisjointSet djs = DisjointSet(n);
    rep(_,q){
        int com; cin >> com;
        if(com == 0){
            int x, y; cin >> x >> y;
            djs.unite(x, y);
        }else if(com == 1){
            int x, y; cin >> x >> y;
            if(djs.same(x,y)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}