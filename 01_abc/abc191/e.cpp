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

const int MAX_N = 2020;

vp to[MAX_N];
int d[MAX_N][MAX_N];

void init(){
  rep(i,MAX_N){
    rep(j,MAX_N){
      d[i][j] = INF;
    }
  }
}

void dijkstra(int s){
  d[s][s] = 0;
  priority_queue<P> pq;
  pq.push(P(0,s));
  while(!pq.empty()){
    int u = pq.top().second, ud = -pq.top().first;
    pq.pop();
    for(auto vp: to[u]){
      int v = vp.first, vd = vp.second;
      if(d[s][v]>ud+vd){
        d[s][v] = ud+vd;
        pq.push(P(-d[s][v],v));
      }
    }
  }
}

int main() {
  int n,m; cin >> n >> m;
  vi ziko(n,INF);
  rep(i,m){
    int a,b,c; cin >> a >> b >> c;
    --a,--b;
    if(a == b){
      ziko[a] = min(ziko[a],c);
      continue;
    }
    to[a].push_back(make_pair(b,c));
  }

  init();
  rep(i,n){
    if((int)to[i].size() == 0) continue;
    sort(rng(to[i]));
  }

  rep(i,n){
    dijkstra(i);
  }

  vi ans(n,INF);
  rep(i,n){
    rep(j,n){
      if(i == j) continue;
      if(d[i][j] == INF) continue;
      auto itr = upper_bound(rng(to[j]),P(i,0));
      if(itr == to[j].end()) continue;
      P p = (*itr);
      if(p.first == i){
        ans[i] = min(ans[i],d[i][j]+p.second);
      }
    }
    ans[i] = min(ans[i], ziko[i]);
  }

  rep(i,n){
    if(ans[i] == INF) cout << -1 << endl;
    else cout << ans[i] << endl;
  }
  /*
  rep(i,n){
    rep(j,n){
      cout << d[i][j] << " ";
    }cout << endl;
  }
  */

  return 0;
}
