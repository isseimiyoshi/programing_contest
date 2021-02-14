#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
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
  int h,w,m; cin >> h >> w >> m;
  vi bh(m),bw(m);
  vi cntbh(h,0), cntbw(w,0);
  rep(i,m){
    cin >> bh[i] >> bw[i];
    bh[i]--, bw[i]--;
    cntbh[bh[i]]++;
    cntbw[bw[i]]++;
  }
  int maxh = 0, maxw = 0;
  rep(i,h) maxh = max(maxh,cntbh[i]);
  rep(i,w) maxw = max(maxw,cntbw[i]);
  int cntmh = 0, cntmw = 0;
  rep(i,h) if(maxh == cntbh[i]) cntmh++;
  rep(i,w) if(maxw == cntbw[i]) cntmw++;

  int cnt = 0;
  rep(i,m){
    if(cntbh[bh[i]] + cntbw[bw[i]] == maxh+maxw) cnt++;
  }
  if(cnt == cntmh*cntmw) cout <<  maxh+maxw-1 << endl;
  else cout << maxh+maxw << endl;
  return 0;
}