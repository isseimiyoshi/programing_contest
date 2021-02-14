#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
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
  int n; cin >> n;
  ll k; cin >> k;
  vl a(n),b(n+1);
  rep(i,n){
    cin >> a[i];
  }
  b[0]= 0;
  rep(i,n){
    b[i+1] = b[i]+a[i];
  }
  vl y(n+1);
  rep(i,n+1) y[i] = (b[i]-i)%k;

  /*
  rep(i,n+1) cout << y[i] << " ";
  cout << endl;
  */

  vector<map<ll,ll> > mp(n+1);
  mp[0][0] = 1;
  rep(i,n+1){
    if(i == 0) continue;
    mp[i] = mp[i-1];
    mp[i][y[i]]++;
  }
  ll ans = 0;
  rep(i,n+1){
    int to = min(n,int(i+k-1));
    ll now = mp[to][y[i]]-mp[i][y[i]];
    // printf("%d %d\n",i,now);
    ans += now;
  }
  cout << ans << endl;
  /*
  rep(i,n+1){
    cout << i << endl;
    for(auto p: mp[i]) cout << p.first << " " << p.second << endl;
  }
  */
  return 0;
}