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

const int MAX_N = 100100;

int main() {
  bool isprime[MAX_N];
  rep(i,MAX_N) isprime[i] = true;
  isprime[0] = isprime[1] = false;
  int i=2;
  while(i<MAX_N){
    i += 2;
    isprime[i] = false;
  }
  for(int i=3; i<MAX_N; i+=2){
    if(!isprime[i]) continue;
    int j = i+i;
    while(j<MAX_N){
      isprime[j] = false;
      j += i;
    }
  }

  int rui[MAX_N];
  rui[0] = rui[1] = rui[2] = 0;
  for(int i=2; i<MAX_N; i++){
    if(i%2 == 0){
      rui[i] = rui[i-1];
      continue;
    }
    if(isprime[i] && isprime[(i+1)/2]) rui[i] = rui[i-1]+1;
    else rui[i] = rui[i-1];
  }

  int q;cin>>q;
  vi ans;
  rep(_,q){
    int l,r; cin >> l >> r;
    int res = rui[r]-rui[l-1];
    ans.push_back(res);
  }
  for(int res: ans){
    cout << res << endl;
  }

  return 0;
}
