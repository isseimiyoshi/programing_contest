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
  ll r1, c1; cin >> r1 >> c1;
  ll r2, c2; cin >> r2 >> c2;
  int ans = 0;
  if(abs(r1-r2)+abs(c1-c2)<=3 || r1+c1 == r2+c2 || r1-c1 == r2-c2) ans = 1;
  else{
    if((r1+c1)%2 == (r2+c2)%2) ans = 2;
    else ans = 3;
  }

  for(int i=-3; i<=3; i++){
    for(int j=-3; j<=3; j++){
      if(abs(i)+abs(j) > 3) continue;
      int r3 = r2+i;
      int c3 = c2+j; 
      if(r1+c1 == r3+c3 || r1-c1 == r3-c3) ans = min(ans,2);
    }
  }
  if(r1 == r2 && c1 == c2) ans = min(ans,0);
  cout << ans << endl;
  return 0;
}
