#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

void chmin(int &a, int b){ a = min(a,b); }

int main() {
  int n,m; cin >> n >> m;
  vector<vector<int>> to(n);
  rep(i,m){
    int a,b; cin >> a >> b;
    --a,--b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  int k; cin >> k;
  vi c(k);
  rep(i,k) cin >> c[i], --c[i];

  vector<vector<int>> dist(k,vector<int>(k)); // 魔法石同士の隣接マトリックス

  auto bfs = [&](int sv){
    vi dist(n,INF);
    queue<int> q;
    q.push(sv);
    dist[sv] = 0;
    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(int u: to[v]){
        if(dist[u] != INF) continue;
        dist[u] = dist[v]+1;
        q.push(u);
      }
    }
    return dist;
  };

  rep(i,k){
    vi d = bfs(c[i]);
    rep(j,k) dist[i][j] = d[c[j]];
  }

  int k2 = 1<<k;
  vector<vector<int>> dp(k2,vector<int>(k,INF));
  rep(i,k) dp[1<<i][i] = 1;
  rep(s,k2) rep(i,k) {  // i：いまいる頂点
    if(~s>>i&1) continue;
    rep(j,k){
      if(s>>j&1) continue;  // j：次に訪れる頂点
      chmin(dp[s|(1<<j)][j], dp[s][i]+dist[i][j]);
    }
  }
  int ans = INF;
  rep(i,k) chmin(ans, dp[k2-1][i]);
  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}