#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const int INF = 1000100100;

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A';

/*
string s = "abcdefg"
s.substr(4) "efg"
s.substr(0,3) "abc"
s.substr(2,4) "cdef"

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

const int MAX_N = 100050;

int n, m;
vector<int> to[MAX_N];

ll dp[MAX_N];

void init(){
    rep(i,MAX_N){
        dp[i] = -1;
    }
}

ll f(int x, int p){
    if(dp[x]>=0) return dp[x];

    ll res = 0;
    for(int y: to[x]){
        if(y == p) continue;
        res = max(res, f(y,x) + 1);
    }
    return dp[x] = res;
}

int main()
{
    cin >> n >> m;
    rep(i,m){
        int xi, yi; cin >> xi >> yi;
        --xi, --yi;
        to[xi].push_back(yi);
    }

    init();

    ll ans = 0;
    rep(i,n){
        ans = max(ans, f(i,-1));
    }

    cout << ans << endl;

}