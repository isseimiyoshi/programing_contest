#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

struct DisjointSet{
    vector<int> p;
    DisjointSet(int N) : p(N){
        rep(i,N) p[i] = i;
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

/*

00:18::36

*/

int main()
{
    int i = 7;
    // bitset<3> b(i);
    cout << ~i << endl;
}