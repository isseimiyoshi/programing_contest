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
        if(p[x]<0) return x;
        return p[x] = root(p[x]);
    }

    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if(p[rx]>p[ry]) swap(rx,ry);
        p[rx] += p[ry];
        p[ry] = rx;
    }

    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

const int MAX_N = 100100;
const int mod = 1000000007;

int n;
vector<int> to[MAX_N];
int flag[MAX_N];

int dp[MAX_N][2];

void init(){
    rep(i,MAX_N){
        rep(j,2) dp[i][j] = 0;
        flag[i] = 0;
    }
}

void f(int x, int p){
    if(flag[x] == 1) return;
    
    flag[x] = 1;
    dp[x][0] = 1;
    dp[x][1] = 1;
    for(int y: to[x]){
        // printf("x y: %d %d\n",x, y);
        if(p == y) continue;
        f(y, x);
        
        dp[x][0] = dp[x][0]*(dp[y][0]+dp[y][1])%mod;
        dp[x][1] = dp[x][1]*dp[y][0]%mod;
    }
}

int main()
{
    cin >> n;

    DisjointSet dis = DisjointSet(n);

    rep(i,n-1){
        int xi, yi; cin >> xi >> yi; --xi, --yi;
        dis.unite(xi,yi);
        to[xi].push_back(yi);
        to[yi].push_back(xi);
    }

    int root = dis.root(0);

    init();
    f(root, -1);

    ll res = 0;
    res = dp[root][0] + dp[root][1];
    res %= mod;
    
    cout << res << endl;
}