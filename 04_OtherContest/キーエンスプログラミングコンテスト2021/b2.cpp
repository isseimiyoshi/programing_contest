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
  int n,k; cin >> n >> k;
  vi a(n);
  rep(i,n) cin >> a[i];
  sort(rng(a));

  map<int,int> mp;
  
  rep(i,n){
    mp[a[i]]++;
  }

  set<int> s;
  rep(i,n){
    s.insert(i);
  }

  if(mp[0] == 0){
    cout << 0 << endl;
    return 0;
  }

  ll now = k;
  ll ans = 0;
  ll nsi = 0;
  for(auto si: s){
    // printf("%d %d\n",si,mp[si]);

    if(now>mp[si]){
      ans += si*(now-mp[si]);
      now = mp[si];
    }
    nsi = si;
    if(now == 0) break;
  }
  if(now != 0){
    ans += now*(nsi+1);
  }
  cout << ans << endl;

  return 0;
}