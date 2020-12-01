#include <bits/stdc++.h>
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
using namespace std;
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

const int MAX_N = 1010;

int n;
vi to[MAX_N];

vi bfs(int sv){
  vi dist(n,INF), pre(n,-1);
  queue<int> q;
  dist[sv] = 0;
  q.push(sv);
  while(!q.empty()){
    int v = q.front(); q.pop();
    for(int u: to[v]){
      if(dist[u] != INF) continue;  // すでに探索済み
      pre[u] = v;
      dist[u] = dist[v]+1;
      q.push(u);
    }
  }

  P best(INF,-1);
  rep(v,n){
    if(v == sv) continue;
    for(int u: to[v]){
      if(u == sv){
        best = min(best, make_pair(dist[v],v));
      }
    }
  }
  if(best.first == INF) return vi(n+1); // スタート地点に戻っている辺がない場合はサイクルを作ることができないので、不可能と同義のものをリターンする
  int v = best.second;
  vi res;
  while(v != -1){
    res.push_back(v);
    v = pre[v];
  }
  return res;
}

int main() {
  int m; cin >> n >> m;
  rep(i,m){
    int a,b; cin >> a >> b; --a,--b;
    to[a].push_back(b);
  }

  vi ans(n+1);
  rep(s,n){
    auto now = bfs(s);
    if(now.size() < ans.size()) ans = now;
  }
  if(ans.size() == n+1){
    cout << -1 << endl;
    return 0;
  }
  cout << ans.size() << endl;
  for(int v: ans){
    cout << v+1 << endl;
  }
  return 0;
}
