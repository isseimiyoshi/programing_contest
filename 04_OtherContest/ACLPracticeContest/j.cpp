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

ll op(ll x, ll y) { return max(x,y); }
ll op2(ll x, ll y) { return min(x,y); }
ll e() { return 0; }
ll v;
bool f(ll x){ return x<v; }


int main() {
  int n,q; cin >> n >> q;

  segtree<ll,op,e> ma(n);
  segtree<ll,op2,e> mi(n);

  rep(i,n){
    ll ai; cin >> ai;
    ma.set(i,ai);
    mi.set(i,ai);
  }

  vl ans;
  rep(qi,q){
    int t; cin >> t;
    if(t == 1){
      ll x; cin >> x >> v;
      --x;
      ma.set(x,v);
      mi.set(x,v);
    }else if(t == 2){
      ll l,r; cin >> l >> r;
      --l;
      ans.push_back(ma.prod(l,r));
    }else{
      ll x; cin >> x >> v;
      --x;
      ll ret = ma.max_right<f>(x)+1;
      ans.push_back(ret);
    }
  }
  for(ll res: ans) cout << res << endl;
  return 0;
}
