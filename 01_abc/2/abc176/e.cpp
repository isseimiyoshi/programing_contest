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
  int H,W,m; cin >> H >> W >> m;
  vi h(m),w(m);
  rep(i,m){
    cin >> h[i] >> w[i];
    --h[i], --w[i];
  }
  vp bomb_w, bomb_h;
  rep(i,m){
    bomb_w.push_back(make_pair(w[i],h[i]));
    bomb_h.push_back(make_pair(h[i],w[i]));
  }
  sort(rng(bomb_h));
  sort(rng(bomb_w));

  vp cntH, cntW;
  rep(i,H){
    cntH.push_back(P((int)distance(upper_bound(rng(bomb_h),P(i,-1)), upper_bound(rng(bomb_h),P(i+1,-1))),i));
  }
  rep(i,W){
    cntW.push_back(P((int)distance(upper_bound(rng(bomb_w),P(i,-1)), upper_bound(rng(bomb_w),P(i+1,-1))),i));
  }
  sort(rrng(cntH));
  sort(rrng(cntW));

  vp maxH, maxW;
  rep(i,H){
    if(cntH[0].first-cntH[i].first > 1) break;
    maxH.push_back(make_pair(cntH[i].first,cntH[i].second));
  }
  rep(i,W){
    if(cntW[0].first-cntW[i].first > 1) break;
    maxW.push_back(make_pair(cntW[i].first,cntW[i].second));
  }
  int ans = -1;
  for(auto ph: maxH) for(auto pw: maxW){
    int cnth = ph.first, uh = ph.second;
    int cntw = pw.first, uw = pw.second;
    int now = cnth+cntw;
    int jdg = distance(lower_bound(rng(bomb_h),make_pair(uh,uw)), upper_bound(rng(bomb_h),make_pair(uh,uw)));
    if(jdg > 0) now--;
    ans = max(ans,now);
  }
  cout << ans << endl;
  return 0;
}
