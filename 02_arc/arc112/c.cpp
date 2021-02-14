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

const int MAX_N = 100100;

int n;
vi to[MAX_N];

tuple<ll,ll,ll> dfs(int u, int flg){
  set<int> s;
  int op = 0;
  for(int v: to[u]) s.insert(v);
  if(s.empty()){
    if(flg == 0) return make_tuple(1,0,2);
    else return make_tuple(0,1,2);
  }

  ll ta = 0;
  ll ao = 0;
  if(flg == 0) ta++, flg++;
  else ao++, (flg+1)%2;
  op++;

  while(!s.empty()){
    ll tares = 0;
    ll aores = 0;
    ll cntres = 0;
    ll vres = -1;
    for(int v: s){
      ll tanow, aonow, cnt;
      tie(tanow, aonow, cnt) = dfs(v,(flg+1)%2);
      if(flg == 0 && tares<tanow){
        tares = tanow, aores = aonow, cntres = cnt, vres = v;
      }
    }
    
  }
}

int main() {
  cin >> n;
  rep(i,n-1){
    int p; cin >> p; --p;
    to[p].push_back(i+1);
  }

  return 0;
}
