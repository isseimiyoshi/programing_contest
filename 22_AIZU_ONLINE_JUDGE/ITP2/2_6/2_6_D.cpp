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

int main()
{
    int n; cin >> n;
    vector<int> A;
    rep(i,n){
        int Ai; cin >> Ai;
        A.push_back(Ai);
    }
    int q; cin >> q;
    rep(i,q){
        int k; cin >> k;
        auto low_itr = lower_bound(A.begin(), A.end(), k);
        auto up_itr = upper_bound(A.begin(), A.end(), k);
        cout << distance(A.begin(), low_itr) << " " << distance(A.begin(), up_itr) << endl;
    }
}