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
  ll n; cin >> n;
  set<ll> s;
  if(n == 2){
    cout << 1 << endl;
    return 0;
  }
  s.insert(n-1);
  for(ll i=2; i*i<=n-1; i++){
    if((n-1)%i == 0){
      s.insert(i);
      s.insert((n-1)/i);
    }
  }
  // cout << s.size() << endl;
  for(ll i=2; i*i<=n; i++){
    if(n%i == 0){
      ll a = i;
      ll b = n/i;
      ll ori_n = n;
      while(n%a == 0){
        n /= a;
      }
      if(n%a == 1) s.insert(a);
      n = ori_n;
      while(n%b == 0){
        n /= b;
      }
      if(n%b == 1) s.insert(b);
      n = ori_n;
      /*
      if((n/a)%a == 1) s.insert(a);
      if((n/b)%b == 1) s.insert(b);
      if((n/a) == 1) s.insert(a);
      if((n/b) == 1) s.insert(b);
      */
    }
  }
  s.insert(n);

  // for(ll res: s) cout << res << endl;
  cout << s.size() << endl;
  return 0;
}
