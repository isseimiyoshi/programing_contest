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
  vl a(n),b(n);
  rep(i,n) cin >> a[i];
  sort(rrng(a));
  rep(i,n) b[i] = a[i]; // b: 降順
  reverse(rng(a));  // a：昇順

  vl sum(n+1); sum[0] = 0;
  rep(i,n){
    sum[i+1] = sum[i]+b[i]; // 降順aの累積和
  }

  /*
  rep(i,n+1){
    cout << sum[i] << " ";
  }cout << endl;
  */

  ll ans = 0;
  auto itr = b.begin();

  while(m>0){
    ll now = *itr;
    ll next = *(++itr); --itr;
    ll target = next*2-now;
    auto titr = lower_bound(rng(b),target,greater<ll>()); // target<0 →　b.end()
    int sumto = distance(b.begin(),titr);
    int sumfrom = distance(b.begin(),itr);

    printf("now:%d next:%d target:%d *titr:%d\n",now, next, target,*titr);

    if(m<2*sumto-2*sumfrom-1){
      ans += now*2; m--; ++itr;
      while(m>0){
        if(m == 1){
          ans += now+(*itr);
          m--;
        }else{
          ans += (now+(*itr))*2ll;
          m -= 2;
        }
        ++itr;
      }
      break;
    }

    ans += sum[sumto]-sum[sumfrom];
    ans += now*(sumto-sumfrom);
    ans += sum[sumto]-sum[sumfrom+1];
    ans += now*(sumto-sumfrom-1);

    ++itr;
    m -= 2*sumto-2*sumfrom-1;
  }
  cout << ans << endl;
  /*
  while(m>0){
    // if(itr == --a.end()){}
    ll ai = *itr;
    ll ai2 = *(--itr); ++itr;
    ll target = ai2*2-ai;
    auto titr = a.begin(); int from,to;
    if(target<0){
      from = n-distance(a.begin(),itr)-1;
      to = n;
    }else{
      titr = lower_bound(rng(a),target);
      from = n-distance(a.begin(),itr)-1;
      to = n-distance(a.begin(),titr);
    }

    if(m<2*to-2*from-1){
      ans += ai*2; m--;
      from++;
      while(m>0){
        if(m == 1){
          ans += ai*b[from];
          m--;
        }else{
          ans += ai*b[from]*2;
          m -= 2;
        }
        from++;
      }
      break;
    }

    ans += sum[to]-sum[from];
    ans += ai*(to-from);
    ans += sum[to]-sum[from+1];
    ans += ai*(to-from-1);
    --itr;
    m -= 2*to-2*from-1;
  }
  cout << ans << endl;
  */
  return 0;
}
