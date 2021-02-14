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
  ll n,m; cin >> n >> m;
  vl a(m);
  rep(i,m){
    cin >> a[i];
    --a[i];
  }
  sort(rng(a));

  if(m == 0){
    cout << 1 << endl;
    return 0;
  }

  vl p;
  rep(i,m){
    if(i == 0){
      if(a[i] != 0) p.push_back(a[i]);
      continue;
    }
    if(a[i] == a[i-1]+1) continue;

    p.push_back(a[i]-a[i-1]-1);
  }
  if(a[m-1] != n-1){
    p.push_back(n-1-a[m-1]);
  }

  ll n2 = p.size();
  ll mi = LINF;
  rep(i,n2){
    mi = min(mi, p[i]);
    // cout << p[i] << endl;
  }
  ll ans = 0;
  rep(i,n2){
    if(p[i]%mi == 0){
      ans += p[i]/mi;
    }else{
      ans += p[i]/mi + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
