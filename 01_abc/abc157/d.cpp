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
    vector<int> p;
    DisjointSet(int n) : p(n){
        rep(i,n) p[i] = -1;
    }

    int root(int x){
        if(p[x] < 0) return x;
        return p[x] = root(p[x]);
    }

    int size(int x){
        return -p[root(x)];
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        if(rx > ry) swap(rx,ry);
        p[rx] += p[ry];
        p[ry] = rx;
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main()
{
    int n, m, k; cin >> n >> m >> k;
    int a[m], b[m];
    rep(i,m) cin >> a[i] >> b[i], --a[i], --b[i];
    int c[k], d[k];
    rep(i,k) cin >> c[i] >> d[i], --c[i], --d[i];

    DisjointSet fdis = DisjointSet(n);
    DisjointSet bdis = DisjointSet(n);

    int fnum[n]; rep(i,n) fnum[i] = 0;
    int bnum[n]; rep(i,n) bnum[i] = 0;

    rep(i,m){
        fdis.unite(a[i], b[i]);
        fnum[a[i]]++;
        fnum[b[i]]++;
    }
    rep(i,k){
        if(fdis.same(c[i], d[i])){
            bnum[c[i]]++;
            bnum[d[i]]++;
        }
    }

    rep(i,n){
        cout << (fdis.size(i)-1 - fnum[i] - bnum[i]);
        if(i != n-1) cout << " ";
    }cout << endl;
}