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

const int MAX_N = 2505;

vi to[MAX_N];
vi rto[MAX_N];

bool from1[MAX_N];
bool toN[MAX_N];
bool ok[MAX_N];

void init(){
  rep(i,MAX_N){
    from1[i] = false;
    toN[i] = false;
  }
}

void dfs(int u){
  if(from1[u]) return;
  from1[u] = true;
  for(int v: to[u]){
    dfs(v);
  }
}

void rdfs(int u){
  if(toN[u]) return;
  toN[u] = true;
  for(int v: rto[u]){
    rdfs(v);
  }
}

int main() {
  int n, m, p; cin >> n >> m >> p;
  vector<tuple<int,int,int> > edges;
  rep(i,m){
    int a,b,c; cin >> a >> b >> c;
    --a,--b;
    c -= p; // ゴールしたときに減らすコストPを辺を通る度に減らすように工夫している
    c = -c; // 最長経路問題を最短経路問題（負の辺あり）　に置き換えている
    edges.emplace_back(a,b,c);
    to[a].push_back(b);
    rto[b].push_back(a);
  }
  init();
  // 頂点0からたどり着ける頂点を絞り込む
  dfs(0);
  // 頂点n-1にたどり着く頂点を絞り込む
  rdfs(n-1);
  
  rep(i,n) ok[i] = from1[i] && toN[i];

  { // bellman-ford実装
    vector<int> d(n,INF);
    d[0] = 0;
    bool upd = true;
    int step = 0;
    while(upd){
      upd = false;
      rep(i,m){
        int a,b,c;
        tie(a,b,c) = edges[i];
        if(!ok[a]) continue;
        if(!ok[b]) continue;
        int res = d[a]+c;
        if(res<d[b]){
          upd = true;
          d[b] = res;
        }
      }
      step++;
      if(step>n){
        puts("-1");
        return 0;
      }
    }
    int ans = -d[n-1];
    ans = max(0,ans);
    cout << ans << endl;
  }
  return 0;
}
