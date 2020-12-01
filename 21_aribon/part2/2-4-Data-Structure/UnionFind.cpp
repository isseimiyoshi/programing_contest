#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_K = 100000 , MAX_N = 50000;
int N, K;
int T[MAX_K], X[MAX_K], Y[MAX_K];

// -----------------------Union_Find木のソースコード-----------------------
int par[MAX_N];     // 親
int myrank[MAX_N];    // 木の深さ

// n要素で初期化
void init(int n){
    for(int i=0; i<n; i++){
        par[i] = i;
        myrank[i] = 0;
    }
}

// 木の根を求める
int find(int x){
    if(par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

// xとyの属する集合を併合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(myrank[x] < myrank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        // 木xと木yの深さが同じ場合、併合すると元の木の深さより１深くなるため
        if(myrank[x] == myrank[y]) myrank[x]++;
    }
}

// xとyが同じ集合に属するか否か
bool same(int x, int y){
    return find(x) == find(y);
}
// ---------------------------------------------------------------------

void solve(){
    // Union-Find木を初期化
    // x, x+N, x+2*Nをそれぞれx-A, x-B, x-Cの要素とする
    init(N*3);

    int ans = 0;
    // Kは命令の数
    for(int i=0; i<K; i++){
        int t = T[i];
        int x = X[i] - 1, y = Y[i] - 1; // 0, ..., N-1の範囲にする
        // 正しくない番号
        if(x<0 || N<=x || y<0 || N<=y){
            ans++;
            continue;
        }
        if(t==1){
            // xとyは同じ種類という情報
            if(same(x, y+N) || same(x, y+2*N)){
                ans++;
            }else{
                unite(x, y);            // x-A & y-A
                unite(x+N, y+N);        // x-B & y-B
                unite(x+2*N, y+2*N);    // x-C & y-C
            }
        }else{
            // xはyを食べるという情報(x-A & y-B, x-B & y-C, x-C & y-A)
            if(same(x, y) || same(x, y+2*N)){
                ans++;
            }else{
                unite(x, y+N);
                unite(x+N, y+2*N);
                unite(x+2*N, y);
            }
        }
    }
    printf("%d\n", ans);
}

/*

100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5

*/

int main()
{
    cin >> N >> K;
    for(int i=0; i<K; i++){
        int t, x, y;
        cin >> t >> x >> y;
        T[i]=t; X[i]=x; Y[i]=y;
    }
    solve();
}