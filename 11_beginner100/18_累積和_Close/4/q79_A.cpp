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
  int n, m, q; cin >> n >> m >> q;
  int tr[n+1][n+1];
  rep(i,n+1) rep(j,n+1) tr[i][j] = 0;
  rep(_,m){
    int l,r; cin >> l >> r; --l,--r;
    tr[r+1][l+1]++;
  }
  int rui[n+1][n+1];
  rep(i,n+1) rep(j,n+1) rui[i][j] = 0;
  rep(i,n){
    rep(j,n){
      rui[i+1][j+1] = rui[i+1][j]+rui[i][j+1]-rui[i][j]+tr[i+1][j+1];
    }
  }
  vi ans(q);
  rep(i,q){
    int pi,qi; cin >> pi >> qi;
    ans[i] = rui[qi][qi]-rui[qi][pi-1]-rui[pi-1][qi]+rui[pi-1][pi-1];
  }
  rep(i,q) cout << ans[i] << endl;
  /*
  rep(i,n+1){
    rep(j,n+1){
      cout << rui[i][j] << " ";
    }cout << endl;
  }
  */
  return 0;
}

