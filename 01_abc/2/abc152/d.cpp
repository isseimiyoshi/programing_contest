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

int f(int n){
  while(n>=10){
    n /= 10;
  }
  return n;
}

int keta(int n){
  int cnt = 0;
  while(n>0){
    cnt++;
    n /= 10;
  }
  return cnt;
}

int main() {
  int n; cin >> n;
  int frtn = f(n);
  int endn = n%10;
  int kn = keta(n);
  ll ans = 0;

  if(n<10){
    cout << n << endl;
    return 0;
  }
  // cout << "ok" << endl;

  for(int a=1; a<=n; a++){
    int frta = f(a);
    int enda = a%10;
    int ka = keta(a);
    if(enda == 0) continue;
    int frtb = enda;
    int endb = frta;

    int bet = 0;
    while(true){
      if(frtb == endb && bet == 0){
        if(frtb<=n) ans++;
        bet++;
        continue;
      }
      if(bet == 0){ bet++; continue; }

      int tgt;
      tgt = frtb*pow(10,bet) + endb;
      for(int i=1;i<bet; i++){
        tgt += 9*pow(10,i);
      }

      // printf("bet:%d tgt:%d\n",bet,tgt);
      if(tgt<=n){
        ans += pow(10,bet-1);
      }else{
        if(frtb == frtn && endb == endn){
          int add = n;
          add -= frtn*pow(10,kn);
          add /= 10;
          ans += add;
          // cout << "yes" << endl;
        }
        break;
      }
      bet++;
    }
  }
  cout << ans << endl;
  return 0;
}
