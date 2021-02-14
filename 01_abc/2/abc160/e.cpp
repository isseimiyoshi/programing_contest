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
  int x,y,a,b,c; cin >> x >> y >> a >> b >> c;
  priority_queue<P> pq;
  rep(i,a){
    int pi; cin >> pi;
    pq.push(P(pi,0));
  }
  rep(i,b){
    int qi; cin >> qi;
    pq.push(P(qi,1));
  }
  rep(i,c){
    int ri; cin >> ri;
    pq.push(P(ri,2));
  }

  int cnt = 0;
  int cnta = 0;
  int cntb = 0;
  ll ans = 0;
  while(cnt<x+y){
    auto p = pq.top(); pq.pop();
    if(cnta == x && p.second == 0) continue;
    if(cntb == y && p.second == 1) continue;

    cnt++;
    ans += p.first;
    if(p.second == 0) cnta++;
    if(p.second == 1) cntb++;
  }
  cout << ans << endl;
  return 0;
}
