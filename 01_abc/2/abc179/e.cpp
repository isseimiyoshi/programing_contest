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
  ll n,x,m; cin >> n >> x >> m;
  vector<pair<ll,ll> > sum(m,make_pair(-1,-1));

  ll now = x;
  sum[x] = make_pair(x,1);
  ll cnt = 1;
  ll ori = -1;
  ll ans = x;
  bool iscycle = false;
  while(cnt<n){
    cnt++;
    ori = now;  // A(i-1)
    now = (ori*ori)%m;  // A(i)

    if(iscycle){
      ans += now;
      continue;
    }

    ll orisum = sum[ori].first, oricnt = sum[ori].second;
    ll nowsum = orisum+now;
    if(sum[now].first >= 0){
      ll cycle = cnt-sum[now].second;
      ll cyclen = (n-cnt)/cycle;
      cnt += cyclen*cycle;
      nowsum += (nowsum-sum[now].first)*cyclen;
      ans = nowsum;
      iscycle = true;
    }else{
      sum[now].first = nowsum;
      sum[now].second = cnt;
      ans = orisum+now;
    }
  }
  cout << ans << endl;
  return 0;
}
