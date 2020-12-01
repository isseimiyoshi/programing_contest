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

const int mod = 10007;
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

const int MAX_N = 1010;

mint dp[MAX_N][7];

void init(){
  rep(i,MAX_N){
    rep(j,7){
      dp[i][j] = 0;
    }
  }
}

/*

以下の関数fをビット演算を使用することによって、簡潔に記述することが可能になる

*/
void f(int i, char now){
  if(now == 'J'){
    dp[i][1] = dp[i][2] = dp[i][4] = 0;
    dp[i][0] += (dp[i-1][0]+dp[i-1][3]+dp[i-1][5]+dp[i-1][6]);

    rep(j,7) if(j != 2) dp[i][3] += dp[i-1][j];
    rep(j,7) if(j != 1) dp[i][5] += dp[i-1][j];
  }else if(now == 'O'){
    dp[i][0] = dp[i][2] = dp[i][5] = 0;
    dp[i][1] += (dp[i-1][1]+dp[i-1][3]+dp[i-1][4]+dp[i-1][6]);

    rep(j,7) if(j != 2) dp[i][3] += dp[i-1][j];
    rep(j,7) if(j != 0) dp[i][4] += dp[i-1][j];
  }else{
    dp[i][0] = dp[i][1] = dp[i][3] = 0;
    dp[i][2] += (dp[i-1][2]+dp[i-1][4]+dp[i-1][5]+dp[i-1][6]);

    rep(j,7) if(j != 0) dp[i][4] += dp[i-1][j];
    rep(j,7) if(j != 1) dp[i][5] += dp[i-1][j];
  }
  rep(j,7) dp[i][6] += dp[i-1][j];
}

int main() {
  int n; cin >> n;
  string s; cin >> s;

  init();

  if(s[0] == 'J'){
    dp[0][0] = dp[0][3] = dp[0][5] = dp[0][6] = 1;
  }else if(s[0] == 'O'){
    dp[0][3] = dp[0][6] = 1;
  }else{
    dp[0][5] = dp[0][6] = 1;
  }

  for(int i=1; i<n; i++){
    f(i,s[i]);
  }
  /*
  rep(i,n){
    rep(j,7){
      cout << dp[i][j] << " ";
    }cout << endl;
  }
  */

  mint ans = 0;
  rep(i,7) ans += dp[n-1][i];
  cout << ans << endl;
  return 0;
}
