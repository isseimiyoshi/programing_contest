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


int main() {
  int n; ll t; cin >> n >> t;
  vl a(n);
  rep(i,n) cin >> a[i];

  vl a1(n/2);
  vl a2(n-n/2);
  rep(i,n/2) a1[i] = a[i];
  for(int i=n/2; i<n; i++) a2[i-n/2] = a[i];

  int a1n = a1.size();
  int a2n = a2.size();

  vector<ll> s1;
  rep(i,(1<<a1n)){
    ll res = 0;
    rep(j,a1n){
      if(i&(1<<j)) res += a1[j];
    }
    s1.push_back(res);
  }
  sort(rng(s1));
  // s1.erase(unique(rng(s1)), s1.end());

  ll ans = -INF;
  rep(i,(1<<a2n)){
    ll res = 0;
    rep(j,a2n){
      if(i&(1<<j)) res += a2[j];
    }
    auto itr = upper_bound(rng(s1), t-res);
    --itr;
    if(t-(*itr+res) < 0) continue;
    if(abs(t-ans)>abs(t-(*itr+res))) ans = *itr+res;
  }
  cout << ans << endl;

  return 0;
}
