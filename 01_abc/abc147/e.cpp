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

const int MAX = 30000;
const int ADD = 15000;

int main() {
  int h, w; cin >>h>> w;
  int a[h][w], b[h][w];
  rep(i,h) rep(j,w) cin >> a[i][j];
  rep(i,h) rep(j,w) cin >> b[i][j];

  int ab[h][w];
  rep(i,h) rep(j,w) ab[i][j] = abs(a[i][j]-b[i][j]);

  bool dp[h][w][MAX];
  rep(i,h) rep(j,w) rep(k,MAX) dp[i][j][k] = false;
  dp[0][0][ADD+ab[0][0]] = true;
  dp[0][0][ADD-ab[0][0]] = true;
  
  rep(i,h) rep(k,MAX){
    if(k-ab[i][0]>=0) if(i != 0 && dp[i-1][0][k-ab[i][0]]) dp[i][0][k] = true;
    if(k+ab[i][0]<MAX) if(i != 0 && dp[i-1][0][k+ab[i][0]]) dp[i][0][k] = true;
  }

  rep(j,w) rep(k,MAX){
    if(k-ab[0][j]>=0) if(j != 0 && dp[0][j-1][k-ab[0][j]]) dp[0][j][k] = true;
    if(k+ab[0][j]<MAX) if(j != 0 && dp[0][j-1][k+ab[0][j]]) dp[0][j][k] = true;
  }

  rep(i,h){
    if(i == 0) continue;
    rep(j,w){
      if(j == 0) continue;
      rep(k,MAX){
        if(k-ab[i][j]>=0) if(dp[i-1][j][k-ab[i][j]] || dp[i][j-1][k-ab[i][j]]) dp[i][j][k] = true;
        if(k+ab[i][j]<MAX) if(dp[i-1][j][k+ab[i][j]] || dp[i][j-1][k+ab[i][j]]) dp[i][j][k] = true;
      }
    }
  }
  int ans = INF;
  rep(i,MAX){
    if(dp[h-1][w-1][i]) ans = min(abs(ADD-i), ans);
  }
  cout << ans << endl;
  return 0;
}
