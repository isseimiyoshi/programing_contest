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

const int MAX_N = 100010;

vector<tuple<int,ll,ll>> to[MAX_N];

int main() {
  int n,m; cin >> n >> m;
  int s,g; cin >> s >> g; --s, --g;
  rep(i,m){
    int ai,bi; ll ti,ki; cin >> ai >> bi >> ti >> ki;--ai,--bi;
    to[ai].push_back(make_tuple(bi,ti,ki));
    to[bi].push_back(make_tuple(ai,ti,ki));
  }
  vl dist(n,LINF);

  dist[s] = 0;
  priority_queue<pair<ll,int>> pq;
  pq.push(make_pair(0,s));
  while(!pq.empty()){
    int u = pq.top().second;
    ll ud = -pq.top().first;
    pq.pop();
    for(auto tuplev: to[u]){
      int v; ll tv,kv;
      tie(v,tv,kv) = tuplev;
      ll wait = 0;
      if(ud%kv != 0){
        wait = kv - ud % kv;
      }
      if(dist[v]>ud+wait+tv){
        dist[v] = ud+wait+tv;
        pq.push(make_pair(-dist[v],v));
      }
    }
  }
  ll ans = dist[g];
  if(ans == LINF) cout << -1 << endl;
  else cout << ans << endl;
  return 0;
}
