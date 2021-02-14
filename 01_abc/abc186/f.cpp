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
  ll h,w,m; cin >> h >> w >> m;
  set<P> hw;
  set<P> wh;
  rep(i,m){
    int hi,wi; cin >> hi >> wi; --hi,--wi;
    if(hw.count(P(hi,wi)) || wh.count(P(wi,hi))) continue;
    if(hi == 0){
      for(int i=wi; i<w; i++){
        hw.insert(P(hi,i));
        wh.insert(P(i,hi));
      }
    }else if(wi == 0){
      for(int i=hi; i<h; i++){
        hw.insert(P(i,wi));
        wh.insert(P(wi,i));
      }
    }else{
      hw.insert(P(hi,wi));
      wh.insert(P(wi,hi));
    }
  }
  set<int> ws;
  set<int> hs;
  ll ans = h*w;
  for(auto p: hw){
    int hi = p.first, wi =p.second;
    if(!hs.count(hi)){
      ans--;
      if(ws.size() != 0){
        ll now = distance(ws.upper_bound(wi), ws.end());
        ans -= now;
      }
    }else{
      if(!ws.count(wi)){
        ans--;
      }
    }
    hs.insert(hi);
    ws.insert(wi);
  }
  cout << ans << endl;
  return 0;
}
