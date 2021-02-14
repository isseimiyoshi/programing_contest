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
  int n; cin >> n;
  string s; cin >> s;
  ll ans = 0;

  vi r(n,0), g(n,0), b(n,0);
  if(s[0] == 'R') r[0] = 1;
  if(s[0] == 'G') g[0] = 1;
  if(s[0] == 'B') b[0] = 1;

  rep(i,n){
    if(i == 0) continue;
    r[i] = r[i-1];
    g[i] = g[i-1];
    b[i] = b[i-1];
    if(s[i] == 'R') r[i] += 1;
    if(s[i] == 'G') g[i] += 1;
    if(s[i] == 'B') b[i] += 1;
  }
  // printf("%d %d %d\n", r[n-1], g[n-1], b[n-1]);

  rep(i,n){
    for(int j=i+1; j<n; j++){
      if(j == n-1) continue;
      if(s[i] == s[j]) continue;
      int k = 2*j-i;
      char c[3] = {'R', 'G', 'B'};
      rep(l,3){
        if(c[l] == s[i] || c[l] == s[j]) continue;
        if(c[l] == 'R') ans += (ll)(r[n-1]-r[j]);
        if(c[l] == 'G') ans += (ll)(g[n-1]-g[j]);
        if(c[l] == 'B') ans += (ll)(b[n-1]-b[j]);
        if(k<n && k>j && c[l] == s[k]) ans--;
        // cout << c[l] << " " << ans << endl;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
