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
  int n; cin >> n;
  vl a(n);
  rep(i,n) cin >> a[i];

  ll ans;
  if(n%2 == 0){
    ll ans1 = 0;
    ll ans2 = 0;
    rep(i,n){
      if(i%2 == 0) ans2 += a[i];
      else ans1 += a[i];
    }
    ans = max(ans1, ans2);
  }else{
    ll dp[n][n/2+1][2];
    rep(i,n) rep(j,n/2+1) rep(k,2) dp[i][j][k] = -LINF;
    dp[0][0][0] = 0;
    dp[0][1][1] = a[0];
    dp[1][0][0] = 0;
    dp[1][1][0] = a[0];
    dp[1][1][1] = a[1];

    rep(i,n){
      if(i == 0 || i == 1) continue;
      int mi = i/2;
      int ma = min(n/2, (i+2)/2);
      for(int j=mi; j<=ma; j++){
        dp[i][j][1] = dp[i-1][j-1][0]+a[i];
        dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]);
      }
    }
    ans = max(dp[n-1][n/2][0], dp[n-1][n/2][1]);
  }
  cout << ans << endl;
  return 0;
}
