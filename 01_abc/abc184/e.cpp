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

const int mh[4] = {0,1,0,-1};
const int mw[4] = {1,0,-1,0};

int main() {
  int h,w; cin >> h >> w;
  set<char> s;
  map<char,vp> mp;
  // for(char moji='a'; moji<='z'; moji++) mp
  P start;
  P goal;
  int m[h][w];
  char a[h][w];
  rep(i,h){
    rep(j,w){
      char moji; cin >> moji;
      a[i][j] = moji;
      if(moji == '#') m[i][j] = 1;
      else{
        m[i][j] = 0;
        if(moji == 'S') start.first = i, start.second = j;
        else if(moji == 'G') goal.first = i, goal.second = j;
        else if(moji != '.'){
          if(s.count(moji)) mp[moji].push_back(make_pair(i,j));
          else s.insert(moji), mp[moji].push_back(make_pair(i,j));
        }
      }
    }
  }

  map<char,bool> label;
  for(char si: s) label[si] = false;

  vector<vector<int> > dist(h, vector<int>(w,INF));
  dist[start.first][start.second] = 0;
  queue<P> q;
  q.push(make_pair(start.first, start.second));

  while(!q.empty()){
    int uh = q.front().first, uw = q.front().second; q.pop();
    rep(i,4){
      int vh = uh+mh[i], vw = uw+mw[i];
      if(vh<0 || vw<0 || vh>=h || vw>=w) continue;
      if(m[vh][vw] == 1) continue;
      if(dist[vh][vw]>dist[uh][uw]+1){
        dist[vh][vw] = dist[uh][uw]+1;
        q.push(make_pair(vh,vw));
        if(a[vh][vw] == '.' || a[vh][vw] == 'S' || a[vh][vw] == 'G') continue;
        if(label[a[vh][vw]]) continue;
        for(auto vp: mp[a[vh][vw]]){
          int vh2 = vp.first, vw2 = vp.second;
          if(dist[vh2][vw2] > dist[vh][vw]+1){
            dist[vh2][vw2] = dist[vh][vw]+1;
            q.push(make_pair(vh2,vw2));
          }
        }
        label[a[vh][vw]] = true;
      }
    }
  }

  if(dist[goal.first][goal.second] == INF) cout << -1 << endl;
  else cout << dist[goal.first][goal.second] << endl;
  return 0;
}
