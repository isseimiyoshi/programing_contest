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


int main() {
  int n, m; cin >> n >> m;
  int c[n];
  rep(i,n){
    int mi; cin >> mi; --mi;
    c[i] = mi;
  }

  int rui[m][n];
  rep(i,m){
    rep(j,n){
      if(j == 0) rui[i][j] = (c[j] == i ? 1: 0);
      else{
        if(c[j] == i) rui[i][j] = rui[i][j-1]+1;
        else rui[i][j] = rui[i][j-1];
      }
    }
  }

  int dp[(1<<m)];
  rep(i,(1<<m)) dp[i] = INF;
  dp[0] = 0;

  rep(i,(1<<m)){
    rep(j,m){
      if(i>>j&1) continue;
      int cnt = 0;
      rep(k,m) if(i>>k&1) cnt+= rui[k][n-1];
      if(cnt == 0) dp[i|(1<<j)] = min(dp[i]+(rui[j][n-1]-(rui[j][rui[j][n-1]-1])), dp[i|(1<<j)]);
      else dp[i|(1<<j)] = min(dp[i]+(rui[j][n-1]-(rui[j][cnt+rui[j][n-1]-1]-rui[j][cnt-1])), dp[i|(1<<j)]);
    }
  }
  // cout << dp[2] << endl;
  cout << dp[(1<<m)-1] << endl;
  return 0;
}
