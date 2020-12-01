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
    vector<int> a, b;
    vector<int> sorta, sortb;
    rep(i,n){
        int ai, bi; cin >> ai >> bi;
        a.push_back(ai); sorta.push_back(ai);
        b.push_back(bi); sortb.push_back(bi);
    }

    sort(sorta.begin(), sorta.end());
    sort(sortb.begin(), sortb.end());

    int s, t;
    if(n % 2 == 0){
        s = (sorta[n/2] + sorta[n/2-1])/2;
        t = (sortb[n/2] + sortb[n/2-1])/2;
    }else{
        s = sorta[n/2];
        t = sortb[n/2];
    }

    ll ans = 0;
    rep(i,n){
        ans += abs(s-a[i]);
        ans += abs(a[i]-b[i]);
        ans += abs(t-b[i]);
    }

    cout << ans << endl;

    return 0;
}