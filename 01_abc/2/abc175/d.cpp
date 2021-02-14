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
  int n; ll k; cin >> n >> k;
  vl p(n), c(n);
  rep(i,n) cin >> p[i], --p[i];
  rep(i,n) cin >> c[i];

  ll ans = -LINF;
  // スタート位置のループ
  rep(i,n){
    bool isrp = false;

    vector<pair<ll,ll> >  score(n);
    rep(j,n) score[j] = make_pair(-LINF, INF);  // 初期値
    score[i] = make_pair(0,0);
    ll sum = 0;
    ll cnt = 0;
    int now = i;
    while(true){
      // if(i == 1) printf("cnt:%d sum:%d now:%d\n",cnt,sum,now);
      if(cnt>=k) break;
      cnt++;
      now = p[now];
      sum += c[now];
      if(isrp){
        ans = max(ans, sum);
      }
      ll nsum = score[now].first, ncnt = score[now].second;
      if(nsum == -LINF){
        score[now] = make_pair(sum,cnt);
        ans = max(ans, sum);
      }else{
        if(nsum>=sum) break;
        ll rp = max((k-ncnt-cnt)/(cnt-ncnt), (ll)0);
        rp = max(rp-1, (ll)0);
        sum += rp*(sum-nsum);
        cnt += rp*(cnt-ncnt);
        ans = max(ans,sum);
        isrp = true;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
