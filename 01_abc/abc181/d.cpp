#include <bits/stdc++.h>
#define fi first
#define se second
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
int getInt(){int x;scanf("%d",&x);return x;}
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
  string s; cin >> s;
  int n = s.size();

  if(n==1){
    if(s == "8") cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
  }else if(n == 2){
    int s0 = s[0]-'0';
    int s1 = s[1]-'0';
    if((s0*10+s1)%8 == 0 || (s1*10+s0)%8 == 0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
    return 0;
  }

  bool isok = false;
  for(int i=111; i<1000; i++){
    if(i%8 == 0 && i%10 != 0 && (i/10)%10 != 0){
      int i100 = i/100;
      int i10 = (i/10)%10;
      int i1 = i%10;
      
      bool isok1 = false;
      bool isok2 = false;
      bool isok3 = false;

      /*
      if(i == 432){
        cout << i100 << " " << i10 << " " << i1 << endl;
      }
      */

      rep(j,n){
        int si = s[j]-'0';
        if(si == i100 && !isok1){
          isok1 = true;
          continue;
        }else if(si == i10 && !isok2){
          isok2 = true;
          continue;
        }else if(si == i1 && !isok3){
          isok3 = true;
          continue;
        }
      }
      if(isok1 && isok2 && isok3){
        isok = true;
      }
    }
  }
  if(isok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
