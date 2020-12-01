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

struct DisjointSet{
    vector<int> p;  // ノードの親を格納する１次元ベクトル
    // コンストラクタ
    DisjointSet(int n) : p(n){
        rep(i,n) p[i] = i;
    }

    int root(int x){
        if(p[x] == x) return x;
        return root(p[x]);
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        p[rx] = ry;
    }

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
        int com, x, y; cin >> com >> x >> y;
        if(com == 0){
            dis.unite(x, y);
        }else{
            if(dis.same(x, y)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}