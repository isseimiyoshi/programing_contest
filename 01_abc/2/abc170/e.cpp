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
#include <atcoder/all>
using namespace atcoder;

int op(int x, int y) { return min(x,y); }
int e() { return INF; }

const int kind = 200000;

segtree<int,op,e> s(kind);
multiset<int> se[kind];

int main() {
  int n,q; cin >> n >> q;
  
  vi rate(n);
  vi zoku(n);
  
  rep(i,n){
    int a,b; cin >> a >> b;
    rate[i] = a;
    --b;
    zoku[i] = b;
    se[b].insert(a);
    if(s.get(b) == INF ||  s.get(b) < a) s.set(b,a);
  }

  // cout << s.prod(0,kind) << endl;

  // cout << "ok" << endl;

  vi ans;
  rep(qi,q){
    int c,d; cin >> c >> d; --c,--d;

    int b = zoku[c];
    se[b].erase(rate[c]);
    if(se[b].empty()) s.set(b,INF);
    else if(s.get(b) == rate[c]) s.set(b,*(--se[b].end()));
    
    se[d].insert(rate[c]);
    if(s.get(d) == INF ||  s.get(d)<rate[c]) s.set(d,rate[c]);
    zoku[c] = d;

    ans.push_back(s.prod(0,kind));  
  }
  for(int res: ans) cout << res << endl;
  return 0;
}
