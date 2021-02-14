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
  int n; ll k; cin >> n >> k;
  vi a(n);
  rep(i,n) cin >> a[i];
  int sum = 0;
  rep(i,n) sum += a[i];

  set<int> s;
  for(int i=1; i*i<=sum; i++){
    if(sum%i == 0){
      s.insert(i);
      s.insert(sum/i);
    }
  }

  // for(auto si: s) cout << si << endl;

  int ans = 0;
  // 整数列Aの合計の約数の種類をループで回す
  for(auto si: s){
    int b[n];
    // 約数のMODを求める
    rep(i,n){
      b[i] = a[i]%si;
    }
    sort(b,b+n);
    // MODをゼロにする部分（マイナスする部分）とMODを割った値にする部分（プラスする部分）で分ける境界をループ
    // マイナスとプラスをそれぞれカウントする
    ll acnt = 0;
    ll mcnt = 0;
    rep(i,n){
      rep(j,i) mcnt += b[j];
      for(int j=i; j<n; j++) acnt += si-b[j];
      // マイナスカウントとプラスカウントを比較し、大きい方がKより大きいか小さいか比較する
      ll res = max(acnt,mcnt);
      // Kより大きい場合は、約数が条件に合わないためcontinue
      if(res<=k){
        ans = max(ans, si);
        // printf("si:%d ans:%d\n", si, ans);
      }
      acnt = mcnt = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
