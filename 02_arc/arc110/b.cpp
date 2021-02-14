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
  string t; cin >> t;
  string s = "110";

  int bai = 1;
  
  
  if(t[0] == '1' && t[1] == '1'){
    for(int i=2; i<n; i++){
      if(s[i%3] == t[i]){
        continue;
      }else{
        cout << 0 << endl;
        return 0;
      }
    }
  }else if(t[0] == '1' && t[1] == '0'){
    for(int i=2; i<n; i++){
      if(s[(i+1)%3] == t[i]){
        continue;
      }else{
        cout << 0 << endl;
        return 0;
      }
    }
  }else{
    for(int i=1; i<n; i++){
      if(s[(i-1)%3] == t[i]){
        continue;
      }else{
        cout << 0 << endl;
        return 0;
      }
    }
  }

  if(n == 1){
    if(t[0] == 1){
      cout << 20000000000 << endl;
      return 0;
    }else{
      cout << 10000000000 << endl;
      return 0;
    }
  }else if(n == 2){
    if(t == "11") cout << 10000000000 << endl;
    else if(t == "10") cout << 10000000000 << endl;
    else cout << 10000000000-1 << endl;
    return 0;
  }else if(n == 3){
    if(t == "110") cout << 10000000000 << endl;
    else if(t == "101") cout << 10000000000-1 << endl;
    else cout << 10000000000-1 << endl;
  }

  ll ori = 3*10000000000;
  int st = 0;
  if(t[0] == '1' && t[1] == '1'){
    st = 0;
  }else if(t[0] == '1' && t[1] == '0'){
    st = 2;
  }else{
    st = 1;
  }
  ori -= st;
  int ed = 0;
  if(t[n-2] == '1' && t[n-1] == '1'){
    ed = 2;
  }else if(t[n-2] == '0' && t[n-1] == '1'){
    ed = 1;
  }else{
    ed = 0;
  }
  ori -= ed;
  n -= st;
  n -= ed;

  // cout << st << endl;
  // cout << ed << endl;
  ll ans;
  if(n == 0){
    ans = 10000000000-1;
  }else{
    if(st == 0 && ed == 0) ans = 10000000000-n/3+1;
    if(st == 0 || ed == 0) ans = 10000000000-n/3;
    else ans = 10000000000-n/3-1;
  }
  
  cout << ans*bai << endl;
  return 0;
}
