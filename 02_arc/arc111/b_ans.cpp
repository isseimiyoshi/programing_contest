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

const int MAX_A = 400100;

// Unionfind
struct uf{
  vl d;
  uf() {};
  uf(ll mx) : d(mx,-1) {};
  int root(int x){
    if(d[x]<0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y){
    x = root(x); y = root(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y]; d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y);}
  ll size(int x){ return -d[root(x)];}
  int operator[] (int x) {return root(x);}
  int operator() (int x) {return size(x);}
};

int main() {
  int n; cin >> n;
  vl deg(MAX_A,0);
  uf dis(n);
  vi a(n),b(n);
  set<int> s;
  rep(i,n){
    cin >> a[i] >> b[i];
    --a[i],--b[i];
    dis.unite(a[i],b[i]);
    deg[a[i]]++;
    deg[b[i]]++;
    s.insert(a[i]);
    s.insert(b[i]);
  } 
  vl cnt(MAX_A,0);
  for(auto si: s){
    cnt[dis.root(si)] += deg[si];
  }
  vector<bool> isfin(MAX_A,false);
  int ans = 0;
  rep(i,n){
    int ra = dis.root(a[i]);
    int rb = dis.root(b[i]);
    // printf("%d %d %d\n",ra,cnt[ra],dis.size(ra));
    if(!isfin[ra]){
      if(cnt[ra]/2 == dis.size(ra)-1){
        ans += dis.size(ra)-1;
      }else{
        ans += dis.size(ra);
      }
      isfin[ra] = true;
    }
    if(!isfin[rb]){
      if(cnt[rb]/2 == dis.size(rb)-1){
        ans += dis.size(rb)-1;
      }else{
        ans += dis.size(rb);
      }
      isfin[rb] = true;
    }
  }
  cout << ans << endl;
  return 0;
}