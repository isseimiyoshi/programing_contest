#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
using P = pair<ll, ll>;

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

const int A = 1000005;


int main()
{
    int n; cin >> n;
    vector<int> a(n);
    vector<int> c(A);   // Aまでの各数字が配列で何回出現したかをメモするための配列
    rep(i,n){
        cin >> a[i];
        c[a[i]]++;
    }

    bool pairwise = true;
    for(int i=2; i<A; i++){ // Aまでの数字を確かめる
        int cnt = 0;
        for(int j=i; j<A; j+=i){
            cnt += c[j];
        }
        if(cnt > 1) pairwise = false;
    }

    bool setwise = false;
    int g = 0;  // 0とその他の数字の最大公約数はその他の数字になる
    rep(i,n) g = __gcd(g, a[i]);
    if(g == 1) setwise = true;

    if(pairwise) cout << "pairwise coprime" << endl;
    else if(setwise) cout << "setwise coprime " << endl;
    else cout << "not coprime" << endl;
}