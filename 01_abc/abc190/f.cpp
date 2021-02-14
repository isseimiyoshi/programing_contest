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

int n; 

 // 1-indexedなので注意。
 struct BIT {
  private:
   vector<int> bit;
   int N;
 
  public:
   BIT(int size) {
     N = size;
     bit.resize(N + 1);
   }
 
   // 一点更新です
   void add(int a, int w) {
     for (int x = a; x <= N; x += x & -x) bit[x] += w;
   }
 
   // 1~Nまでの和を求める。
   int sum(int a) {
     int ret = 0;
     for (int x = a; x > 0; x -= x & -x) ret += bit[x];
     return ret;
   }
 };

int main() {
  cin >> n;
  vl a(n);
  rep(i,n) cin >> a[i];
  set<ll> s;

  vl v(n);
  rep(i,n) v[i] = a[i]+1;

  ll ten = 0;
   BIT b(n);  // これまでの数字がどんな風になってるのかをメモる為のBIT
   for (int i = 0; i < n; i++) {
     ten += i - b.sum(v[i]); // BITの総和 - 自分より左側 ＝ 自分より右側
     b.add(v[i], 1); // 自分の位置に1を足す(ダジャレではないです)
   }
  
  
  vl ans(n);
  ans[0] = ten;
  for(int i=n-1; i>0; i--){
    ll now = 0;
    now += a[i];
    now -= n-a[i]-1;
    ten += now;
    ans[i] = ten;
  }
  rep(i,n) cout << ans[i] << endl;
  
  // cout << ten << endl;
  return 0;
}
