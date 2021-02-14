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

  int dp[n][n/2+1][n];
  rep(i,n) rep(j,n/2+1) rep(k,n) dp[i][j][k] = INF;

  // 文字列の先頭をみて初期値が定めやすい場合は、先に初期値を定めて文字列の１文字目を除いてDPするのが楽
  if(s[0] == '(') dp[0][1][0] = 0;
  else dp[0][1][0] = 1;

  rep(i,n) rep(j,n/2+1) rep(k,n){
    if(i == 0) continue;
    if(dp[i-1][j][k] == INF) continue;  // もらうDPのため、もらうものがINFであれば飛ばす
    if(s[i] == '('){
      if(j != n/2) dp[i][j+1][k] = min(dp[i][j+1][k], dp[i-1][j][k]);
      if(j != 0) dp[i][j-1][i] = min(dp[i][j-1][i], dp[i-1][j][k]+i-k+1);
    }else{
      if(j != n/2) dp[i][j+1][i] = min(dp[i][j+1][i], dp[i-1][j][k]+i-k+1);
      if(j != 0) dp[i][j-1][k] = min(dp[i][j-1][k], dp[i-1][j][k]);
    }
    /*
    if(s[i] == '('){
      dp[i+1][j+1][k] = min(dp[i+1][j+1][k], dp[i][j][k]);
      if(j>0) dp[i+1][j-1][i+1] = min(dp[i+1][j-1][i+1], dp[i][j][k]+1);
    }else{
      dp[i+1][j+1][i+1] = min(dp[i+1][j+1][i+1], dp[i][j][k]);
      if(j>0) dp[i+1][j-1][k] = min(dp[i+1][j-1][k], dp[i][j][k]+1);
    }
    */
  }
  int ans = INF;
  rep(i,n){
    ans = min(ans, dp[n-1][0][i]);
    // cout << dp[n][0][i] << endl;
  }
  cout << ans << endl;
  return 0;
}
