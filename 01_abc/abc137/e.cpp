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

const int MAX_N = 5050;

int n,p;
vp to[MAX_N];
ll dp[MAX_N];

bool isok = true;
const ll No = -LINF+100000;

void init(){
  rep(i,MAX_N){
    dp[i] = -LINF;
  }
}

// roop：自己ループしてたらtrueとしてもらうDPを続け、
// 頂点0に到達した場合スコアの最大値は存在しなくなる
ll f(int u){
  // if(dp[u] != -LINF) return dp[u];
  if(u == 0) return dp[0];
  if(dp[u] == No || dp[u] != -LINF) return No;

  ll ans = -LINF;
  int cnt = 0;
  int i = 0;
  for(auto pi: to[u]){
    int v = pi.first, c = pi.second;
    // 自己ループの場合、この頂点を絶対に通れない
    if(u == v){
      return dp[u] = No;
    }
    ll res = f(v);
    if(res == No) cnt++;
    i++;
    ans = max(ans, res+(ll)c);
  }
  if(cnt == i) return dp[u] = No;
  return dp[u] = ans;
}

int main() {
  int m; cin >> n >> m >> p;

  init();
  dp[0] = 0;

  rep(i,m){
    int a,b,c; cin >> a >> b >> c;
    --a,--b;
    to[b].push_back(P(a,c-p));
  }

  f(n-1);

  if(dp[n-1] == No) cout << -1 << endl;
  else cout << max((ll)0,dp[n-1]) << endl;

  return 0;
}
