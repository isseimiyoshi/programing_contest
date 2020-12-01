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

// DFSを実装する場合はグローバルに変数をとる必要性がある

struct Edge {
  int to, id;
};

vector<vector<Edge> > g;
vector<int> ans;

// デフォルト引数
void dfs(int v, int c=-1, int p=-1){
  int k = 1;
  rep(i,(int)g[v].size()){
    int u = g[v][i].to, ei = g[v][i].id;
    if(u == p) continue;
    if(k == c) k++;
    ans[ei] = k; ++k;
    dfs(u, ans[ei], v);
  }
}


int main() {
  int n; cin >> n;
  g.resize(n);
  ans = vector<int>(n-1);
  rep(i,n-1){
    int a, b; cin >> a >> b; --a,--b;
    g[a].push_back((Edge){b,i});
    g[b].push_back((Edge){a,i});
  }
  dfs(0);
  int mx = 0;
  rep(i,n) mx = max(mx,int(g[i].size()));
  cout << mx << endl;
  rep(i,n-1) cout << ans[i] << endl;
  return 0;
}
