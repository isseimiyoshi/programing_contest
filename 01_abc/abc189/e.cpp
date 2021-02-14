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
  int n; cin >> n;
  vl x(n),y(n);
  rep(i,n) cin >> x[i] >> y[i];

  int m; cin >> m;
  vector<pair<int,ll> >  op(m);
  rep(i,m){
    int opi; cin >> opi;
    if(opi == 3 || opi == 4){
      ll p; cin >> p;
      op[i] = make_pair(opi,p);
    }else{
      op[i] = make_pair(opi,(ll)-1);
    }
  }
  int q; cin >> q;
  vector<pair<ll,ll> > ans(q);
  vector<tuple<int,int,int> > query(q);
  rep(i,q){
    int a,b; cin >> a >> b;
    query[i] = make_tuple(a,b,i);
  }
  sort(rng(query));
  int qi = 0;

  ll a11 = 1, a12 = 0, a21 = 0, a22 = 1;
  ll p1 = 0, p2 = 0;

  auto f = [&](int opi, int p){
    ll o_a11 = a11,o_a12 = a12,o_a21 = a21,o_a22 = a22;
    ll o_p1 = p1, o_p2 = p2;
    if(opi == 1){
      a11 = o_a21, a12 = o_a22, a21 = -o_a11, a22 = -o_a12;
      p1 = o_p2, p2 = -o_p1;
    }else if(opi == 2){
      a11 = -o_a21, a12 = -o_a22, a21 = o_a11, a22 = o_a12;
      p1 = -o_p2, p2 = o_p1;
    }else if(opi == 3){
      a11 = -o_a11, a12 = -o_a12, a21 = o_a21, a22 = o_a22;
      p1 = -p1+2*p, p2 = p2;
    }else{
      a21 = -o_a21, a22 = -o_a22;
      p2 = -p2+2*p;
    }
  };

  while(true){
    int a,b,qii;
    tie(a,b,qii) = query[qi];
    if(a == 0){
      ans[qii] = make_pair(x[b-1], y[b-1]);
    }else{
      break;
    }
    qi++;
  }

  rep(i,m){
    f(op[i].first, op[i].second);
    while(qi<q){
      int a,b,qii;
      tie(a,b,qii) = query[qi];
      if(a == i+1){
        ll x1 = a11*x[b-1] + a12*y[b-1] + p1;
        ll y1 = a21*x[b-1] + a22*y[b-1] + p2;
        ans[qii] = make_pair(x1, y1);
      }else{
        break;
      }
      qi++;
    } 
  }

  rep(i,q){
    auto res = ans[i];
    cout << res.first << " " << res.second << endl;
  }
 

  return 0;
}
