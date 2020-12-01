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
    DisjointSet(int n){
        p.resize(n, 0);
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

    void reset(int n){
        rep(i,n) p[i] = i;
    }
};

int main()
{
    int n, m; cin >> n >> m;
    int a[n], b[n];
    rep(i,m){
        cin >> a[i] >> b[i];
        --a[i], --b[i];
    }

    DisjointSet dis = DisjointSet(n);
    int ans = 0;
    rep(i,m){   // 辺iを今回の素なグラフから抜く
        rep(j,m){
            if(i == j) continue;
            dis.unite(a[j], b[j]);
        }
        int origin = 0;
        rep(j,n){
            if(dis.same(origin, j)) continue;
            else{
                ans++;
                break;
            }
        }
        dis.reset(n);
    }
    cout << ans << endl;
}