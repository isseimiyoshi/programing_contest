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
void chmin(int &a, int b){ a = min(a,b); }

int main() {
  int n,m; cin >> n >> m;
  // 各頂点に隣接している頂点を集合で持つ
  vi g(n);
  while(m--){
    int a,b; cin >> a >> b;
    a--,b--;
    g[a] |= 1<<b;
    g[b] |= 1<<a;
  }
  // 各頂点集合に対して、最小でいくつのクリークで構成可能か格納する
  vi dp(1<<n, INF);
  dp[0] = 1;

  rep(i,n) rep(j,1<<n){
    // 頂点集合jがクリーク　かつ　頂点iから頂点集合jのすべての頂点に対して辺がはられている場合、頂点集合jに頂点iを含めたものもクリークとなる
    if(dp[j] == 1 && (g[i]&j) == j) dp[j | 1<<i] = 1;
  }
  // 頂点集合iを頂点集合jと頂点集合i^(XOR)jに二分して、頂点集合iを構成するクリークの最小数を求めている
  for(int i=1; i<(1<<n); i++) for(int j=i; --j &=i; ){
    chmin(dp[i], dp[i^j]+dp[j]);
  }
  cout << dp.back() << endl;
  return 0;
}