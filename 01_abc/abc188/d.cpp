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
  int n; ll C; cin >> n >> C;
  vector<tuple<ll,ll,ll> > t;
  rep(i,n){
    ll a,b,c; cin >> a >> b >> c;
    t.push_back(make_tuple(a,b,c));
  }
  sort(rng(t));
  ll iti = 1;
  ll tot = 0;
  ll ans = 0;
  priority_queue<pair<ll,ll>> pq; // 1次元目：終了位置（のマイナス）、2次元目：料金
  rep(i,n){
    ll a,b,c;
    tie(a,b,c) = t[i];
    pq.push(make_pair(-b,c));
    while(!pq.empty() && -pq.top().first<a){
      ll b2 = -pq.top().first, c2 = pq.top().second; pq.pop();
      if(tot>C){
        ans += C*(b2-iti+1);
      }else{
        ans += tot*(b2-iti+1);
      }
      iti = b2+1;
      tot -= c2;
    }
    if(tot>C){
      ans += C*(a-iti);
    }else{
      ans += tot*(a-iti);
    }
    tot += c;
    iti = a;
  }
  while(!pq.empty()){
    ll b2 = -pq.top().first, c2 = pq.top().second; pq.pop();
    if(tot>C){
      ans += C*(b2-iti+1);
    }else{
      ans += tot*(b2-iti+1);
    }
    iti = b2+1;
    tot -= c2;
  }
  cout << ans << endl;
  return 0;
}
