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

const int MAX_N = 200005;
const int INF = 1001001001;

vector<int> a, ans;
vector<int> to[MAX_N];   // 隣接リストとして使用する変数
int dp[MAX_N];  // LIS(最長増加部分列)を求める際のDP（動的計画法）で使用する多次元配列

void dfs(int v, int p=-1){
    int i = lower_bound(dp, dp+MAX_N, a[v]) - dp;    // スタート位置のインデックスを求める
    int old = dp[i];
    dp[i] = a[v];
    ans[v] = i;
    if(p != -1) ans[v] = max(ans[v], ans[p]);
    for(int u: to[v]){
        if(u == p) continue;
        dfs(u, v);
    }
    dp[i] = old;
}

int main()
{
    int n; cin >> n;
    a = ans = vector<int>(n);
    rep(i,n) cin >> a[i];
    // 隣接リストに各辺の情報を格納していく
    rep(i,n-1){ // 辺の数はn-1
        int u, v; cin >> u >> v;
        u--; v--;   // インデックスの番号と整合性をとるためにデクリメントする
        to[v].push_back(u);
        to[u].push_back(v);
    }
    rep(i,MAX_N) dp[i] = INF;   // 初期化
    dp[0] = -INF;
    dfs(0);
    rep(i,n) cout << ans[i] << endl;
    return 0;
}