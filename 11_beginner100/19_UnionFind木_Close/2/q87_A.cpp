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
        rep(i,n) p[i] = i;
    } 

    int root(int x){
        if(p[x] == x) return x;
        return p[x] = root(p[x]);
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
    ll n, m; cin >> n >> m;
    int a[m], b[m];
    rep(i,m){
        cin >> a[i] >> b[i];
        --a[i], --b[i];
    }
    reverse(a, a+m);
    reverse(b, b+m);    

    DisjointSet dis = DisjointSet(n);

    vector<ll> num(n);
    rep(i,n) num[i] = 1;

    ll ans[m];
    ans[0] = n*(n-1)/2;

    rep(i,m-1){
        // printf("%d, %d\n", dis.root(a[i]), dis.root(b[i]));
        int ori_a = dis.root(a[i]);
        int ori_b = dis.root(b[i]);
        if(ori_a == ori_b){
            ans[i+1] = ans[i];
        }else{
            ans[i+1] = ans[i] - num[ori_a]*num[ori_b];
            dis.unite(a[i], b[i]);
            num[ori_a] = num[ori_b] = num[ori_a]+num[ori_b];
        }
    }
    /*
    rep(i,m-1){
        int rootb = dis.root(b[i]);
        int roota = dis.root(a[i]);
        if(roota == rootb){
            // dis.unite(a[i], b[i]);
            ans[i+1] = ans[i];
        }else{
            ans[i+1] = ans[i] - num[rootb]*num[roota];
            num[rootb] += num[roota];
            num[roota] = 0;
            dis.unite(a[i], b[i]);
        }
    }
    */
    reverse(ans, ans+m);
    rep(i,m) cout << ans[i] << endl;
}