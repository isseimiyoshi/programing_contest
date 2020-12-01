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

const int MAX_A = 3050;

int main() {
  int n, t; cin >> n >> t;
  vp ab(n);
  rep(i,n){
    int ai,bi; cin >> ai >> bi;
    ab[i] = make_pair(ai,bi);
  }
  sort(rng(ab));

  int dp[n+1][t+MAX_A];
  rep(i,n+1) rep(j,t+MAX_A) dp[i][j] = 0;
  rep(i,n){
    rep(j,t+MAX_A){
      int a = ab[i].first;
      int b = ab[i].second;
      if(j<a) dp[i+1][j] = dp[i][j];
      else if(j-a>=t) dp[i+1][j] = dp[i][j];
      else{
        dp[i+1][j] = max(dp[i][j], dp[i][j-a]+b);
      }
    }
  }
  int res = 0;
  rep(j,t+MAX_A){
    res = max(res, dp[n][j]);
  }
  cout << res << endl;
  return 0;
}
