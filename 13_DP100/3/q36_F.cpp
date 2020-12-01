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

int keta(ll n){
  int cnt = 0;
  while(n != 0){
    n /= 10;
    cnt++;
  }
  return cnt;
}

int main() {
  ll a, b; cin >> a >> b; --a;
  int an = keta(a);
  int bn = keta(b);
  
  
  ll dpa[an+1][2][2][2];
  rep(i,an+1) rep(j,2) rep(k,2) rep(l,2) dpa[i][j][k][l] = 0;
  dpa[0][0][0][0] = 1;
  rep(i,an) rep(j,2) rep(k,2) rep(l,2) { 
    int lim = j ? 9 : (a/(ll)pow(10,an-1-i))%10;
    rep(d,lim+1){
      dpa[i+1][j||d<lim][k || d == 4][l || d == 9] += dpa[i][j][k][l];
    }
  }

  ll dpb[bn+1][2][2][2];
  rep(i,bn+1) rep(j,2) rep(k,2) rep(l,2) dpb[i][j][k][l] = 0;
  dpb[0][0][0][0] = 1;
  rep(i,bn) rep(j,2) rep(k,2) rep(l,2) { 
    int lim = j ? 9 : (b/(ll)pow(10,bn-1-i))%10;
    rep(d,lim+1){
      dpb[i+1][j||d<lim][k || d == 4][l || d == 9] += dpb[i][j][k][l];
    }
  }

  ll ansa = 0;
  rep(j,2) rep(k,2) rep(l,2){
    if(k || l) ansa += dpa[an][j][k][l];
  }
  ll ansb = 0;
  rep(j,2) rep(k,2) rep(l,2){
    if(k || l) ansb += dpb[bn][j][k][l];
  }
  
  cout << ansb-ansa << endl;
  return 0;
}
