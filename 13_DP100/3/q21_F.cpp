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

const ll w[3] = {2,3,5};
const int di2[6] = {0,1,0,2,0,1};
const int di3[6] = {0,0,1,0,0,1};
const int di5[6] = {0,0,0,0,1,0};

int main() {
  int n; ll d;
  cin >> n >> d;
  set<ll> s;
  map<ll,ll> m;
  for(int wi: w){
    while(d%wi == 0){
      d /= wi;
      if(s.count(wi)) m[wi]++;
      else { s.insert(wi); m[wi] = 1;}
    }
  }

  if(d != 1){
    double ans = 0.0;
    printf("%.f6\n",ans);
    return 0;
  }

  int a, b, c;
  a = (s.count(2) ? m[2] : 0);
  b = (s.count(3) ? m[3] : 0);
  c = (s.count(5) ? m[5] : 0);
  double dp[a+1][b+1][c+1];
  rep(i,a+1) rep(j,b+1) rep(k,c+1) dp[i][j][k] = 0.0;
  dp[0][0][0] = 1.0;
  rep(lp,n){
    rep(i,a+1){
      rep(j,b+1){
        rep(k,c+1){
          rep(l,6){
            if(i-di2[l]<0 || j-di3[l]<0 || k-di5[l]<0) continue;
            if(l == 0) continue;
            dp[i][j][k] += dp[i-di2[l]][j-di3[l]][k-di5[l]]*(1.0/6.0);
          }
        }
      }
    }
  }
  cout << dp[a][b][c] << endl;
  return 0;
}
