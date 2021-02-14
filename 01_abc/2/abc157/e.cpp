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
#include <atcoder/all>
using namespace atcoder;

vector<int> op(vector<int> a, vector<int> b){
  vector<int> p(26,0);
  rep(i,26) if(a[i] || b[i]) p[i] = 1;
  return p;
}

vector<int> e(){ return vector<int>(26); }

int main() {
  int n; cin >> n;
  string s; cin >> s;
  segtree<vector<int>,op,e> t(n);

  rep(i,n){
    vector<int> p(26,0);
    p[s[i]-'a'] = 1;
    t.set(i,p);
  }

  int q; cin >> q;
  vi ans;
  rep(_,q){
    int qu; cin >> qu;
    if(qu == 1){
      int i; char c; cin >> i >> c; --i;
      vector<int> p = t.get(i);
      int si = c-'a';
      if(p[si] == 1) continue;
      else{
        p = vector<int>(26);
        p[si] = 1;
        t.set(i,p);
      }
    }else{
      int l,r; cin >> l >> r; --l,r;
      vector<int> p = t.prod(l,r);
      int cnt = 0;
      rep(i,26) if(p[i] == 1) cnt++;
      ans.push_back(cnt);
    }
  }
  /*
  vector<int> p = t.prod(0,n);
  rep(i,26) cout << p[i] << " ";
  cout << endl;
  */

  for(int res: ans) cout << res << endl;
  return 0;
}
