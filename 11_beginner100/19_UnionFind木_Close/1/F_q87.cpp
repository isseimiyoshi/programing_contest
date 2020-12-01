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
    vector<int> p;

    DisjointSet(int N){
        // 1次元配列pは、各ノードの親番号を格納する配列
        // ノードが親である場合は、-(size)を格納する（初期値は-1)
        p = vector<int>(N,-1);
    }

    int root(int x){
        if(p[x] < 0) return x;
        return p[x] = root(p[x]);   // xの親番号を根の番号に変更することによって経路圧縮を実現している
    }

    int size(int x){
        return (-1)*root(x);
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        // もし入力された２つのノードが同じグループである場合は何もしない
        if(rx == ry) return;
        if(size(x) < size(y)) swap(x, y);
        p[root(x)] += p[root(y)];
        p[root(y)] = x;
    }

};

int main()
{
    int N, M; cin >> N >> M;
    int A[M], B[M];
    rep(i,M){
        cin >> A[i] >> B[i];
        A[i]--, B[i]--;
    }
    DisjointSet dis = DisjointSet(N);
    ll ans[M];
    ans[M-1] = N*(N-1)/2;
    for(int i=M-1; i>=1; i--){
        int Ai = A[i]; int Bi = B[i];
        if(dis.root(Ai) != dis.root(Bi)){
            ans[i-1] = ans[i] - dis.size(Ai)*dis.size(Bi);
            dis.unite(Ai, Bi);
        }else{
            ans[i-1] = ans[i];
        }
    }
    rep(i,M) cout << ans[i] << endl;
}