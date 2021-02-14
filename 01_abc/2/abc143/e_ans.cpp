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


int main() {
  ll n,m,l; cin >> n >> m >> l;
  ll dist[n][n];
  rep(i,n) rep(j,n) dist[i][j] = LINF;
  rep(i,n) dist[i][i] = 0;
  rep(i,m){
    int a,b; ll c; cin >> a >> b >> c; --a,--b;
    dist[a][b] = dist[b][a] = c;
  } 
  // ワーシャルフロイド法を適用し、全点対最短経路を求める
  rep(k,n){
    rep(i,n){
      if(dist[i][k] == LINF) continue;
      rep(j,n){
        if(dist[j][k] == LINF) continue;
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
      }
    }
  }

  // 求められた最短経路から、燃料の補給なしに点間の移動ができる点間に辺を張っていく
  ll d[n][n];
  rep(i,n) rep(j,n) d[i][j] = LINF;
  rep(i,n) d[i][i] = 0;
  rep(i,n){
    rep(j,n){
      if(dist[i][j]<=l){
        d[i][j] = d[j][i] = 1;
      }
    }
  }

  rep(k,n){
    rep(i,n){
      if(d[i][k] == LINF) continue;
      rep(j,n){
        if(d[j][k] == LINF) continue;
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }

  int q; cin >> q;
  vl ans;
  rep(_,q){
    int s,t; cin >> s>>t; --s,--t;
    if(d[s][t] == LINF) ans.push_back(-1);
    else ans.push_back(d[s][t]-1);
  }
  for(auto res: ans) cout << res << endl;
  return 0;
}