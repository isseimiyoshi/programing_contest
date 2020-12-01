#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

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

ll floor(ll A, ll B, ll x){
    ll kou1 = (A * x) / B;
    ll kou2 = x / B;
    kou2 = kou2*A;
    ll ans = kou1 - kou2;
    return ans;
}

int main()
{
    ll A, B, N; cin >> A >> B >> N;
    ll max_n;
    if(N<B){
        cout << floor(A, B, N) << endl;
    }else{
        cout << floor(A, B, B-1) << endl;
    }
}