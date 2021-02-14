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
  string s; cin >> s;
  int n = s.size();
  int k; cin >> k;

  int dp[n+1][2][k+1];
  rep(i,n+1) rep(j,2) rep(l,k+1) dp[i][j][l] = 0;
  dp[0][0][0] = 1;

  rep(i,n) rep(l,k+1){
    int si = s[i]-'0';
    rep(d,10){
      if(d != 0 && l == k) continue;
      if(d == 0) dp[i+1][1][l] += dp[i][1][l];
      else dp[i+1][1][l+1] += dp[i][1][l];
    }
    rep(d,si){
      if(d != 0 && l == k) continue;
      if(d == 0) dp[i+1][1][l] += dp[i][0][l];
      else dp[i+1][1][l+1] += dp[i][0][l];
    }
    if(si == 0) dp[i+1][0][l] += dp[i][0][l];
    else{
      if(l == k) continue;
      dp[i+1][0][l+1] += dp[i][0][l];
    }
  }

  int ans = 0;
  rep(j,2) {
    ans += dp[n][j][k];
  }
  cout << ans << endl;
  return 0;
}
