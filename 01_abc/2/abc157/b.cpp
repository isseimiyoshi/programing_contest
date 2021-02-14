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
  int a[3][3];
  rep(i,3) rep(j,3) cin >> a[i][j];
  int isok[3][3];
  rep(i,3) rep(j,3) isok[i][j] = 0;
  int n; cin >> n;
  rep(i,n){
    int b; cin >> b;
    rep(i,3) rep(j,3) if(a[i][j] == b) isok[i][j] = 1;
  }
  bool ans = false;
  rep(i,3){
    int cnt = 0;
    rep(j,3) if(isok[i][j]) cnt++;
    if(cnt == 3) ans = true;
  }
  rep(j,3){
    int cnt = 0;
    rep(i,3) if(isok[i][j]) cnt++;
    if(cnt == 3) ans = true;
  }
  if(isok[0][0] + isok[1][1] + isok[2][2] == 3) ans = true;
  if(isok[0][2] + isok[1][1] + isok[2][0] == 3) ans = true; 
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
