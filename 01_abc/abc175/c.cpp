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
    ll x, k, d; cin >> x >> k >> d;
    if(abs(x) / d >= k){
        cout << abs(x)-d*k << endl;
    }else{
        // cout << min(abs(x)%d, (d-abs(x)%d)) << endl;
        int ama = (abs(x) / d) % 2;
        if(k%2 == ama) cout << abs(x)%d << endl;
        else cout << (d-abs(x)%d) << endl;
    }
}