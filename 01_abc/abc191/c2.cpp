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

const int mh[8] = {-1,-1,-1,0,1,1,1,0};
const int mw[8] = {-1,0,1,1,1,0,-1,-1};

int main() {
  int h,w; cin >> h >> w;
  int m[h][w];
  rep(i,h) rep(j,w){
    char moji; cin >> moji;
    if(moji == '#') m[i][j] = 1;
    else m[i][j] = 0;
  }

  int ans = 0;

  rep(i,h) rep(j,w){
    if(m[i][j] == 1){
      int sh = i, sw = j;
      int nowh = sh, noww = sw;
      int ph = -1, pw = -1;
      while(true){
        if(ans != 0 && nowh == sh && noww == sw) break;
        rep(i,8){
          int vh = nowh+mh[i], vw = noww+mw[i];
          if(vh == sh && vw == sw) continue;
          if(vh == ph && vw == pw) continue;
          int vh2 = nowh+mh[(i+9)%8], vw2 = noww+mw[(i+9)%8];
          int vh3 = nowh+mh[(i+7)%8], vw3 = noww+mw[(i+7)%8];
          if(vh2<0 || vw2<0 || vh2>=h || vw2>=w) continue;
          if(vh3<0 || vw3<0 || vh3>=h || vw3>=w) continue;
          if(m[vh][vw] == 0) continue;
          if(m[vh2][vw2] == 0 || m[vh3][vw3] == 0){
            ans++;
            while(true){
              if(m[nowh+mh[i]][noww+mw[i]] == 0){
                int ph = nowh-mh[i], pw = noww-mw[i];
                break;
              }
              nowh = nowh+mh[i], noww = noww+mw[i];
            }
            break;
          }
        }
      }
      break;
    }
  }
  cout << ans << endl;
  return 0;
}