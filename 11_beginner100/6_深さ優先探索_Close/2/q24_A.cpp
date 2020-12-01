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

const int MAX_N = 105;

int n, t;
vector<int> d[MAX_N];

int s[MAX_N], g[MAX_N];

void init(){
    rep(i,MAX_N){
        s[i] = -1;
        g[i] = -1;
    }
}

void dfs(int u){
    if(s[u] == -1) s[u] = ++t;

    for(int to: d[u]){
        if(s[to] == -1) dfs(to);
    }

    if(g[u] == -1) g[u] = ++t;
}

int main()
{
    cin >> n;
    rep(i,n){
        int u; cin >> u; --u;
        int k; cin >> k;
        rep(_,k){
            int vi; cin >> vi; vi--;
            d[u].push_back(vi);
        }
    }

    // 初期化
    init();

    t = 0;
    dfs(0);

    rep(i,n) cout << s[i] << endl;
    rep(i,n) cout << g[i] << endl;
}