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
#include <atcoder/all>
using namespace atcoder;
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
  int n; cin >> n;
  vp edge(n-1);
  rep(i,n-1){
    int a,b; cin >> a >> b; --a,--b;
    edge[i] = make_pair(a,b);
  }
  // 
  vi to[n];
  rep(i,n-1){
    int a = edge[i].first, b = edge[i].second;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  // 頂点0を根としたときの各頂点の深さを求める
  queue<int> q;
  vi d(n,-1);
  d[0] = 0;
  q.push(0);
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v: to[u]){
      if(d[v]>=0) continue;
      d[v] = d[u]+1;
      q.push(v);
    }
  }
  // cout << endl;
  // rep(i,n) cout << d[i] << endl;
  // クエリを読み取り、各頂点に値を足す（または引く）処理を行っていく
  vl res(n,0);
  int Q; cin >> Q;
  rep(_,Q){
    int t,e; ll x;
    cin >> t >> e >> x; --e;
    int a = edge[e].first, b = edge[e].second;
    if(t == 1){
      if(d[a]>d[b]){
        res[a] += x;
      }else{
        res[0] += x;
        res[b] -= x;
      }
    }else{
      if(d[a]>d[b]){
        res[0] += x;
        res[a] -= x;
      }else{
        res[b] += x;
      }
    }
  }
  // いもす法の要領で各頂点に足されている数値を足し合わせていく
  queue<int> q2;
  q2.push(0);
  while(!q2.empty()){
    int u = q2.front();
    q2.pop();
    for(int v: to[u]){
      if(d[v]>d[u]){
        q2.push(v);
        res[v] += res[u];
      }
    }
  }
  rep(i,n) cout << res[i] << endl;
  return 0;
}