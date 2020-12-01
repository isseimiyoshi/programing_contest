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

const int DEV = 13000;

int main() {
  int h, w; cin >> h >> w;
  int a[h][w], b[h][w];
  rep(i,h) rep(j,w) cin >> a[i][j];
  rep(i,h) rep(j,w) cin >> b[i][j];

  int c[h][w];
  rep(i,h) rep(j,w) c[i][j] = abs(a[i][j]-b[i][j]);

  /*
  rep(i,h){
    rep(j,w){
      cout << c[i][j] << " ";
    }cout << endl;
  }
  */
  bool dp[h][w][DEV*2];
  rep(i,h) rep(j,w) rep(k,DEV*2) dp[i][j][k] = false;
  dp[0][0][c[0][0]+DEV] = true;
  dp[0][0][-c[0][0]+DEV] = true;
  rep(i,h){
    rep(j,w){
      if(i == 0 && j == 0) continue;
      rep(k,DEV*2){
        if(i-1>=0) if(k-c[i][j]<2*DEV && k-c[i][j]>=0) if(dp[i-1][j][k-c[i][j]]) dp[i][j][k] = true;
        if(i-1>=0) if(k+c[i][j]<2*DEV && k+c[i][j]>=0) if(dp[i-1][j][k+c[i][j]]) dp[i][j][k] = true;
      
      
        if(j-1>=0) if(k-c[i][j]<2*DEV && k-c[i][j]>=0) if(dp[i][j-1][k-c[i][j]]) dp[i][j][k] = true;
        if(j-1>=0) if(k+c[i][j]<2*DEV && k+c[i][j]>=0) if(dp[i][j-1][k+c[i][j]]) dp[i][j][k] = true;
      
      }
    }
  }
  int ans = INF;
  rep(k,DEV*2){ 
    if(dp[h-1][w-1][k]) ans = min(ans,abs(k-DEV));
  }
  cout << ans << endl;
  return 0;
}
