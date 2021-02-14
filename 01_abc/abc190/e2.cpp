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

const int MAX_N = 100100;
const int MAX_K = 18;

vi to[MAX_N];

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

ll d[MAX_K][MAX_N];

void init(){
  rep(i,MAX_K){
    rep(j,MAX_N){
      d[i][j] = LINF;
    }
  }
}

int main() {
  int n,m; cin >> n >> m;
  vi a(m),b(m);
  rep(i,m) cin >> a[i] >> b[i], --a[i], --b[i];
  int k; cin >> k;
  vi c(k);
  rep(i,k) cin >> c[i], --c[i];

  // もしすべての必要な魔法石が同じグループでなければ、条件を満たすことは不可能
  uf dis(n);
  rep(i,m){
    to[a[i]].push_back(b[i]);
    to[b[i]].push_back(a[i]);
    dis.unite(a[i],b[i]);
  }
  int p = dis.root(c[0]);
  rep(i,k){
    if(dis.root(c[i]) == p) continue;
    cout << -1 << endl;
    return 0;
  }

  init();
  rep(i,k){
    queue<int> q;
    q.push(c[i]);
    d[i][c[i]] = 0;
    while(!q.empty()){
      int u = q.front(); q.pop();
      for(int v: to[u]){
        if(d[i][v] == LINF){
          d[i][v] = d[i][u]+1;
          q.push(v);
        }
      }
    }
  }

  ll ans = LINF;
  
  rep(i,k){
    ll dp[1<<k][k];
    rep(b,1<<k) rep(j,k) dp[b][j] = LINF;
    // rep(j,k) dp[0][j] = 0;
    dp[1<<i][i] = 0;
    rep(b,1<<k){
      rep(j,k){
        if(b>>j&1) continue;
        rep(l,k){
          if(!(b>>l&1)) continue;
          int nb = (b|(1<<j));
          if(dp[nb][j]>dp[b][l]+d[l][c[j]]){
            dp[nb][j] = dp[b][l]+d[l][c[j]];
          }
        }
      }
    }
    // cout << dp[(1<<k)-1][i] << endl;
    rep(j,k) ans = min(dp[(1<<k)-1][j],ans);
    // if(i == 0) cout << dp[(1<<k)-1][1] << endl;
  }
  ans++;
  cout << ans << endl;
  return 0;
}