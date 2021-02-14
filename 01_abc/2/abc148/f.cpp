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

vi to[MAX_N];

int main() {
  int n,U,V; cin >> n >> U >> V; --U,--V;
  rep(i,n-1){
    int a,b; cin >> a >> b; --a,--b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vi du(n,INF);
  vi dv(n,INF);
  du[U] = 0;
  dv[V] = 0;
  queue<int> qu,qv;
  qu.push(U);
  qv.push(V);

  while(!qu.empty()){
    int u = qu.front(); qu.pop();
    for(int v: to[u]){
      if(du[v] == INF){
        du[v] = du[u]+1;
        qu.push(v);
      }
    }
  }
  while(!qv.empty()){
    int u = qv.front(); qv.pop();
    for(int v: to[u]){
      if(dv[v] == INF){
        dv[v] = dv[u]+1;
        qv.push(v);
      }
    }
  }
  int ans = 0;
  rep(i,n){
    if(du[i]<dv[i]){
      ans = max(ans, dv[i]-1);
    }
  }
  cout << ans << endl;
  /*
  rep(i,n) cout << du[i] << " ";
  cout << endl;
  rep(i,n) cout << dv[i] << " ";
  cout << endl;
  */
  return 0;
}
