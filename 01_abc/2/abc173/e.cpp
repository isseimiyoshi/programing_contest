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

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, const mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
// combination mod prime
// https://www.youtube.com/watch?v=8uowVvQ_-Mo&feature=youtu.be&t=1619
struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
  mint p(int n, int k) {
    return fact[n]*ifact[n-k];
  }
} c(2000005);

int main() {
  int n,k; cin >> n >> k;
  vl b(n);
  rep(i,n) cin >> b[i];

  if(n == k){
    mint ans = 1;
    rep(i,n) ans *= b[i];
    cout << ans << endl;
    return 0;
  }else if(k == 1){
    int ans = -INF;
    rep(i,n) ans = max(ans,(int)b[i]);
    if(ans<0) ans += mod;
    cout << ans << endl;
    return 0;
  }

  bool iszero = false;
  vl a;
  int mns = 0;
  int pls = 0;
  rep(i,n){
    if(b[i] == 0){
      iszero = true;
      continue;
    }else if(b[i]<0){
      mns++;
    }else{
      pls++;
    }
    a.push_back(b[i]);
  }
  int m = a.size();

  sort(rng(a));

  mint ans = 1;
  if(m<k){
    ans = (mint)0;
  }else if(m == k){
    if(mns%2 == 1 && iszero) ans = (mint)0;
    else{
      rep(i,m) ans *= a[i];
    }
  }else if(k%2 == 1 && a[m-1] < 0){ // 答えが負になる
    int cnt = 0;
    for(int i=m-1; i>=0; i--){
      ans *= a[i];
      cnt++;
      if(cnt == k) break;
    }
    if(iszero) ans = (mint)0;
  }else{
    if(k%2 == 1) ans *= (mint)a[m-1], --k,--m;
    vl s,t;
    rep(i,m){
      if(a[i]>0) s.push_back(a[i]);
      else t.push_back(a[i]);
    }
    sort(rrng(s));
    sort(rng(t));
    vl res;
    rep(i,(int)s.size()/2) res.push_back(s[2*i]*s[2*i+1]);
    rep(i,(int)t.size()/2) res.push_back(t[2*i]*t[2*i+1]);
    sort(rrng(res));
    rep(i,(int)res.size()){
      ans *= (mint)res[i];
      k -= 2;
      if(k == 0) break;
    }
    if(k == 1) ans *= (mint)s.back();
  } 
  cout << ans << endl;
  return 0;
}
