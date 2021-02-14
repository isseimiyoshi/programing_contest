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
// #define sz(x) (int)(x).size()
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
  int n; cin >> n;
  vi par(n-1);
  for(auto &v: par){
    cin >> v;
    --v;
  }

  vector<vector<int>> g(n);
  rep(v,n){
    if(v == 0) continue;
    g[par[v-1]].push_back(v);
  }
  vi sz(n,1); // 自分を含む部分木の頂点数 // 自分は初期状態で含んである
  vi f(n,1);  // 自分を含む部分木での得点（先手-後手）  // 訪れた頂点のコインは拾ってある状態
  const auto rec = [&](auto &&rec, int v) -> void {
    int sum = 0;
    vi seq;
    for(const auto &w: g[v]){
      rec(rec,w);// sz[w]が確定する
      sz[v] += sz[w];
      // もし子の頂点数が奇数ならば手番は変わる
      if(sz[w]%2){
        // case3
        seq.push_back(-f[w]); // 損が小さい方から順に取得する
      } else {
        if(f[w]<0){
          // case1
          f[v] -= -f[w];  // 真っ先に取得する
        }else{
          // case2
          sum += -f[w]; // 一番最後に損が少ない順に取得する
        }
      }
    }
    // ソートすることで、どの順番で頂点を訪れるべきか最適解を全探索しなくても求めることができる
    sort(seq.begin(), seq.end(), greater<int>());
    seq.push_back(sum);
    for(int i=0; i<(int)seq.size(); ++i){
      // iの偶奇で手番が誰かを判断し、得点を足す（または引く）処理を行う
      if(i%2){
        f[v] += seq[i];
      }else{
        f[v] -= seq[i];
      }
    }
  };
  rec(rec,0);
  int ans = (n+f[0])/2;
  cout << ans << endl;
  return 0;
}