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
  int n,m,q; cin >> n >> m >> q;
  vi a(q),b(q),c(q),d(q);
  rep(i,q) cin >> a[i] >> b[i] >> c[i] >> d[i], --a[i],--b[i];
  vi A(n,-INF);

  int ans = 0;
  rep(i,(1<<q)){
    rep(k,n) A[k] = -INF;
    int res = 0;
    rep(j,q){
      if(i>>j&1){
        if(A[b[j]] == -INF && A[a[j]] == -INF){
          A[b[j]] = c[j];
          A[a[j]] = 0;
        }else if(A[b[j]] == -INF){
          A[b[j]] = c[j]+A[a[j]];
        }else if(A[a[j]] == -INF){
          A[a[j]] = A[b[j]]-c[j];
        }else{
          if(A[b[j]]-A[a[j]] != c[j]) continue;
        }
        res += d[j];
      }
    }

    int maxn = -INF;
    int minn = INF;
    rep(k,n){
      maxn = max(maxn, A[k]);
      if(A[k] != -INF) minn = min(minn, A[k]);
    }
    // printf("%d %d\n", maxn, minn);
    if(maxn-minn < m) ans = max(ans, res);
  }
  cout << ans << endl;
  return 0;
}
