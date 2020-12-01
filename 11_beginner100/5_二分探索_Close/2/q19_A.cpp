#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

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

int main()
{
    int d, n, m; cin >> d >> n >> m;
    vector<int> s;
    s.push_back(0);
    s.push_back(d);
    rep(i,n-1){
        int di; cin >> di;
        s.push_back(di);
    }
    vector<int> k(m);
    rep(i,m) cin >> k[i];

    sort(s.begin(), s.end());

    ll ans = 0;
    rep(i,m){
        
        auto itr = lower_bound(s.begin(), s.end(), k[i]);
        auto itr2 = itr;
        --itr;
        ans += min((*itr2)-k[i], k[i]-(*itr));
        // printf("%d %d\n", *itr2,*itr);
    }
    cout << ans << endl;
}