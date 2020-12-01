#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

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
    vector<int> rank, p, w;

    // コンストラクタ（空）
    DisjointSet(){}
    // コンストラクタ（引数あり）
    DisjointSet(int size){
        rank.resize(size, 0);
        p.resize(size, 0);
        w.resize(size, 0);
        rep(i,size) makeSet(i);
    }

    void makeSet(int x){
        p[x] = x;
        rank[x] = 0;    // 集合ランクの初期値はゼロ
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
            p[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }

    int findSet(int x){
        if(p[x] != x){
            p[x] = findSet(p[x]);   // 親を見つける過程で高さを調整する
        }
        return p[x];
    }
};

int main()
{
    int n,q; cin >> n >> q;
    DisjointSet DS(n);
    rep(i,q){
        int com; cin >> com;
        if(com == 0){
            int x, y; cin >> x >> y;
            DS.unite(x, y);
        }else if(com == 1){
            int x, y; cin >> x >> y;
            if(DS.same(x,y)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}