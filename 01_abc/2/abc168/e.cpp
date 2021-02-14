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
const int mod = 1000000007;
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
  int n; cin >> n;
  ll a[n],b[n];
  rep(i,n){
    cin >> a[i] >> b[i];
  }

  vector<double> ab,ba;
  mint cnt = 0;
  rep(i,n){
    // cout << i << endl;
    if(a[i] == 0 && b[i] == 0){
      cnt = cnt+(mint)1;
    }else if(b[i] == 0){
      ab.push_back((double)LINF);
      ba.push_back(-(double)b[i]/(double)a[i]);
    }else if(a[i] == 0){
      ab.push_back((double)a[i]/(double)b[i]);
      ba.push_back((double)LINF);
    }else{
      ab.push_back((double)a[i]/(double)b[i]);
      ba.push_back(-(double)b[i]/(double)a[i]);
    }
  }

  // cout << "ok" << endl;

  int m = ab.size();
  set<double> s;
  // sort(rng(ba));

  mint ans = 1;
  rep(i,m){
    if(s.count(ab[i])) continue;
    if(lower_bound(rng(ba),ab[i]) != upper_bound(rng(ba),ab[i])){
      int num = distance(upper_bound(rng(ba),ab[i]), lower_bound(rng(ba),ab[i]));
      ans *= (mint)(num+2);
      cout << num+2 << endl;
      s.insert(ab[i]);
    }else{
      ans *= (mint)2;
      cout << 2 << endl;
    }
  }

  ans = ans-(mint)1;
  ans += cnt;

  cout << ans << endl;

  rep(i,m){
    printf("%.6f %.6f\n", ab[i], ba[i]);
  }
  
  return 0;
}