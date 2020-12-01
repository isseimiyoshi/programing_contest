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

const int moh[4] = {-1,0,1,0};
const int mow[4] = {0,1,0,-1};

int main() {
  vi ans;
  while(true){
    int w,h; cin >> w >> h;
    if(w == 0 && h == 0) break;

    vi c[2*h-1];
    rep(i,2*h-1){
      if(i%2 == 0){
        rep(_,w-1){
          int cij; cin >> cij; c[i].push_back(cij);
        }
      }else{
        rep(_,w){
          int cij; cin >> cij; c[i].push_back(cij); 
        }
      }
    }
    
    int dis[h][w];
    rep(i,h) rep(j,w) dis[i][j] = INF;

    queue<P> q;
    q.push(make_pair(0,0));
    dis[0][0] = 0;

    while(!q.empty()){
      int uh = q.front().first;
      int uw = q.front().second;
      q.pop();
      rep(i,4){
        int vh = uh+moh[i];
        int vw = uw+mow[i];
        if(vh<0||vw<0||vh>=h||vw>=w) continue;
        if(moh[i] == 1) if(c[uh*2+1][uw] == 0 && dis[vh][vw] == INF) dis[vh][vw] = dis[uh][uw]+1, q.push(make_pair(vh,vw));
        if(moh[i] == -1) if(c[uh*2-1][uw] == 0 && dis[vh][vw] == INF) dis[vh][vw] = dis[uh][uw]+1, q.push(make_pair(vh,vw));
        if(mow[i] == 1) if(c[uh*2][uw] == 0 && dis[vh][vw] == INF) dis[vh][vw] = dis[uh][uw]+1, q.push(make_pair(vh,vw));
        if(mow[i]==-1) if(c[uh*2][uw-1] == 0 && dis[vh][vw] == INF) dis[vh][vw] = dis[uh][uw]+1, q.push(make_pair(vh,vw));
      }
    }

    if(dis[h-1][w-1] == INF) ans.push_back(0);
    else ans.push_back(dis[h-1][w-1]+1);
  }

  for(auto res: ans) cout << res << endl;
  return 0;
}
