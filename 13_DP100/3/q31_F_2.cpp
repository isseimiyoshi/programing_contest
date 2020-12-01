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

int n,m;
int k[160];

int dp[160][16][80];

int main() {
  cin >> n >> m;
  vp s[160];
  rep(i,n){
    cin >> k[i];
    rep(j,k[i]){
      int d,x; cin >> x >> d;
      s[i].push_back(P(x,d));
    }
  }

  rep(i,160) rep(j,16) rep(l,80) dp[i][j][l] = INF;

  // 3次元目は、1行飛ばしをすることのできる残り回数で表現している
  rep(j,k[0]) dp[0][j][m] = 0;  // スタート地点の岸から1行目の石へはコストゼロで飛び乗ることができる
  if(m) rep(j,k[1]) dp[1][j][m-1] = 0;  // スタート地点の岸から2行目の石へはコストゼロで一段跳びを一回行うことで飛び乗ることができる

  rep(i,n-1){
    rep(j,k[i]){
      rep(l,m+1){
        if(i == n-2 && l>0) continue;
        // 飛び乗る先の石を後ろのループにしている
        rep(t,k[i+1]){
          int cost = (s[i][j].second + s[i + 1][t].second) * abs(s[i][j].first - s[i + 1][t].first);
          dp[i+1][t][l] = min(dp[i+1][t][l], dp[i][j][l] + cost);
        }

        if(l>0){
          rep(t,k[i+2]){
            int cost = (s[i][j].second + s[i + 2][t].second) * abs(s[i][j].first - s[i + 2][t].first);
            dp[i+2][t][l-1] = min(dp[i+2][t][l-1], dp[i][j][l]+cost);
          }
        }
      }
    }
  }
  int ans = INF;
  rep(j,k[n-1]) rep(l,m+1) ans = min(ans, dp[n-1][j][l]);
  rep(j,k[n-2]) for(int l=1; l<=m; l++) ans = min(ans, dp[n-2][j][l]);
  cout << ans << endl;
  return 0;
}
