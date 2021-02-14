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
#include <atcoder/all>
using namespace atcoder;
const int MX = 200005;

const int MAX_A = 400100;

int main() {
  int n; cin >> n;
  vi a(n),b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
    --a[i],--b[i];
  }
  set<int> s;
  vi cnt(MAX_A,0);
  rep(i,n){
    cnt[a[i]]++;
    cnt[b[i]]++;
    s.insert(a[i]);
    s.insert(b[i]);
  }
  priority_queue<pair<int,int> > color_cnt;
  for(auto si: s){
    color_cnt.push(make_pair(-cnt[si],si));
    // printf("%d %d\n",-cnt[si],si);
  }
  // sort(rng(color_cnt));
  vector<priority_queue<pair<int,int> >> pq(MAX_A);
  rep(i,n){
    pq[a[i]].push(make_pair(cnt[b[i]],i));
    pq[b[i]].push(make_pair(cnt[a[i]],i));
  }

  vector<bool> isfin(n,false);
  set<int> ans;
  
  while(!color_cnt.empty()){
    int cnti = -color_cnt.top().first;
    int color = color_cnt.top().second;
    // printf("%d %d\n",cnti,color);
    color_cnt.pop();
    
    if(pq[color].empty()) continue;
    while(!pq[color].empty()){
      int aikata = pq[color].top().first;
      int id = pq[color].top().second;
      if(isfin[id]){
        pq[color].pop();
        continue;
      }
      ans.insert(color);
      isfin[id] = true;
      pq[color].pop();
      break;
    }
    
  }
  for(auto res: ans) cout << res << " ";
  cout << endl;
  // for(auto si: s) printf("%d %d\n",si,cnt[si]);
  return 0;
}
