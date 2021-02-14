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
  int n ; cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  vi cnt(n,0);

  auto f = [&](int x){
    // cnt[x-1] = (cnt[x-1]+1)%2;
    cnt[0] = (cnt[0]+1)%2;
    if(x != 1) cnt[x-1] = (cnt[x-1]+1)%2;
    for(int i=2; i*i<=x; i++){
      while(x%i == 0){
        x /= i;
        cnt[x-1] = (cnt[x-1]+1)%2;
        cnt[i-1] = (cnt[i-1]+1)%2;
      }
    }
  };

  int ans = 0;
  vi b(n,0);
  for(int i=n-1; i>=0; i--){
    if(a[i] == 0){
      if(cnt[i] == 0) continue;
      else{
        ans++;
        b[i]++;
        f(i+1);
      }
    }else{
      if(cnt[i] == 1) continue;
      else{
        ans++;
        b[i]++;
        f(i+1);
      }
    }
  }
  cout << ans << endl;
  vi ansv;
  rep(i,n){
    if(cnt[i] == 1) ansv.push_back(i+1);
  }
  int n2 = ansv.size();
  rep(i,n2){
    cout << ansv[i];
    if(i != n2-1) cout << " ";
  }
  cout << endl;
  return 0;
}
