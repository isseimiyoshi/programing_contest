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
  int n, k; cin >> n >> k;
  string s; cin >> s;

  vi p;
  int ori = -1;
  int cnt = 0;
  rep(i,n){
    int now = int(s[i]-'0');
    if(i == 0){
      ori = now;
      cnt++;
      continue;
    }
    if(now == ori){
      cnt++;
      if(i == n-1) p.push_back(cnt);
    }else{
      ori = now;
      p.push_back(cnt);
      cnt = 1;
      if(i == n-1) p.push_back(cnt);
    }
  }

  int x;
  if(s[0] == '0') x = 0;
  else x = 1;

  int n2 = p.size();
  vi sump(n2);
  
  rep(i,n2){
    if(i == 0) sump[i] = p[i];
    else{
      sump[i] = sump[i-1]+p[i];
    }
  }

  /*
  cout << n2 << endl;
  rep(i,n2){
    cout << sump[i] << " ";
  }cout << endl;
  */

  int ans = -1;
  rep(i,n2){
    int mi = (i == 0) ? 0 : sump[i-1];
    if(x == 1){
      if(i%2 == 0){
        if(i+k*2<n2) ans = max(ans, sump[i+k*2]-mi);
        else ans = max(sump[n2-1]-mi,ans);
      }else{
        if(i+2*k-1<n2) ans = max(ans, sump[i+2*k-1]-mi);
        else ans = max(sump[n2-1]-mi,ans);
      }
    }else{
      if(i%2 == 0){
        if(i+2*k-1<n2) ans = max(ans, sump[i+2*k-1]-mi);
        else ans = max(sump[n2-1]-mi,ans);
      }else{
        if(i+k*2<n2) ans = max(ans, sump[i+k*2]-mi);
        else ans = max(sump[n2-1]-mi,ans);
      }
    }
  }
  if(ans == -1) ans = n;
  cout << ans << endl;

  /*
  for(int pi: p){
    cout << pi << endl;
  }
  */
  return 0;
}
