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
  ll a,b,c; cin >> a >> b >> c;
  vector<char> ans;
  bool isok = true;

  vector<string> s(n);
  rep(i,n) cin >> s[i];

  rep(i,n){
    if(s[i] == "AB"){
      if(a>b){
        ans.push_back('B');
        b++; a--;
      }else if(a<b){
        ans.push_back('A');
        a++; b--;
      }else{
        if(i == n-1){ a++, b--;ans.push_back('A');}
        else if(s[i+1] == "AC"){ a++; b--; ans.push_back('A');}
        else{ a--; b++; ans.push_back('B');}
      }
    }else if(s[i] == "AC"){
      if(a>c){
        ans.push_back('C');
        c++; a--;
      }else if(a<c){
        ans.push_back('A');
        a++; c--;
      }else{
        if(i == n-1){ a++, c--;ans.push_back('A');}
        else if(s[i+1] == "BC"){ a--; c++; ans.push_back('C');}
        else{ a++; c--; ans.push_back('A');}
      }
    }else{
      if(c>b){
        ans.push_back('B');
        b++; c--;
      }else if(c<b){
        ans.push_back('C');
        c++; b--;
      }else{
        if(i == n-1){ b++, c--;ans.push_back('B');}
        else if(s[i+1] == "AB"){ b++; c--; ans.push_back('B');}
        else{ b--; c++; ans.push_back('C');}
      }
    }
    if(a<0 || b<0 || c<0) isok = false;
    // printf("%d %d %d\n",a,b,c);
  }
  if(isok){
    cout << "Yes" << endl;
    for(auto res: ans) cout << res << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
