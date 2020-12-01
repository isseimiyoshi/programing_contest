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

// Mod int
const int mod = 100000;
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  // mint(ll x):x(x){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint operator-() const { return mint(0) - *this;}
  mint operator~() const { return mint(1) / *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint& operator/=(const mint& a){ (x*=a.pow(mod-2).x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  mint operator/(const mint& a)const{ return mint(*this) /= a;}
  mint pow(ll t) const {
    if(!t) return 1;
    mint res = pow(t/2);
    res *= res;
    return (t&1)?res*x:res;
  }
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
mint ex(mint x, ll t) { return x.pow(t);}
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}
typedef vector<mint> vm;
struct comb {
  vm f, g;
  comb(){}
  comb(int mx):f(mx+1),g(mx+1) {
    f[0] = 1;
    rrep(i,mx) f[i] = f[i-1]*i;
    g[mx] = f[mx].pow(mod-2);
    for(int i=mx;i>0;i--) g[i-1] = g[i]*i;
  }
  mint operator()(int a, int b) {
    if (a < b) return 0;
    return f[a]*g[b]*g[a-b];
  }
} c(MX);
//

int main() {
  int w,h; cin >> w >> h;
  mint dpw[h][w-1][2];
  mint dph[h-1][w][2];

  rep(i,h) rep(j,w-1) rep(k,2) dpw[i][j][k] = 0;
  rep(i,h-1) rep(j,w) rep(k,2) dph[i][j][k] = 0;

  rep(j,w-1) dpw[0][j][0] = 1;
  rep(i,h){if(i == 0) dpw[i][0][0] = 1; else dpw[i][0][1] = 1;}
  rep(i,h-1) dph[i][0][0] = 1;
  rep(j,w) if(j == 0) dph[0][j][0] = 1; else dph[0][j][1] = 1;

  rep(i,h){
    rep(j,w){
      if(i == 0 && j == 0) continue;
      if(j-1>=0) dpw[i][j][0] = dpw[i][j-1][0] + dpw[i][j-1][1];
      if(i-1>=0) dpw[i][j][1] = dph[i-1][j][0];
      if(i-1>=0) dph[i][j][0] = dph[i-1][j][0] + dph[i-1][j][0];
      if(j-1>=0) dph[i][j][1] = dpw[i][j-1][0];
    }
  }

  rep(i,h){
    rep(j,w-1){
      cout << dpw[i][j][0] << " ";
    }cout << endl;
  }

  mint ans = 0;
  ans += dpw[h-1][w-2][0];
  ans += dpw[h-1][w-2][1];
  ans += dph[h-2][w-1][0];
  ans += dph[h-2][w-1][1];
  cout << ans << endl;
  return 0;
}
