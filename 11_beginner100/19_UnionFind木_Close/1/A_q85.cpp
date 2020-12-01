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

struct DisjointSet {
    vector<int> p;  // ノードの親を格納する配列
    DisjointSet(int N) : p(N){
        rep(i,N) p[i] = i;  // 初期ではすべてのノードを根として設定する
    }
    // あるノードの根を求める
    int root(int x){
        if(p[x] == x) return x;
        return root(p[x]);
    }

    // ある２つのデータの属するグループが異なる場合に併合する
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        p[rx] = ry;
    }

    // ある異なる２つのデータが同じグループに属するか判定する
    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main()
{
    int n, q; cin >> n >> q;
    DisjointSet dis = DisjointSet(n);
    rep(_,q){
        int com; cin >> com;
        if(com == 0){
            int x, y; cin >> x >> y;
            dis.unite(x, y);
        }else if(com == 1){
            int x, y; cin >> x >> y;
            if(dis.same(x, y)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}