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

int mh[4] = {0,1,0,-1};
int mw[4] = {1,0,-1,0};

int main() {
  int h,w,k; cin >> h >> w >> k;
  int sh,sw,gh,gw; cin >> sh >> sw >> gh >> gw;
  --sh,--sw,--gh,--gw;

  int mass[h][w];
  rep(i,h){
    rep(j,w){
      char moji; cin >> moji;
      if(moji == '.') mass[i][j] = 0;
      else mass[i][j] = 1;
    }
  }

  int d[h][w];
  rep(i,h) rep(j,w) d[i][j] = INF;
  d[sh][sw] = 0;

  queue<tuple<int,int,int,int> > q;
  q.push(make_tuple(sh,sw,-1,0));
  
  // cout << "ok" << endl;

  while(!q.empty()){
    int uh,uw,p,cnt;
    tie(uh,uw,p,cnt) = q.front();
    q.pop();
    rep(i,4){
      int vh = uh+mh[i];
      int vw = uw+mw[i];
      if(vh<0 || vw<0 || vh>=h || vw>=w) continue;
      if(mass[vh][vw] == 1) continue;

      /*
      if(vh == 0 && vw == 3){
        printf("uh:%d, uw:%d, cnt:%d\n", uh, uw, cnt);
      }
      */

      if(i == p){
        if(d[vh][vw]>d[uh][uw] && cnt+1<=k){
          d[vh][vw] = d[uh][uw];
          q.push(make_tuple(vh,vw,p,cnt+1));
        }else{
          if(d[vh][vw]>d[uh][uw]+1){
            d[vh][vw] = d[uh][uw]+1;
            q.push(make_tuple(vh,vw,p,1));
          }
        }
      }else{
        if(d[vh][vw]>d[uh][uw]+1){
          d[vh][vw] = d[uh][uw]+1;
          q.push(make_tuple(vh,vw,i,1));
        }
      }
    }
  }
  if(d[gh][gw] == INF) cout << -1 << endl;
  else cout << d[gh][gw] << endl; 

  /*
  rep(i,h){
    rep(j,w){
      cout << d[i][j] << " ";
    }cout << endl;
  }
  */
  return 0;
}
