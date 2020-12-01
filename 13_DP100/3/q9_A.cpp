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

const char m[4] = {'A', 'B', 'X', 'Y'};

int main() {
  int n; cin >> n;
  string c; cin >> c;
  int ans = INF;
  int dp[n+1];
  rep(i,4) rep(j,4){
    rep(i2,4) rep(j2,4){
      rep(k,n+1) dp[k] = INF;
      string L = ""; L += m[i], L += m[j];
      string R = ""; R += m[i2], R += m[j2];
      // cout << L << " " << R << " ";
      dp[0] = 0;
      rep(k,n){
        if(k == 0) {dp[k+1] = 1; continue;}
        else{
          string ci = ""; ci += c[k-1], ci += c[k];
          if(ci == L || ci == R) dp[k+1] = min(dp[k-1]+1, dp[k+1]);
          else dp[k+1] = min(dp[k]+1, dp[k+1]);
        }
      }
      // cout << dp[n] << endl;
      ans = min(ans, dp[n]);
    }
  }
  cout << ans << endl;
  return 0;
}
