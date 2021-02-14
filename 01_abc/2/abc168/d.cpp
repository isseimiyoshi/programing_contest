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


int main() {
  int n,m; cin >> n >> m;
  vi to[n];
  rep(i,m){
    int a,b; cin >> a >> b;
    --a,--b;
    to[a].push_back(b);
    to[b].push_back(a);
  }

  int d[n];
  rep(i,n) d[i] = INF;
  vi p(n,-1);

  d[0] = 0;
  queue<int> q;
  q.push(0);

  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v: to[u]){
      if(d[v] == INF || d[v]>d[u]+1){
        d[v] = d[u]+1;
        q.push(v);
        p[v] = u;
      }
    }
  }
  bool ok = true;
  rep(i,n) if(d[i] == INF) ok = false;
  if(ok){
    cout << "Yes" << endl;
    rep(i,n){
      if(i == 0) continue;
      cout << p[i]+1 << endl;
    }
  }else{
    cout << "No" << endl;
  }
  return 0;
}
