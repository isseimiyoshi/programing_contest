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


int main() {
  int n,m; cin >> n >> m;
  vi a(m),b(m);
  // 自分がつながっている辺のbit集合
  vi e(n);
  rep(i,m){
    cin >> a[i] >> b[i];
    a[i]--,b[i]--;
    e[a[i]] |= 1<<b[i];
    e[b[i]] |= 1<<a[i];
  }
  // 集合Aをいくつのクリークで実現できるか
  vi dp(1<<n,INF);
  dp[0] = 0; // 集合にどの頂点も含まれていない場合は0個のクリーク

  // 集合iがクリークになっているか調べる
  for(int i=1; i<(1<<n); i++){
    rep(j,n){
      // jbit目が立っているか
      if((i&(1<<j)) == 0) continue; // jビット目が立っていない場合
      int target = i-(1<<j);  // jbit目がたっている場合、集合iからjビット目をへらす
      if(dp[target]<=1 && (e[j]&target) == target){
        dp[i] = 1;
      }
      // 1つ調べれば十分なのでbreak
      break;
    }
  }
  // 集合iが何個のクリークで実現できるか考える
  rep(i,(1<<n)){
    for(int j=i; j>0; j=(j-1)&i){
      // iを　jとk　の2つの集合に分ける
      int k = i-j;
      // 適切な分け方を探して最小値を更新する
      dp[i] = min(dp[i],dp[j]+dp[k]);
    }
  }
  cout << dp[(1<<n)-1] << endl;
  return 0;
}