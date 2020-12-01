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

const int MAX_N = 200200;

int n;
vector<int> to[MAX_N];
vector<int> cnt(MAX_N);
vector<int> parent(MAX_N);

void init(){
    rep(i,MAX_N){
        cnt[i] = 0;
        parent[i] = -100;
    }
}

void decide_pare(int u){
    if(u == 0) parent[u] = -1;
    for(int d: to[u]){
        if(parent[d] == -100){
            parent[d] = u;
            decide_pare(d);
        }
    }
    
}

/*
void dfs(int u, int x){
    cnt[u] += x;
    for(int d: to[u]){
        if(d != parent[u]) dfs(d, x);
    }
}
*/

void dfs(int u){
    for(int d: to[u]){
        if(d != parent[u]){
            cnt[d] += cnt[u];
            dfs(d);
        }
    }
}

int main()
{
    cin >> n;
    int q; cin >> q;
    rep(i,n-1){
        int a, b; cin >> a >> b; --a, --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    init();
    decide_pare(0);

    /*
    cout << "親が決定しました" << endl;
    rep(i,n) cout << parent[i] << endl;
    */

    rep(_,q){
        int p, x; cin >> p >> x; --p;
        cnt[p] += x;
    }

    dfs(0);

    rep(i,n){
        cout << cnt[i];
        if(i != n-1) cout << " ";
    }cout << endl;
}