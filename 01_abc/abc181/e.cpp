#include <bits/stdc++.h>
#define fi first
#define se second
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
#define v(T) vector<T>
#define vv(T) v(v(T))
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
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;


int main() {
  int n, m; cin >> n >> m;
  vl h(n), w(m);
  cin >> h;
  cin >> w;

  sort(rng(h));
  sort(rng(w));

  if(n == 1){
    ll ans = LINF;
    rep(i,m){
      ans = min(ans, abs(h[0]-w[i]));
    }
    cout << ans << endl;
    return 0;
  }

  vl be(n/2);
  vl af(n/2);
  int bei = 0;
  for(int i=2; i<n; i+=2){
    be[bei] = abs(h[i]-h[i-1]);
    bei++;
  }
  int afi = 0;
  for(int i=0; i<n-2; i+=2){
    af[afi] = abs(h[i]-h[i+1]);
    afi++;
  }

  vl afr(n/2,0);
  vl ber(n/2,0);
  rep(i,n/2){
    if(i == 0){
      afr[0] = af[0];
      ber[0] = be[0];
      continue;
    }
    afr[i] = afr[i-1]+af[i];
    ber[i] = ber[i-1]+be[i];
  }

  ll ans = LINF;
  for(int i=0; i<n; i+=2){
    ll t;
    if(m == 1) t = abs(h[i]-w[0]);
    else if(lower_bound(rng(w),h[i]) == w.end()) t = abs(h[i]-*(--lower_bound(rng(w),h[i])));
    else if(lower_bound(rng(w),h[i]) == w.begin()) t = abs(h[i]-w[0]);
    else{
      ll t1 = abs(h[i]-*lower_bound(rng(w),h[i]));
      ll t2 = abs(h[i]-*(--lower_bound(rng(w),h[i])));
      t = min(t1,t2);
    }
    ll res = t;
    if(i/2>0) res += afr[i/2-1];

    if(i/2>0) res += ber[n/2-1]-ber[i/2-1];
    else res += ber[n/2-1];

    ans = min(ans, res);
  }
  cout << ans << endl;
  return 0;
  
}
