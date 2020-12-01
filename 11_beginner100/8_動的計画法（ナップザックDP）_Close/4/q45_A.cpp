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

ll f(ll x, ll c){
  if(x+c>=255) return 255;
  if(x+c<=0) return 0;
  return x+c;
}

int main() {
  vl ans;
  while(true){
    int n, m; cin >> n >> m;
    if(n == 0 && m == 0) break;
    vi c(m), x(n);
    rep(i,m) cin >> c[i];
    rep(i,n) cin >> x[i];

    ll dp[n][m];
    vl y(m);
    rep(j,m) y[j] = 128;

    rep(i,n) rep(j,m) dp[i][j] = LINF;
    rep(j,m) y[j]=f(x[0],c[j]),dp[0][j] = (x[0]-y[j])*(x[0]-y[j]);

    rep(i,n){
      if(i == 0) continue;
      vl y2(m);
      rep(j,m){
        rep(k,m){
          if(dp[i][j]>dp[i-1][k]+(x[i]-(y[k],c[j])*(x[i]-(y[k],c[j])))){
            dp[i][j]=dp[i-1][k]+(x[i]-f(y[k],c[j])*(x[i]-f(y[k],c[j])));
            y2[j] = f(y[k],c[j]);
          }
        }
      }
      rep(j,m) y[j] = y2[j];
    }
    ans.push_back(dp[n-1][m-1]);
  }
  for(ll res: ans) cout << res << endl;
  return 0;
}
