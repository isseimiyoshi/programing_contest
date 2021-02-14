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

const int MAX_N = 100100;
const int MAX_C = 20;

int n;
vi to[MAX_N];
vi h(MAX_N,-1);
ll ans = 0;

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

void f_h(int u, int p, int hi){
  for(auto v: to[u]){
    if(v == p) continue;
    if(h[v]>0) continue;
    h[v] = hi;
    f_h(v,u,hi+1);
  }
}


int main() {
  int m; cin >> n >> m;
  uf dis(n);
  vi ai(n),bi(n);
  rep(i,m){
    int a,b; cin >> a >> b; --a,--b;
    ai[i] = a, bi[i] = b;
    to[a].push_back(b);
    to[b].push_back(a);
    dis.unite(a,b);
  }
  int k; cin >> k;
  vi c(k);
  rep(i,k){
    int ci; cin >> ci; --ci;
    c[i] = ci;
  }

  cout << "ok" << endl;

  rep(i,k){
    for(int j=i+1; j<k; j++){
      if(!dis.same(c[i],c[j])){
        cout << -1 << endl;
        return 0;
      }
    }
  }

  cout << "ok2" << endl;  

  int p = dis.root(c[0]);
  h[p] = 0;
  printf("p: %d\n", p);

  f_h(p,-1,1);

  cout << "ok3" << endl;
  vl v;
  rep(i,k){
    v.push_back(h[c[i]]);
  }
  sort(rrng(v));
  
  rep(i,k){
    if(i == 0 || i == 1){
      ans += v[i];
    }else{
      ans += (ll)2*v[i];
    }
  }
  ans++;
  cout << ans << endl;
  return 0;
}
