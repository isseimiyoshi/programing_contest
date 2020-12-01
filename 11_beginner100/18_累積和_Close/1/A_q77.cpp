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

const int MOD = 100000;

int main()
{
    int n, m; cin >> n >> m;
    int A[n]; A[0] = 0;
    rep(i,n-1) cin >> A[i+1];
    int S[n];
    rep(i,n){
        if(i == 0) S[0] = A[0];
        else S[i] = A[i] + S[i-1];
    }
    ll sum = 0;
    int ori_i = 0;
    rep(_,m){
        int ai; cin >> ai;
        sum += abs(S[ai+ori_i] - S[ori_i]);
        ori_i = ai+ori_i;
        sum %= MOD;
    }
    cout << sum << endl;
}