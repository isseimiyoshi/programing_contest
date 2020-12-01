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

const int MAX_KE = 45;

int main() {
  int n; ll K; cin >> n >> K;
  vl a(n);
  rep(i,n) cin >> a[i];

  

  ll dp[MAX_KE+1][2];
  rep(i,MAX_KE+1) rep(j,2) dp[i][j] = 0;

  for(int i=MAX_KE-1; i>=0; i--){
    vl sum(2,0);
    rep(k,n){
      if(a[k]&(1<<i)) sum[1] += (1<<i);
      else sum[0] += (1<<i);
    }
    if((1<<i)>K){
      dp[i][0] = max(dp[i][0], dp[i+1][0]+sum[1]);
      continue;
    }
    if(K&(1<<i)){
      dp[i][1] = max(dp[i][1], dp[i+1][0]+sum[1]);
      dp[i][0] = max(dp[i][0], dp[i+1][0]+sum[0]);
    }else{
      dp[i][0] = max(dp[i][0], dp[i+1][0]+sum[1]);
    }
  }

  rep(i,40){
    rep(k,2){
      cout << dp[i][k] << " ";
    }cout << endl;
  }

  ll ans = 0;
  rep(k,2){
    ans = max(ans, dp[1][k]);
  }
  cout << ans << endl;
  return 0;
}
