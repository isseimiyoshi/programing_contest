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
  string s; cin >> s;
  int n = s.size();

  int r[n][2];
  int l[n][2];
  rep(i,n) rep(j,2){
    r[i][j] = 0;
    l[i][j] = 0;
  }

  
  rep(i,n){
    if(s[i] == 'R'){
      if(i == 0) r[0][0] = 1;
      else{
        r[i][0] = r[i-1][1]+1;
        r[i][1] = r[i-1][0];
        r[i-1][1] = r[i-1][0] = 0;
      }  
    }else if(s[i] == 'L'){
      continue;
    }
  }
  
  for(int i=n-1; i>=0; i--){
    if(s[i] == 'L'){
      if(i == n-1) l[n-1][0] = 1;
      else{
        l[i][0] = l[i+1][1]+1;
        l[i][1] = l[i+1][0];
        l[i+1][1] = l[i+1][0] = 0;
      }  
    }else if(s[i] == 'R'){
      continue;
    }
  }
  /*
  rep(i,n) cout << l[i][0] << " ";
  cout << endl;
  rep(i,n) cout << l[i][1] << " ";
  */
  vi ans(n,0);

  
  rep(i,n){
    rep(j,2){
      if(j == 0){
        ans[i] += r[i][j];
      }else{
        ans[i+1] += r[i][j];
      }
    }
  }
  rep(i,n){
    rep(j,2){
      if(j == 0){
        ans[i] += l[i][j];
      }else{
        ans[i-1] += l[i][j];
      }
    }
  }
  
  rep(i,n) cout << ans[i] << endl;
  return 0;
}
