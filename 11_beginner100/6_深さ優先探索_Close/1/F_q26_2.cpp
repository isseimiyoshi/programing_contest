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

vector<int> to[200100];
vector<int> ans;
void dfs(int u, int p=-1){
    for(int v: to[u]){
        if(v == p) continue;
        ans[v] += ans[u];
        dfs(v, u);
    }
}

/*

部分木すべてに指定の値を足す　＝　親に指定の値を足しておいて、あとで累積和すると答えが求まる
木構造の累積和は、無向の隣接リストというデータ構造で深さ優先探索の引数に親のノード番号を記録しておくことによって可能になる

*/


int main()
{
    int N, Q; cin >> N >> Q;
    rep(i,N-1){
        int a, b; cin >> a >> b;
        --a; --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    ans.resize(N);  // vectorのサイズをNに変更する、デフォルトは0らしい
    rep(i,Q){
        int p, x; cin >> p >> x;
        --p;
        ans[p] += x;
    }
    dfs(0);
    rep(i,N){
        cout << ans[i];
        if(i != N-1) cout << " ";
    }cout << endl;
}