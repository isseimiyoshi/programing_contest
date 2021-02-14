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

const int MAX_N = 100100;

int n;
int s,t; 
vi to[MAX_N];
vi tonew[MAX_N];

ll is1[MAX_N];

void init(){
  rep(i,MAX_N){
    is1[i] = -1;
  }
}

void fto(int u, ll cnt){
  if(cnt%3 == 0 && is1[u] >= 0){
    if(is1[u]>cnt/3) is1[u] = cnt/3;
    else return;
  }else if(cnt%3 == 0 && is2[u] < 0){
    is1[u] = cnt/3;
  }

  if(cnt%3 == 0 && )

  for(int v: to[u]){
    fto(v,cnt+1);
  }
}

int main() {
  int m; cin >> n >> m;
  rep(i,m){
    int u,v; cin >> u >> v; --u, --v;
    to[u].push_back(v);
    from[v].push_back(u);
  }
  cin >> s >> t;
  --s,--t;

  init();

  fto(s,0);

  /*
  rep(i,n) cout << is1[i] << " ";
  cout << endl;
  rep(i,n) cout << is2[i] << " ";
  cout << endl;
  */
  
  /*
  ll ans = LINF;
  rep(i,n){
    if(is1[i]>=0 && is2[i]>=0) ans = min(ans, is1[i]+is2[i]);
  }
  if(ans == LINF) cout << -1 << endl;
  else cout << ans << endl;
  */

  if(is1[t] < 0) cout << -1 << endl;
  else cout << is1[t] << endl;
  return 0;
}
