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

vl pow2;

ll f(ll now, ll cnt){
  ll res = cnt;
  while(true){
    ll w = pow2[cnt];
    res += now/w;
    if(now%w == 0) break;
    now %= w;
    cnt--;
  }
  return res;
}


int main() {
  ll x,y; cin >> x >> y;

  ll p = 1;
  pow2.push_back(p);
  while(p<LINF){
    p *= 2;
    pow2.push_back(p);
  }

  ll ans = 0;
  if(x == y) ans = 0;
  else if(x>y) ans = x-y;
  else{
    ll res = LINF;
    // 愚直にプラスとマイナスのみ使用してxをyに合わせた場合の操作回数
    res = min(res,y-x);

    ll cnt = 0;
    ll now = x;
    while(true){
      now *= 2;
      cnt++;
      if(y/2<now) break;
    }
    // 関数fは2倍という操作とプラス、マイナスを効率よく使用した場合の操作回数を返す
    // 2倍してからプラス（もしくはマイナス）するよりも、プラス（もしくはマイナス）してから2倍したほうが操作回数が少ないということを利用している
    res = min(res, f(now-abs(now-y),cnt+1));
    res = min(res, f(abs(now-y),cnt));
    ans = res;
  }
  cout << ans << endl;
  return 0;
}
