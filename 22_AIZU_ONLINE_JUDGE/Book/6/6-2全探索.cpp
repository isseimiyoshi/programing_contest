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

const int MAX_N = 20;
int A[MAX_N];
int n;

bool solve(int i, int m){
    if(m == 0) return true;
    if(i >= n) return false;
    bool res = solve(i+1, m) || solve(i+1, m-A[i]);
    return res;
}

int main()
{
    cin >> n;
    rep(i,n){
        cin >> A[i];
    }
    int q; cin >> q;
    rep(_,q){
        int m; cin >> m;
        if(solve(0,m)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}