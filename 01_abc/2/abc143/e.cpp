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

const int MAX_N = 305;

int n; ll l;
vector<pair<int,ll> > to[MAX_N];

int p[MAX_N][MAX_N];
ll d[MAX_N][MAX_N];

void init(){
  rep(i,MAX_N){
    rep(j,MAX_N){
      p[i][j] = INF;
      d[i][j] = LINF;
    }
  }
}

void dijkstra(int s){
  d[s][s] = 0;
  p[s][s] = -1;

  priority_queue<pair<ll,int>> pq;
  pq.push(make_pair(0,s));
  while(!pq.empty()){
    int u = pq.top().second; ll uc = -pq.top().first;
    pq.pop();
    for(auto pairv: to[u]){
      int v = pairv.first; ll vc = pairv.second;
      if(d[s][v] == LINF && d[s][v]>uc+vc){
        d[s][v] = uc+vc;
        p[s][v] = u;
        pq.push(make_pair(-d[s][v],v));
      }
    }
  }

}

int main() {
  int m; cin >> n >> m >> l;
  rep(i,m){
    int a,b; ll c; cin >> a >> b >> c; --a,--b;
    to[a].push_back(make_pair(b,c));
    to[b].push_back(make_pair(a,c));
  }
  init();
  rep(i,n) dijkstra(i);

  rep(i,n){
    sort(rng(to[i]));
  }

  int q; cin >> q;
  vi res;
  rep(_,q){
    int s,t; cin >> s >> t; --s,--t;
    if(m == 0){
      int ans = (s == t ? 0 : -1);
      res.push_back(ans);
      continue;
    }

    int ans = 0;
    int now = t;
    ll fuel = l;
    while(true){
      // printf("%d %d %d\n", s, t, now);
      if(now == s) break;
      auto itr = upper_bound(rng(to[now]),make_pair(p[s][now],(ll)-1));
      ll dist = (*itr).second;
      if(dist>l){
        ans = -1;
        break;
      }
      if(fuel>=dist){
        fuel -= dist;
        now = p[s][now];
      }else{
        ans++;
        fuel = l-dist;
        now = p[s][now];
      }
    }
    res.push_back(ans);
  }

  for(int ans: res) cout << ans << endl;
  /*
  rep(i,n){
    rep(j,n){
      cout << d[i][j] << " ";
    }cout << endl;
  }
  */
  return 0;
}
