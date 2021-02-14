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

const ll MAX_N = 1000;

int main() {
  ll x; cin >> x;
  ll n5[2*MAX_N+1];
  
  for(ll i=-MAX_N; i<=MAX_N; i++){
    n5[i+MAX_N] = pow(i,5);
  }
  bool isok = false;
  int a = -1, b = -1;
  for(ll i=-MAX_N; i<=MAX_N; i++){
    for(ll j=-MAX_N; j<=MAX_N; j++){
      if(n5[i+MAX_N]-n5[j+MAX_N] == x){
        a = i;
        b = j;
        isok = true;
        break;
      }
    }
  }
  if(isok) printf("%d %d\n",a,b);
  else cout << -1 << endl;
  //rep(i,2*MAX_N+1) cout << n5[i] << endl;
  return 0;
}
