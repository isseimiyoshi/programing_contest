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
  int n; cin >> n;
  vl a(n),b(n); vi p(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  int cnt = 0;
  rep(i,n){
    cin >> p[i]; --p[i];
    if(i == p[i]){
      cnt++;
      continue;
    }
    if(a[i]<=b[p[i]]){
      cout << -1 << endl;
      return 0;
    }
  }

  if(cnt == n){
    cout << 0 << endl;
    return 0;
  }

  vector<pair<ll,ll> > weight;
  vi bag(n);
  rep(i,n){
    weight.push_back(make_pair(a[i],i));
    bag[p[i]] = i;
  }
  sort(rng(weight));
  vp ans;
  rep(i,n){
    ll ai = weight[i].first, id = weight[i].second;
    // printf("id:%d p[id]:%d\n",id,p[id]);
    if(id == p[id]) continue;
    
    ans.push_back(make_pair(id,bag[id]));
    // p[bag[id]]: いま１番の荷物を持っているが持つ荷物
    p[bag[id]] = p[id];
    bag[p[id]] = bag[id];
    p[id] = id;
    bag[id] = id;
  }
  cout << ans.size() << endl;
  for(auto res: ans){
    printf("%d %d\n",res.first+1, res.second+1);
  }
  return 0;
}