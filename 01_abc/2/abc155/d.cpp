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
  ll n,k; cin >> n >> k;
  vl a(n);
  rep(i,n) cin >> a[i];

  ll cnt0 = 0;
  vl mns, pls;
  rep(i,n){
    if(a[i] == 0) cnt0 += 1;
    else if(a[i]>0) pls.push_back(a[i]);
    else mns.push_back(a[i]);
  }
  sort(rng(mns));
  sort(rng(pls));
  ll mns_n = mns.size(), pls_n = pls.size();

  // 積がゼロになるペアの個数を求める
  ll cnt1 = 0;
  cnt1 += cnt0*(mns_n+pls_n);
  cnt1 += cnt0*(cnt0-1)/2;

  ll cnt2 = mns_n*pls_n;


  auto f = [&](ll m){
    ll res = 0;
    for(ll mnsi: mns){
      mnsi *= -1;
      res += distance(pls.begin(),upper_bound(rng(pls),m/mnsi));
    }
    return res;
  };

  auto f2 = [&](ll m){
    ll res = 0;
    if(mns_n != 1){
      for(auto itr=mns.begin(); itr!=mns.end(); itr++){
        ll now = distance(itr,upper_bound(rng(mns),m/(*itr)));
        if(upper_bound(rng(mns),m/(*itr)) == mns.end()) now--;
        res += max(now,(ll)0);
      }
    }
    if(pls_n != 1){
      for(auto itr=pls.begin(); itr!=pls.end(); itr++){
        ll now = distance(itr,upper_bound(rng(pls),m/(*itr)));
        if(upper_bound(rng(pls),m/(*itr)) == pls.end()) now--;
        res += max(now,(ll)0);
      }
    }
    // printf("res: %d\n",res);
    return res;
  };

  if(k<=cnt2){  // k番目の値はマイナスになる
    ll l=0,r=LINF;
    while(l+1<r){
      ll m = (l+r)/2;
      if(f(m)>cnt2-k) r = m;
      else l = m+1;
    }
    cout << -l << endl;
  }else if(k<=cnt1+cnt2){
    cout << 0 << endl;
    // printf("%d %d %d\n",cnt1,mns_n,pls_n);
  }else{
    k = k-cnt1-cnt2;

    rep(i,mns_n) mns[i] *= (ll)-1;
    sort(rng(mns));

    // cout << k << endl;
    ll l=0,r=LINF;
    while(l+1<r){
      ll m = (l+r)/2;
      if(f2(m)>k) r = m;
      else l = m+1;
    }
    cout << l << endl;
  }

  return 0;
}

/*

10 10
5 4 3 2 -1 0 0 0 0 0

30 15
-170202098 -268409015 537203564 983211703 21608710 -443999067 -937727165 -97596546 -372334013 398994917 -972141167 798607104 -949068442 -959948616 37909651 0 886627544 -20098238 0 -948955241 0 -214720580 277222296 -18897162 834475626 0 -425610555 110117526 663621752 0


*/
