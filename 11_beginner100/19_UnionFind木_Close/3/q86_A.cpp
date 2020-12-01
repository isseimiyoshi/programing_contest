#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const int INF = 1000100100;

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
    int n, m; cin >> n >> m;
    int a[m], b[m];
    rep(i,m){
        cin >> a[i] >> b[i];
        --a[i], --b[i];
    }

    int ans = 0;
    rep(i,m){
        DisjointSet dis = DisjointSet(n);
        rep(j,m){
            if(i == j) continue;
            dis.unite(a[j], b[j]);
        }
        bool isok = true;
        rep(j,n){
            rep(k,n){
                if(!dis.same(j,k)) isok = false;
            }
        }
        if(!isok) ans++;
    }
    cout << ans << endl;
}