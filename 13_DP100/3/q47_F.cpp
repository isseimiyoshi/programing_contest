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

const int MAX_N = 4100;

int n;
vl a(MAX_N);

ll dp[MAX_N][MAX_N];

void init(){
  rep(i,MAX_N){
    rep(j,MAX_N){
      dp[i][j] = -1;
    }
  }
}

ll f(int l, int r){
  if(dp[l][r]>=0) return dp[l][r];
  if(l == r && n%2 == 1) return a[l];
  if(l == r && n%2 == 0) return 0;
  int cnt = (n-(r-l+1))%2;
  if(cnt == 1){
    if(a[l]>a[r]) dp[l][r] = f(l+1,r);
    else if(a[l]<a[r]) dp[l][r] = f(l,r-1);
  }else{
    dp[l][r] = max(f(l+1,r)+a[l], f(l,r-1)+a[r]);
  }
  return dp[l][r];
}

int main() {
  cin >> n;
  rep(i,n) cin >> a[i];
  rep(i,n) a[i+n] = a[i];

  init();

  ll ans = 0;
  for(int i=1; i<=n; i++){
    dp[i][i+n-2] = f(i,i+n-2);
    ans = max(ans, dp[i][i+n-2]+a[i-1]);
  }
  cout << ans << endl;
  
  return 0;
}
