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
  int n, m; cin >> m >> n;
  int q; cin >> q;
  int area[m][n];
  rep(i,m){
    rep(j,n){
      char moji; cin >> moji;
      if(moji == 'J'){
        area[i][j] = 0;
      }else if(moji == 'O'){
        area[i][j] = 1;
      }else{
        area[i][j] = 2;
      }
    }
  }
  int rui[m][n][3];
  rep(i,m) rep(j,n) rep(k,3) rui[i][j][k] = 0;
  rui[0][0][area[0][0]]++;
  for(int j=1; j<n; j++){
    rep(k,3){
      if(k != area[0][j]) rui[0][j][k] = rui[0][j-1][k];
      else rui[0][j][k] = rui[0][j-1][k]+1;
    }
  }
  for(int i=1; i<m; i++){
    rep(k,3){
      if(k != area[i][0]) rui[i][0][k] = rui[i-1][0][k];
      else rui[i][0][k] = rui[i-1][0][k]+1;
    }
  }

  for(int i=1; i<m; i++){
    for(int j=1; j<n; j++){
      rep(k,3){
        if(k == area[i][j]) rui[i][j][k] = rui[i][j-1][k]+rui[i-1][j][k]+1-rui[i-1][j-1][k];
        else rui[i][j][k] = rui[i][j-1][k]+rui[i-1][j][k]-rui[i-1][j-1][k];
      }
    }
  }
  /*
  rep(i,m){
    rep(j,n){
      cout << rui[i][j][0] << " ";
    }cout << endl;
  }
  */

  int ans[q][3];
  rep(i,q){
    int i1,j1,i2,j2; cin >> i1 >> j1 >> i2 >> j2; --i1,--j1,--i2,--j2;
    rep(k,3){
      if(i1 == 0 && j1 == 0) ans[i][k] = rui[i2][j2][k];
      else if(i1 == 0) ans[i][k] = rui[i2][j2][k]-rui[i2][0][k];
      else if(j1 == 0) ans[i][k] = rui[i2][j2][k]-rui[0][j2][k];
      else ans[i][k] = rui[i2][j2][k] - rui[i2][j1-1][k] - rui[i1-1][j2][k] + rui[i1-1][j1-1][k];
    }
  }
  rep(i,q){
    printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
  }
  return 0;
}
