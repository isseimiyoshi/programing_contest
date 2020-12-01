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
  int n, k; cin >> n >> k;
  vi c(n),r(n);
  rep(i,n){
    cin >> c[i] >> r[i];
  }

  vi a(k),b(k);
  rep(i,k){
    cin >> a[i] >> b[i];--a[i],--b[i];
  }

  vi to2[n];
  rep(i,k){
    to2[a[i]].push_back(b[i]);
    to2[b[i]].push_back(a[i]);
  }
  int dis2[n][n];
  rep(i,n){
    rep(j,n){
      dis2[i][j] = INF;
    }
    dis2[i][i] = 0;
  }
  rep(i,n){
    vi color2(n,0);
    queue<int> q;
    q.push(i);
    while(!q.empty()){
      int u = q.front(); q.pop();
      color2[u] = 1;
      for(int v: to2[u]){
        if(dis2[i][v] == INF && color2[v] == 0){
          dis2[i][v] = dis2[i][u]+1;
          q.push(v);
        }
      }
    }
  }

  vp to[n];
  rep(i,n){
    rep(j,n){
      if(dis2[i][j]<=r[i]) to[i].push_back(make_pair(j,c[i]));
    }
  }
  
  vi dis(n,INF);
  vi color(n,0);

  color[0] = 1;
  dis[0] = 0;
  priority_queue<P> pq;
  pq.push(make_pair(-dis[0], 0));
  while(!pq.empty()){
    int u = pq.top().second, disu = -pq.top().first;
    pq.pop();
    for(auto pv: to[u]){
      int v = pv.first, dv = pv.second;
      if(color[v] == 0 && dis[v]>disu+dv){
        dis[v] = disu+dv;
        pq.push(make_pair(-dis[v],v));
      }
    }
  }
  cout << dis[n-1] << endl;
  return 0;
}


