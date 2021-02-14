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
  vi a(n);
  rep(i,n) cin >> a[i], --a[i];

  map<int,int> m;
  rep(i,n) m[a[i]] = i;

  bool isex[n-1];
  rep(i,n-1) isex[i] = false;

  bool isok = true;

  rep(i,n) if(a[i] == i){
    cout << -1 << endl;
    return 0;
  }

  vi ans;
  int cnt = 0;
  rep(i,n){
    while(true){
      int exi = m[i];
      if(exi == i) break;
      else if(exi > i){
        if(isex[exi-1]) isok = false;
        swap(m[a[exi-1]], m[a[exi]]);
        swap(a[exi-1], a[exi]);
        isex[exi-1] = true;
        ans.push_back(exi-1);
        cnt++;
      }else{
        if(isex[exi]) isok = false;
        swap(m[a[exi+1]], m[a[exi]]);
        swap(a[exi+1], a[exi]);
        isex[exi] = true;
        ans.push_back(exi-1);
        cnt++;
      }
    }
    if(cnt == n-1) break;
    if(isok == false) break;
  }

  // printf("cnt: %d\n", cnt);

  if(!isok) cout << -1 << endl;
  else{
    if(cnt != n-1) cout << -1 << endl;
    else{
      bool isok2 = true;
      rep(i,n) if(i != a[i]) isok2 = false;
      if(isok2){
        for(auto res: ans) cout << res+1 << endl;
      }else{
        cout << -1 << endl;
      }
    }
  }
  return 0;
}
