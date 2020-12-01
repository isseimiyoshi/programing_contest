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
    int n; cin >> n;
    int x[n], y[n];
    rep(i,n) cin >> x[i] >> y[i];

    vector<ll> v1;
    vector<ll> v2;
    rep(i,n){
        v1.push_back(x[i]+y[i]);
        v2.push_back(x[i]-y[i]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    cout << max(v1[n-1]-v1[0], v2[n-1]-v2[0]) << endl;
}