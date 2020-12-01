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

const int MAX_N = 155, MAX_M = 80, MAX_K = 11;

int main() {
  int n, m; cin >> n >> m;
  vi k(n);
  vector<vector<pair<ll,ll>> > st(n);
  rep(i,n){
    cin >> k[i];
    rep(j,k[i]){
      int x,d; cin >> x >> d;
      st[i].push_back(make_pair(x,d));
    }
  }
  ll dp[MAX_N][MAX_K][MAX_M];
  rep(i,MAX_N) rep(j,MAX_K) rep(l,MAX_M) dp[i][j][l] = LINF;
  rep(j,MAX_K) rep(l,m+1) dp[0][j][l] = 0;
  rep(j,k[0]) dp[1][j][0] = 0;
  rep(j,k[1]) dp[2][j][1] = 0;

  auto calc = [&](int i, int j, int i2, int j2){
    return (st[i][j].second + st[i2][j2].second)*abs(st[i][j].first - st[i2][j2].first);
  };

  rep(i,n){
    if(i == 0) continue;
    rep(j,k[i]){
      rep(j2,k[i-1]){
        rep(l,m+1){
          if(l == 0){
            dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][0]+calc(i,j,i-1,j2));
          }else{
            dp[i+1][j][l] = min(dp[i+1][j][l], dp[i][j][l]+calc(i,j,i-1,j2));
          }
        }
      }
      // 1行飛ばしを行う場合の処理
      if(i == 1) continue;
      rep(j3,k[i-2]){
        rep(l,m+1){
          if(l == 0) continue;
          dp[i+1][j][l] = min(dp[i+1][j][l], dp[i-1][j][l-1]+calc(i,j,i-2,j3));
        } 
      }
    }
  } 
  ll ans = LINF;
  /*
  rep(j,k[n-1]){
    rep(l,m+1){
      ans = min(ans, dp[n][j][l]);
      cout << dp[n][j][l] << " ";
    }cout << endl;
  }
  rep(j,k[n-2]){
    rep(l,m){
      ans = min(ans, dp[n][j][l]);
      cout << dp[n][j][l] << " ";
    }cout << endl;
  }
  */
  rep(j,k[n-1]) rep(l,m+1) ans = min(ans, dp[n][j][l]);
  rep(j,k[n-2]) rep(l,m) ans = min(ans, dp[n-1][j][l]);
  cout << ans << endl;
  return 0;
}
