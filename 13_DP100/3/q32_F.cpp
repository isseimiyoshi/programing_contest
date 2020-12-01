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
  vl book[10];
  rep(i,n){
    int c,g; cin >> c >> g; --g;
    book[g].push_back(c);
  }
  rep(i,10){
    sort(rrng(book[i]));
  }
  vl book2;
  rep(i,10){
    int bn1 = book[i].size();
    int now = 0;
    rep(j,bn1){
      book2.push_back(book[i][j]+(j+1)*j-now);
      now = (j+1)*j;
    }
  }
  ll dp[n+1][k+1];
  rep(i,n+1) rep(j,k+1) dp[i][j] = 0;
  rep(i,n){
    rep(j,k+1){
      if(j<1) dp[i+1][j] = dp[i][j];
      else{
        dp[i+1][j] = max(dp[i][j], dp[i][j-1]+book2[i]);
      }
    }
  }
  cout << dp[n][k] << endl;
  return 0;
}

/*

7 4
14 1
13 2
12 3
14 2
8 2
16 3
11 2

*/
