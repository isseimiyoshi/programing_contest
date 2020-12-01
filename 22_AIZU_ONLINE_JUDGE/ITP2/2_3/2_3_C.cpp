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
*/

int count_n(vector<ll> A, int b, int e, int k){
    int cnt = 0;
    for(int i=b; i<e; i++){
        if(A[i] == k) cnt++;
    }
    return cnt;
}

int main()
{
    int n; cin >> n;
    vector<ll> A(n);
    rep(i,n){
        ll Ai; cin >> Ai;
        A[i] = Ai;
    }
    int q; cin >> q;
    rep(i,q){
        int b, e, k; cin >> b >> e >> k;
        cout << count_n(A, b, e, k) << endl;
    }
}