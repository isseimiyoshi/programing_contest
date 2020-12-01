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

// hが奇数の時
const int moveh_o[6] = {-1,-1,0,1,1,0};  
const int movew_o[6] = {0,1,1,1,0,-1};

// hが偶数の時
const int moveh_e[6] = {-1,-1,0,1,1,0};  
const int movew_e[6] = {-1,0,1,0,-1,-1};


int main() {
  int w, h; cin >> w >> h;
  int c[h+6][w+6];
  rep(i,h+6) rep(j,w+6) c[i][j] = 0;
  rep(i,h) rep(j,w) cin >> c[i+3][j+3];

  /*
  rep(i,h){
    rep(j,w){
      int cnt = 0;
      rep(k,6){
        int nh,nw;
        if((i+1)%2 == 0) nh = i+moveh_e[k], nw = j+movew_e[k];
        else nh = i+moveh_o[k], nw = j+movew_o[k];

        if(nh<0||nw<0||nh>=h||nw>=w) continue;
        if(c[nh][nw] == 1) cnt++;
      }
      if(cnt == 6) c[i][j] = 1;
    }
  }
  */



  queue<P> q;
  q.push(make_pair(2,2));
  c[2][2] = INF;

  while(!q.empty()){
    int uh = q.front().first;
    int uw = q.front().second;
    q.pop();
    rep(k,6){
      int nh,nw;
      if((uh+1)%2 == 1) nh = uh+moveh_e[k], nw = uw+movew_e[k];
      else nh = uh+moveh_o[k], nw = uw+movew_o[k];

      if(nh<0||nw<0||nh>=h+6||nw>=w+6) continue;
      if(c[nh][nw] == 0){
        c[nh][nw] = INF;
        q.push(make_pair(nh,nw));
      }
    }
  }

  rep(i,h+6){
    rep(j,w+6){
      if(c[i][j] == 0) c[i][j] = 1;
    }
  }

  int ans = 0;
  rep(i,h+6){
    rep(j,w+6){
      if(c[i][j] == INF) continue;
      int cnt = 0;
      rep(k,6){
        int nh,nw;
        if((i+1)%2 == 1) nh = i+moveh_e[k], nw = j+movew_e[k];
        else nh = i+moveh_o[k], nw = j+movew_o[k];

        if(nh<0||nw<0||nh>=h+6||nw>=w+6) continue;
        if(c[nh][nw] != INF) cnt++;
      }
      ans += (6-cnt);
    }
  }
  
  cout << ans << endl;
  return 0;
}
