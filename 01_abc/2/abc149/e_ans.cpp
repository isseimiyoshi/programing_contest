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
#include <atcoder/all>
using namespace atcoder;
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


int main() {
  ll n; ll m; cin >> n >> m;
  vl a(n);
  rep(i,n) cin >> a[i];
  sort(rng(a));
  vl sum(n+1,0);
  rep(i,n) sum[i+1] = sum[i]+a[i];

  auto calc = [&](ll x){
    ll tot = 0, num = 0;
    rep(i,n){
      int j = lower_bound(rng(a),x-a[i])-a.begin();
      num += n-j;
      tot += a[i]*(n-j)+(sum[n]-sum[j]);
    }
    return make_pair(tot,num);
  };

  ll l=0, r=200005;
  while(l+1<r){
    ll mid = (l+r)/2ll;
    if(calc(mid).second>=m) l=mid; else r=mid;
  }
  ll ans = calc(l).first;
  ans -= (calc(l).second-m)*l;
  cout << ans << endl;
  return 0;
}