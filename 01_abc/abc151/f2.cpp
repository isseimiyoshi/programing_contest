#include <bits/stdc++.h>
#define fi first
#define se second
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
#define v(T) vector<T>
#define vv(T) v(v(T))
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
int getInt(){int x;scanf("%d",&x);return x;}
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

int n;
struct _P {
  double x, y;
};
vector<_P> p;

// 2点間の距離を求める関数
double dist(_P a, _P b){
  double dx = a.x-b.x;
  double dy = a.y-b.y;
  return sqrt(dx*dx + dy*dy);
}

// 中心点を決めたときの最遠点までの距離、全部の点について、xyからpiまでの距離
double f(double x, double y){
  double res = 0;
  rep(i,n){
    // それぞれの点までの距離のMAXが中心を決めたときの最小の半径
    res = max(res, dist((_P){x,y}, p[i]));
  }
  return res;
} // この関数を最小化するような x,y を求めたい

// x座標を決め打ったときのyを好きに選んでいいときのfの最小値
// なので、もう一度三分探索
double g(double x){
  double l = 0, r = 1000;
  rep(i,80){
    double c1 = (l*2+r)/3;
    double c2 = (l+r*2)/3;
    if(f(x,c1) > f(x,c2)) l = c1; else r = c2;
  }
  return f(x,l);
}


int main() {
  cin >> n;
  p = vector<_P>(n);
  rep(i,n) cin >> p[i].x >> p[i].y;

  double l = 0, r = 1000;
  // まずx座標を三分探索
  rep(i,80){
    double c1 = (l*2+r)/3;
    double c2 = (l+r*2)/3;
    // 最小値を求めたいから大きい方を近づけていく
    if(g(c1) > g(c2)) l = c1; else r = c2;
  }

  double ans = g(l);
  printf("%.10f\n", ans);
  return 0;
}
