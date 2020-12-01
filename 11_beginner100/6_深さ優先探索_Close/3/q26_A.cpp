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

const int MAX_N = 2000200;

int n, q; 
vector<int> d[MAX_N];
bool finish[MAX_N];
int cnt[MAX_N];

void init(){
    rep(i,MAX_N){
        finish[i] = false;
        cnt[i] = 0;
    }
}

void dfs(int u){
    finish[u] = true;
    for(int v: d[u]){
        if(!finish[v]){
            // cout << v << endl;
            cnt[v] += cnt[u];
            dfs(v);
        }
    }
    // cout << u << endl;
}

int main()
{
    cin >> n >> q;
    rep(i,n-1){
        int ai, bi; cin >> ai >> bi;
        --ai, --bi;
        d[ai].push_back(bi);
        d[bi].push_back(ai);
    }

    init();

    rep(i,n){
        cnt[i] = 0;
    }
    rep(i,q){
        int pi, xi; cin >> pi >> xi;
        --pi;
        cnt[pi] += xi;
    }

    dfs(0);

    rep(i,n){
        cout << cnt[i];
        if(i != n-1) cout << " ";
    }cout << endl;
}