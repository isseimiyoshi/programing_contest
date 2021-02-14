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
  int n,m; cin >> n >> m;
  string s[m];
  rep(i,m) cin >> s[i];
  mint dp[n+1][m+1][3];
  rep(i,n+1) rep(j,m+1) rep(k,3) dp[i][j][k] = 0;
  dp[0][0][0] = 1;

  rep(i,n) rep(j,m+1) rep(k,3) rep(l,10){
    if(i == 0 && l == 0) continue;  // １桁目で0になることはないので、飛ばす
    bool ok1 = false;
    bool ok2 = false;
    if(l%5 == 0) ok1 = true;
    if((k+l)%3 == 0) ok2 = true;
    // 言葉を発する条件を満たす場合は、言葉を発する回数に対応する次元を1つプラスする
    if(ok1 || ok2){
      if(j == m) continue;
      if(s[j] == "Fizz" && (!ok1 && ok2)) dp[i+1][j+1][(k+l)%3] += dp[i][j][k];
      else if(s[j] == "Buzz" && (ok1 && !ok2)) dp[i+1][j+1][(k+l)%3] += dp[i][j][k];
      else if(s[j] == "FizzBuzz" && (ok1 && ok2)) dp[i+1][j+1][(k+l)%3] += dp[i][j][k];
    }else{
      // 言葉を発する条件を満たさない場合は、言葉を発する回数に対応する次元をそのままにして場合の和をプラスする
      dp[i+1][j][(k+l)%3] += dp[i][j][k];
    }
  }
  mint ans = 0;
  rep(k,3){
    ans += dp[n][m][k];
  }
  cout << ans << endl;
  return 0;
}
