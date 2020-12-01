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

int main()
{
    int n; cin >> n;
    set<int> A;
    rep(i,n){
        int Ai; cin >> Ai;
        A.insert(Ai);
    }
    int m; cin >> m;
    set<int> B;
    rep(i,m){
        int Bi; cin >> Bi;
        B.insert(Bi);
    }
    bool is = true;
    for(auto Bi: B){
        if(A.count(Bi) == 0){
            is = false;
            break;
        }
    }
    if(is) cout << 1 << endl;
    else cout << 0 << endl;
}