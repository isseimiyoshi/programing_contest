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

// dp[i][j][k] := s[i]文字目までみて、'('がj文字で最後に文字を反転したのが、
// s[k]文字目の時のコストの最小値
int dp[110][55][110];

int main() {
  rep(i,110) rep(j,55) rep(k,110) dp[i][j][k] = INF;

  string s; cin >> s;
  int n = s.size();

  // sの先頭の文字を先にみて、初期値を決定しておく
  if(s[0] == '(') dp[0][1][0] = 0;
  else dp[0][1][0] = 1;

  rep(i,n-1) for(int j=0; j<=n/2; j++) rep(k,n){
    if(dp[i][j][k] == INF) continue;
    if(s[i+1] == '('){
      // 変更
      if(i+1 > j*2) continue; // 
      dp[i+1][j][i+1] = min(dp[i][j][k]+i+1-k+1, dp[i+1][j][i+1]); // コスト：（カーソル移動分）＋（変更分）
      // そのまま
      if(i+1 > (j+1)*2) continue;
      dp[i+1][j+1][k] = min(dp[i+1][j+1][k], dp[i][j][k]);
    }else{
      // そのまま
      if(i+1>j*2) continue;
      dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
      // 変更
      if(i+1>(j+1)*2) continue;
      dp[i+1][j+1][i+1] = min(dp[i+1][j+1][i+1], dp[i][j][k]+i+1-k+1);
    }
  }
  int ans = INF;
  rep(i,n){
    ans = min(ans, dp[n-1][n/2][i]);
  }
  cout << ans << endl;
  return 0;
}
