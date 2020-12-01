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
    vector<int> A;
    int q; cin >> q;
    rep(i,q){
        int query; cin >> query;
        if(query == 0){
            int x; cin >> x;
            A.push_back(x);
        }else if(query == 1){
            int p; cin >> p;
            cout << A[p] << endl;
        }else if(query == 2){
            A.pop_back();
        }
    }
}