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

  ll ori = 10000000000;

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
    if(t[0] == '1'){
      cout << ori*2 << endl;
      return 0;
    }else{
      cout << ori << endl;
      return 0;
    }
  }else if(n == 2){
    if(t == "11") cout << ori << endl;
    else if(t == "10") cout << ori << endl;
    else cout << ori-1 << endl;
    return 0;
  }else if(n == 3){
    if(t == "110") cout << ori << endl;
    else if(t == "101") cout << ori-1 << endl;
    else cout << ori-1 << endl;
    return 0;
  }

  ll ans = 0;
  string ts = ""; ts += t[0]; ts += t[1];
  string te = ""; te += t[n-2]; te += t[n-1];
  if(ts == "11"){
    if(te == "10") ans = ori-n/3+1;
    else if(te == "01") ans = (3*ori-3)-(n-1)/3+1;
    else ans = ori-n/3;
  }else if(ts == "10"){
    if(n == 4) ans = ori-1;
    else{
      if(te == "10") ans = ori-n/3;
      else if(te == "01") ans = ori-n/3;
      else ans = ori-n/3;
    }
  }else{
    if(te == "10") ans = ori-n/3;
    else if(te == "01") ans = ori-n/3-1;
    else ans = ori-n/3;
  }
  cout << ans << endl;
  return 0;
}
