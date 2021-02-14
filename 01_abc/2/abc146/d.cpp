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

vp to[MAX_N];
vi clr(MAX_N,-1);
int clr_n;

void dfs(int u, int pe){
  int c = 1;
  for(auto p: to[u]){
    int v = p.first, e = p.second;
    if(pe >= 0 && c == clr[pe]) c++;
    if(clr[e] > 0) continue;
    clr[e] = c;
    dfs(v,e);
    c++;
  }
}

int main() {
  int n; cin >> n;
  vi dim(n,0);
  rep(i,n-1){
    int a,b; cin >> a >> b;
    --a,--b;
    to[a].push_back(P(b,i));
    to[b].push_back(P(a,i));
    dim[a]++, dim[b]++;
  }
  clr_n = 0;
  rep(i,n){
    clr_n = max(clr_n,dim[i]);
  }

  dfs(0,-1);

  cout << clr_n << endl;
  rep(i,n-1){
    cout << clr[i] << endl;
  }
  return 0;
}
