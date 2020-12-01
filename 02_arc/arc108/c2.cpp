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

// Unionfind
struct uf{
  vi d;
  uf() {};
  uf(int mx) : d(mx,-1) {};
  int root(int x){
    if(d[x]<0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y){
    x = root(x); y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y]; d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y);}
  int size(int x){ return -d[root(x)];}
  int operator[] (int x) {return root(x);}
  int operator() (int x) {return size(x);}
};

const int MAX_N = 200100;

int n;
vp d[MAX_N];
int label[MAX_N];

void init(){
  rep(i,MAX_N) label[i] = -1;
}

void dfs(int u, int c){
  label[u] = c;
  for(auto dp: d[u]){
    int v = dp.first, vc = dp.second;
    if(label[v]>=0) continue;
    if(c == vc){
      if(c == 1) dfs(v,2);
      else dfs(v,1);
    }else{
      dfs(v,vc);
    }
  }
}

int main() {
  int m; cin >> n >> m;
  uf dis(n);
  rep(i,m){
    int u,v,c; cin >> u >> v >> c;
    --u,--v;
    d[u].push_back(make_pair(v,c));
    d[v].push_back(make_pair(u,c));
    dis.unite(u,v);
  }

  set<int> s;
  rep(i,n) s.insert(dis.root(i));
  if(s.size()>1){
    cout << "No" << endl;
    return 0;
  } 

  init();
  dfs(0,1);

  rep(i,n) cout << label[i] << endl;

  return 0;
}
