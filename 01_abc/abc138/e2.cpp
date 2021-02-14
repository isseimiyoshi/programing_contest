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
  string s,t; cin >> s >> t;
  map<char,vi> m;
  int sn = s.size();
  int tn = t.size();
  rep(i,sn){
    m[s[i]].push_back(i);
  }

  /*
  for(char c='a'; c<='z'; c++){
    cout << c << " ";
    for(auto i: m[c]){
      cout << i << " ";
    }
    cout << endl;
  }
  */
  int ans = 0;
  int ti = 0;

  map<char,int> tm;
  auto init = [&](){
    for(char c='a'; c<='z'; c++) tm[c] = 0;
  };
  init();

  while(ti<tn){
    char cti = t[ti];
    
    if(m[cti].size() == 0){
      ans = -1;
      break;
    }

    if(ti == 0){
      ans += m[cti][tm[cti]]+1;
      tm[cti]++;
      ti++;
      continue;
    }


    char cti_m1 = t[ti-1];
    int nowi = (int)m[cti][tm[cti]];
    int orii = m[cti_m1][tm[cti_m1]-1];
    if(m[cti].size()<=tm[cti]){
      init();
      nowi = (int)m[cti][tm[cti]];
    }
    if(nowi>orii){
      ans += nowi-orii;
    }else{
      ans += sn-orii-1;
      ans += nowi+1;
      init();
    }
    // printf("ans: %d, ti: %c\n", ans, cti);
    // cout << "nowi: " << nowi << endl;
    // cout << "nowi: " << (int)m[cti][tm[cti]] << endl;
    tm[cti]++;
    ti++;
  }
  cout << ans << endl;
  return 0;
}
