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

const double dINF = 1000100100.0;

int main() {
  int n, m; cin >> n >> m;
  vector<tuple<double,double,double> > cn(n);
  vector<pair<double,double> > cm(m);
  rep(i,n){
    double x,y; double r; cin >> x >> y >> r;
    cn[i] = make_tuple(x,y,r);
  }
  rep(i,m){
    int x,y; cin >> x >> y;
    cm[i] = make_pair(x,y);
  }
  vector<double> cmr(m,dINF);
  rep(i,m){
    double minr = dINF;
    double xi,yi;
    xi = cm[i].first;
    yi = cm[i].second;
    rep(j,n){
      double xj,yj,rj;
      tie(xj,yj,rj) = cn[j];
      double now = sqrt((xi-xj)*(xi-xj)+(yi-yj)*(yi-yj))-rj;
      minr = min(minr,now);
    }
    rep(j,m){
      if(i == j) continue;
      double xj,yj;
      xj = cm[j].first;
      yj = cm[j].second;
      double now = sqrt((xi-xj)*(xi-xj)+(yi-yj)*(yi-yj));
      now /= 2.0;
      minr = min(minr,now);
    }
    cmr[i]=  minr;
  }
  double ans = dINF;
  rep(i,m) ans = min(ans,cmr[i]);
  rep(i,n) {
    double x,y,r; tie(x,y,r) = cn[i];
    ans = min(ans,r);
  }
  printf("%.6f\n", ans);
  return 0;
}
