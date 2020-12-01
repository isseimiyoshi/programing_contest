#include <bits/stdc++.h>
#define fi first
#define se second
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
#define v(T) vector<T>
#define vv(T) v(v(T))
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
int getInt(){int x;scanf("%d",&x);return x;}
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

const int MAX_N = 1010;
const int MAX_M = 2020;

int n;
vi to[MAX_N];
vp ans;
int ansv = -1;
map<P,int> mp;
int label[MAX_M];

void init(){
  rep(i,MAX_M) label[i] = 0;
}

void dfs(int u, set<int> s, vp ord, int now){
  if(s.count(u)){
    if(ansv<0){
      ansv = u;
      ans = ord;
    }else{
      if(u == 1) cout << "size " << ord.size() << endl;
      if((int)ans.size()>(int)ord.size()){
        ansv = u;
        ans = ord;
      }
    }
    return;
  }
  s.insert(u);
  ord.push_back(make_pair(now,u));
  for(int v: to[u]){
    if(label[mp[make_pair(u,v)]]) continue;
    label[mp[make_pair(u,v)]] = 1;
    dfs(v,s,ord,now+1);
  }
}

int main() {
  int m; cin >> n >> m;
  vi a(m), b(m);
  rep(i,m) cin >> a[i] >> b[i],--a[i],--b[i], mp[make_pair(a[i],b[i])] = i;

  rep(i,m) to[a[i]].push_back(b[i]);

  init();
  set<int> s;
  vp ord;
  dfs(0,s,ord,0);

  if(ansv<0) cout << -1 << endl;
  else{
    bool out = false;
    vi res;
    sort(rng(ans));
    for(auto ansp: ans){
      int u = ansp.second;
      if(u == ansv) out = true;
      if(out) res.push_back(u);
    }
    sort(rng(res));
    cout << res.size() << endl;
    for(int re: res) cout << re+1 << endl;
  }
  return 0;
}
