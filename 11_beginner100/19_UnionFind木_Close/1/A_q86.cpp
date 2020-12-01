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

int main()
{
    int N, M; cin >> N >> M;
    int a[M], b[M];
    rep(i,M) cin >> a[i] >> b[i], --a[i], --b[i];
    // このループでカウントしない辺を決めている
    int cnt = 0;
    rep(i,M){
        DisjointSet dis = DisjointSet(N);
        rep(j,M){
            if(j == i) continue;
            else dis.unite(a[j], b[j]);
        }
        rep(k,N){
            if(!dis.same(0,k)){
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
}