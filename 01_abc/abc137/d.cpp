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
  int n,m; cin >> n >> m;
  vp p;
  rep(i,n){
    int ai,bi; cin >> ai >> bi;
    p.push_back(P(bi,ai));
  }

  // バイトに使うことのできる日数表の作成
  multiset<int> s;

  // バイトを報酬順にソート
  sort(rng(p));
  reverse(rng(p));

  /*
  rep(i,n){
    printf("b:%d a:%d\n", p[i].first, p[i].second);
  }
  */

  ll ans = 0;
  // 使用した日付を消していき、まだ使える日付をO(1)であぶりだせるようにセット
  rep(i,n){
    int a,b;
    a = p[i].second, b = p[i].first;
    if(m-a<0) continue;
    // cout << j << endl;
    if(!s.count(m-a)){
      s.insert(m-a);
      ans += b;
    }else{
      if(distance(s.begin(),lower_bound(rng(s),m-a)) == m-a) continue;
      else{
        s.insert(m-a);
        ans += b;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
