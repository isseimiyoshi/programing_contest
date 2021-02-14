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
  ll n,k; cin >> n >> k;
  vl h(n+1);
  h[0] = 0;
  rep(i,n){
    cin >> h[i+1];
  }
  if(n<=k){
    cout << 0 << endl;
    return 0;
  }
  ll m = n-k;
  ll dp[n+1][m+1];
  rep(i,n+1) rep(j,m+1) dp[i][j] = LINF;
  dp[0][0] = 0;
  rep(i,n){
    for(int j=1; j<=m; j++){
      rep(l,i+1){
        dp[i+1][j] = min(dp[i+1][j], dp[l][j-1]+max((ll)0,h[i+1]-h[l]));
      }
    }
  }
  ll ans = LINF;
  rep(i,n+1){
    ans = min(ans, dp[i][m]);
  }
  cout << ans << endl;
  return 0;
}