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
  int h,w; ll k,v; cin >> h >> w >> k >> v;
  ll a[h][w];
  rep(i,h) rep(j,w) cin >> a[i][j];

  ll rui[h][w]; rui[0][0] = a[0][0];
  for(int i=1; i<h; i++) rui[i][0] = rui[i-1][0]+a[i][0];
  for(int j=1; j<w; j++) rui[0][j] = rui[0][j-1]+a[0][j];

  for(int i=1; i<h; i++){
    for(int j=1; j<w; j++){
      rui[i][j] = rui[i-1][j]+rui[i][j-1]-rui[i-1][j-1]+a[i][j];
    }
  }
  ll ans = 0;
  rep(i2,h) rep(j2,w){
    for(int i=0;i<=i2; i++){
      for(int j=0; j<=j2; j++){
        ll res = 0; ll men = 0;
        if(i == 0 && j == 0){
          men = (i2+1)*(j2+1);
          res += men*k;
          res += rui[i2][j2];
        }else if(i == 0){
          men = (j2-j+1)*(i2+1);
          res += men*k;
          res += rui[i2][j2]-rui[i2][j-1];
        }else if(j == 0){
          men = (j2+1)*(i2-i+1);
          res += men*k;
          res += rui[i2][j2]-rui[i-1][j2];
        }else{
          men = (j2-j+1)*(i2-i+1);
          res += men*k;
          res += rui[i2][j2]-rui[i2][j-1]-rui[i-1][j2]+rui[i-1][j-1];
        }
        if(res<=v) ans = max(ans,men);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
