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

const int MAX_H = 11, MAX_W = 11;

const int mh[8] = {-1,-1,-1,0,1,1,1,0};
const int mw[8] = {-1,0,1,1,1,0,-1,-1};

int h,w;
int mass[MAX_H][MAX_W];
int ans = 0;
bool is[MAX_H][MAX_W];

void init(){
  rep(i,MAX_H){
    rep(j,MAX_W){
      mass[i][j] = 0;
      is[i][j] = false;
    }
  }
}

void solve(int uh, int uw, int ph, int pw, int sh, int sw){
  if()
  rep(i,8){
    int vh = uh+mh[i], vw = uw+mv[i];
    if(vh == ph && vw == pw) continue;
    if(mass[vh][vw] == 1){
      int vh2 = uh+mh[(i+9)%8], vw2 = uw+mw[(i+9)%8];
      int vh3 = uh+mh[(i+7)%8], vw3 = uw+mw[(i+7)%8];
      if(mass[vh2][vw2] == 0 || mass[vh3][vw3] == 0){
        ans++;
        int nowh = vh, noww = vw;
        while(true){
          if(mass[nowh+mh[i]][noww+mw[i]] == 0) break;
          nowh += mh[i], noww += mv[i];
          is[nowh][noww] = true;
        }
        solve(nowh, noww, nowh-mh[i], noww-mw[i], sh, sw);
        break;
      }
    }
  }
}


int main() {
  cin >> h >> w;
  init();
  int cntb = 0;
  rep(i,h){
    rep(j,w){
      char moji; cin >> moji;
      if(moji == '#') mass[i][j] = 1, cntb++;
    }
  }
  if(cntb == 1){
    cout << 1 << endl;
    return 0;
  }

  return 0;
}
