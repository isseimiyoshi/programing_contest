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
#include <atcoder/all>
using namespace atcoder;
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

int c[10][1005];

int main() {
  int h,w,k; cin >> h >> w >> k;
  vector<string> s(h);
  rep(i,h) cin >> s[i];

  int ans = INF;

  rep(div,(1<<(h-1))){
    int g = 0;  // 横方向に分割したときのグループ数
    vi id(h);
    rep(i,h){
      id[i] = g;
      if(div>>i&1) g++;
    }
    g++;  // 変数gをグループ数を表す数値とするため
    rep(i,g) rep(j,w) c[i][j] = 0;  // 初期化:
    rep(i,h) rep(j,w) c[id[i]][j] += (s[i][j]-'0');

    int num = g-1;  //すでに横方向にこの回数だけ割っているため
    vector<int> now(g);

    auto add = [&](int j){
      rep(i,g) now[i] += c[i][j];
      rep(i,g) if(now[i]>k) return false;
      return true;
    };

    rep(j,w){
      if(!add(j)){
        num++;
        now = vector<int>(g);
        if(!add(j)){
          num = INF;
          break;
        }
      }
    }
    ans = min(ans, num);
  } 
  cout << ans << endl;
  return 0;
}