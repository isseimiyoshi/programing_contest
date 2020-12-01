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


int main() {
  int n,m,k,s; cin >>n>>m>>k>>s;
  int p,q;cin>>p>>q;

  vi c(k);
  rep(i,k) cin >> c[i], --c[i];
  sort(rng(c));
  int a[m], b[m];
  rep(i,m) cin >> a[i] >> b[i], --a[i],--b[i];


  vi to1[n+1];
  rep(i,m){
    to1[a[i]].push_back(b[i]);
    to1[b[i]].push_back(a[i]);
  }
  rep(i,k){
    to1[n].push_back(c[i]);
    to1[c[i]].push_back(n);
  }

  vi color(n+1,0);
  vi dis(n+1,INF);
  dis[n] = 0;
  queue<int> qu; qu.push(n);
  while(!qu.empty()){
    int u = qu.front(); qu.pop();
    color[u] = 1;
    for(int v: to1[u]){
      if(color[v] == 0 && dis[v]>dis[u]+1){
        dis[v] = dis[u]+1;
        qu.push(v);
      }
    }
  }
  /*
  rep(i,n+1) cout << dis[i] << " ";
  cout << endl;

  cout << "ok" << endl;
  */

  vp to[n];
  rep(i,m){
    if(k == 0){
      to[b[i]].push_back(make_pair(a[i], p));
      to[a[i]].push_back(make_pair(b[i], p));
      continue;
    }

    if(upper_bound(rng(c),a[i]) - lower_bound(rng(c),a[i]) || upper_bound(rng(c),b[i]) - lower_bound(rng(c),b[i])) continue;

    if(a[i] == n-1) to[b[i]].push_back(make_pair(a[i], 0));
    else if(dis[a[i]] <= s+1) to[b[i]].push_back(make_pair(a[i], q));
    else to[b[i]].push_back(make_pair(a[i], p));

    if(b[i] == n-1) to[a[i]].push_back(make_pair(b[i], 0));
    else if(dis[b[i]] <= s+1) to[a[i]].push_back(make_pair(b[i], q));
    else to[a[i]].push_back(make_pair(b[i], p));
  }

  // cout << "ok2" << endl;

  vl dis2(n,INF);
  vi color2(n,0);
  dis2[0] = 0;
  color2[0] = 1;
  priority_queue<pair<ll,int> > pq;
  pq.push(make_pair(-dis2[0], 0));
  while(!pq.empty()){
    int u = pq.top().second; ll disu = -pq.top().first;
    pq.pop();
    color2[u] = 1;
    for(auto pv: to[u]){
      int v = pv.first; ll dv = pv.second;
      if(color2[v] == 0 && dis2[v]>disu+dv){
        dis2[v] = disu+dv;
        pq.push(make_pair(-dis2[v],v));
      }
    }
  }

  // cout << "ok3" << endl;

  cout << dis2[n-1] << endl;
  return 0;
}
