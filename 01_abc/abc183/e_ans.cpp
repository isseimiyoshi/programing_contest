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
  int h,w; cin >> h >> w;
  int s[h][w];
  rep(i,h) rep(j,w){
    char moji; cin >> moji;
    if(moji == '#') s[i][j] = 1;
    else s[i][j] = 0;
  }

  int dp[h][w];
  int dpx[h][w];
  int dpy[h][w];
  int dpxy[h][w];
  rep(i,h) rep(j,w) dp[i][j] = dpx[i][j] = dpy[i][j] = dpxy[i][j] = 0;
  dp[0][0] = dpx[0][0] = dpy[0][0] = dpxy[0][0] = 1;

  rep(i,h){
    rep(j,w){
      if(s[i][j] == 1) continue;
      if(i == 0 && j == 0) continue;
      dp[i][j] = (i-1 >= 0 ? dpy[i-1][j]:0) + (j-1 >= 0 ? dpx[i][j-1]:0) + (i-1 >= 0 && j-1 >=0 ? dpxy[i-1][j-1]:0);
      if(i-1>=0) dpy[i][j] = dpy[i-1][j] + dp[i][j];
      if(j-1>=0) dpx[i][j] = dpx[i][j-1] + dp[i][j];
      if(i-1>=0 && j-1>=0) dpxy[i][j] = dpxy[i-1][j-1]+dp[i][j];
    }
  }

  cout << "dpx" << endl;
  rep(i,h){
    rep(j,w){
      cout << dpx[i][j] << " ";
    }cout << endl;
  }cout << endl;

  cout << "dpy" << endl;
  rep(i,h){
    rep(j,w){
      cout << dpy[i][j] << " ";
    }cout << endl;
  }cout << endl;

  cout << "dpxy" << endl;
  rep(i,h){
    rep(j,w){
      cout << dpxy[i][j] << " ";
    }cout << endl;
  }cout << endl;

  rep(i,h){
    rep(j,w){
      cout << dp[i][j] << " ";
    }cout << endl;
  }

  cout << dp[h-1][w-1] << endl;

  return 0;
}
