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
vp to[MX];
vl dp1(n,0);
vl dp2(n,0);

void f(int u, int p){

  for(auto vp: to[u]){
    int v = vp.first;
    ll x = vp.second;
    dp1[v] += x + dp1[u];
    f(v,u);
  }
  if(p == -1) return;
  
}

int main() {
  cin >> n;
  ll sum = 0;
  pair<P,P> edge[n-1];
  rep(i,n-1){
    int ai,bi; cin >> ai >> bi; --ai,--bi;
    edge[i].first.first = ai;
    edge[i].first.second = bi;
    edge[i].second.first = 0;
    edge[i].second.second = 0;
  }
  int q; cin >> q;
  rep(_,q){
    int t,e; ll x;
    cin >> t >> e >> x; --e;
    sum += x;
    if(t == 1){
      edge[e].second.first += x;
    }else{
      edge[e].second.second += x;
    }
  }
  rep(i,n-1){
    int ai,bi,atob,btoa;
    ai = edge[i].first.first;
    bi = edge[i].first.second;
    atob = edge[i].second.first;
    btoa = edge[i].second.second;
    to[ai].push_back(make_pair(bi,atob));
    to[bi].push_back(make_pair(ai,btoa));
  }



  rep(i,n){
    for(auto p: to[i]){
      printf("%d %d %d\n",i+1,p.first+1,p.second);
    }
  }
  return 0;
}
