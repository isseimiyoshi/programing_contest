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

const int MAX_V = 50;
const int MAX_S = MAX_V*50+5;

struct Edge {
  int to,a,b; // to：行先
  Edge(int to, int a, int b): to(to),a(a),b(b) {}
};

struct Data{
  int v,s;
  ll x;
  Data(int v, int s, ll x): v(v),s(s),x(x) {}
  bool operator<(const Data& a) const {
    return x > a.x;
  }
};

vector<Edge> g[MAX_V];
ll dist[MAX_V][MAX_S+5];  // 1次元：頂点、2次元：所持銀貨枚数


int main() {
  int n,m,s; cin >> n >> m >> s;
  rep(i,m){
    int u,v,a,b;
    cin >> u >> v >> a >> b;
    --u,--v;
    g[u].emplace_back(v,a,b);
    g[v].emplace_back(u,a,b);
  }
  vector<int> c(n), d(n);
  rep(i,n) cin >> c[i] >> d[i];

  rep(i,n) rep(j,MAX_S+5) dist[i][j] = LINF;  // 初期化
  s = min(s,MAX_S); // 所持金が多すぎると意味がない

  priority_queue<Data> q;

  auto push = [&](int v, int s, ll x){
    if(s<0) return;
    if(dist[v][s] <= x) return;
    dist[v][s] = x;
    q.emplace(v,s,x);
  };

  push(0,s,0);  // 初期状態を突っ込む

  while(!q.empty()){
    Data hoge = q.top(); q.pop();
    int v = hoge.v, s = hoge.s; ll x = hoge.x;
    if(dist[v][s] != x) continue; // 現時点での最小値を取り出したいため、それ以外のものは飛ばす
    {
      int ns = min(s+c[v], MAX_S);
      push(v,ns,x+d[v]);
    }
    for(Edge e: g[v]){
      push(e.to, s-e.a, x+e.b);
    }
  }

  // 答えを出力する
  for(int i=1; i<n; i++){
    ll ans = LINF;
    rep(j,MAX_S+5){
      ans = min(ans, dist[i][j]);
    }
    cout << ans << endl;
  }
  return 0;
}
