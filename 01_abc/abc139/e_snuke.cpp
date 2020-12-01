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
  int n; cin >> n;
  vector<vector<int> > a(n, vector<int>(n-1));
  rep(i,n){
    rep(j,n-1){
      cin >> a[i][j];
      --a[i][j];
    }
    reverse(rng(a[i])); // vector型は最後尾の要素を削除する方が操作が早いため
  }
  vp q;

  // ある日のある選手において、その選手がその日に行うことのできる試合があるかどうかをチェックする。
  //　行うことのできる試合がある場合　→　試合リスト（配列q）に試合を追加する
  auto check = [&](int i){
    if(a[i].size() == 0) return;
    int j = a[i].back();
    if(a[j].size() == 0) return;
    if(a[j].back() == i){ // もしお互いが対戦し合う予定になっていれば
      P p(i,j);
      if(p.first > p.second) swap(p.first, p.second);
      q.push_back(p);
    }
  };

  rep(i,n){
    check(i); // 初日に行われる試合をqにぶち込んでいる
  }

  int day = 0;
  while(q.size() > 0){
    day++;

    // ソートしてから2行目のコードを実行することによって、配列から重複を削除することができる
    sort(rng(q));
    q.erase(unique(rng(q)), q.end());

    vp prevQ;
    swap(prevQ, q); // 現在保持している配列を過去扱いにする
    for(P p: prevQ){
      int i = p.first, j = p.second;
      a[i].pop_back();
      a[j].pop_back();
    }
    for(P p: prevQ){
      int i = p.first, j = p.second;
      check(i);
      check(j);
    }
  }

  // 行われないままの試合がないかチェック、あった場合は日程実現不可能となる
  rep(i,n){
    if(a[i].size() != 0){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << day << endl;
  return 0;
}
