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
  vi ans;
  while(true){
    int h; cin >> h;
    if(h == 0) break;

    int res = 0;
    int m[h][5];
    rep(i,h){
      rep(j,5) cin >> m[h-1-i][j];
    }
    // 削除するブロックがなくなったら抜ける
    while(true){
      bool isch = false;
      rep(i,h){
        vi cnt(9,0);
        int t = -1;
        int ori = -1;
        rep(j,5){
          if(m[i][j] == 0) continue;
          if(ori == m[i][j]) cnt[m[i][j]-1]++;
          else{
            if(cnt[m[i][j]-1]>=3) continue;
            else cnt[m[i][j]-1] = 1;
            ori = m[i][j];
          }
        }
        rep(j,9){
          if(cnt[j]>=3){
            t = j+1;
            isch = true;
          }
        }
        if(t != -1) res += cnt[t-1]*t; 
        rep(j,5) if(m[i][j] == t) m[i][j] = 0;
      }

      if(!isch) break;

      rep(j,5){
        int cnt = 0;
        vi s;
        rep(i,h){
          if(m[i][j] != 0) s.push_back(m[i][j]), cnt++;
        }
        rep(i,cnt) m[i][j] = s[i];
        for(int i=cnt; i<h; i++) m[i][j] = 0;
      }
      /*
      rep(i,h){
        rep(j,5){
          cout << m[h-1-i][j] << " ";
        }cout << endl;
      }
      cout << endl;
      cout << res << endl;
      */
    }
    ans.push_back(res);
  }
  for(int res: ans) cout << res << endl;
  return 0;
}

/*

10
3 5 6 5 6
2 2 2 8 3
6 2 5 9 2
7 7 7 6 1
4 6 6 4 9
8 9 1 1 8
5 6 1 8 1
6 8 2 1 2
9 6 3 3 5
5 3 8 8 8
0

*/
