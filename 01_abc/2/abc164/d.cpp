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
  string s; cin >> s;
  reverse(rng(s));
  int n = s.size();

  vi n10(n);
  n10[0] = 1;
  rep(i,n){
    if(i == 0) continue;
    n10[i] = n10[i-1]*10;
    n10[i] %= 2019;
  }

  int cnt[n+1];
  cnt[0] = 0;
  rep(i,n){
    if(i == 0) cnt[i+1] = (int(s[i]-'0')*n10[i])%2019;
    else cnt[i+1] = (int(s[i]-'0')*n10[i]+cnt[i])%2019;
  }
  map<int,ll> mp;
  rep(i,n+1){
    mp[cnt[i]]++;
  }
  ll ans = 0;
  for(auto p: mp){
    if(p.second == 1) continue;
    // printf("%d %d\n", p.first, p.second);
    ans += p.second*(p.second-1)/2;
  }
  cout << ans << endl;
  // rep(i,n+1) cout << cnt[i] << endl;
  return 0;
  
}
