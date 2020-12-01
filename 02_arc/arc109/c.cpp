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
  int n,k; cin >> n >> k;
  string s; cin >> s;
  
  if(n%2 == 1) s += s;

  auto f = [&](char s1, char s2){
    char ans = 'N';
    if(s1 == s2) ans = s1;
    if((s1 == 'P' && s2 == 'R') || (s1 == 'R' && s2 == 'P')) ans = 'P';
    if((s1 == 'P' && s2 == 'S') || (s1 == 'S' && s2 == 'P')) ans = 'S';
    if((s1 == 'S' && s2 == 'R') || (s1 == 'R' && s2 == 'S')) ans = 'R';
    return ans;
  };

  while(k > 0){
    string t =  "";
    int sn = s.size();
    rep(i,sn/2){
      t += f(s[2*i], s[2*i+1]);
    }
     t += t;
     s = t;
     k--;
  }
  cout << s[0] << endl;

  return 0;
}
