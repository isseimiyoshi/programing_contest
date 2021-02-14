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

ll gcd(ll x, ll y){
  if(x%y == 0) return y;
  return gcd(y,x%y);
}

ll lcm(ll x, ll y){
  return x*y/gcd(x,y);
}

int f(ll n){
  int cnt = 0;
  while(n%2 == 0){
    n /= 2;
    cnt++;
  }
  return cnt;
}

int main() {
  int n; ll m; cin >> n >> m;
  vl a(n);
  int p2 = -1;
  rep(i,n){
    cin >> a[i];
    if(p2 == -1) p2 = f(a[i]);
    else{ if(p2 != f(a[i])){ cout << 0 << endl; return 0; } }
  }
  rep(i,n) a[i] /= pow(2,p2);

  ll lcmn = 1;
  rep(i,n){
    lcmn = lcm(lcmn,a[i]);
    if(lcmn>(ll)INF){ cout << 0 << endl; return 0;}
  }
  
  lcmn *= pow(2,p2-1);

  int ans = 0;
  if(lcmn>m) ans = 0;
  else{
    ans = m/lcmn;
    if(ans%2 == 0) ans /= 2;
    else ans = ans/2+1;
  }
  cout << ans << endl;

  return 0;
}
