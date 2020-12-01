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

const int MAX_N = 101;

int main() {
  int a,b,c; cin >> a >> b >> c;
  double dp[MAX_N][MAX_N][MAX_N];
  rep(i,101) rep(j,101) rep(k,101) dp[i][j][k] = 0.0;
  dp[100][100][100] = 0;
  dp[100][100][99] = dp[100][99][100] = dp[99][100][100] = 99.0/299.0;
  dp[99][99][99] = 1.0;
  for(int i=99; i>=0; i--){
    for(int j=99; j>=0; j--){
      for(int k=99; k>=0; k--){
        if(i == 99 && j == 99 && k == 99) continue;
        double probi = (double)i / ((double)i + (double)j + (double)k);
        double probj = (double)j / ((double)i + (double)j + (double)k);
        double probk = (double)k / ((double)i + (double)j + (double)k);
        dp[i][j][k] += (dp[i+1][j][k]+1.0)*probi;
        dp[i][j][k] += (dp[i][j+1][k]+1.0)*probj;
        dp[i][j][k] += (dp[i][j][k+1]+1.0)*probk;
      }
    }
  }
  /*
  rep(i,101){
    cout << dp[i][50][50] << " ";
  }cout << endl;
  */
  printf("%.6f\n", dp[a][b][c]);
  return 0;
}
