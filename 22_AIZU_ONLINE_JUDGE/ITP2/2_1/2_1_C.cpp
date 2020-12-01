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
    int q; cin >> q;
    vector<int> A = {100};
    auto itr = A.begin();
    rep(i,q){
        int query; cin >> query;
        if(query == 0){
            int x; cin >> x;
            A.insert(itr, x);
        }else if(query == 1){
            int d; cin >> d;
            if(d > 0) rep(j,d) itr++;
            else rep(j,(-1)*d) itr--; 
        }else if(query == 2){
            A.erase(itr);
        }
    }
    rep(i,A.size()-1) cout << A[i] << endl;
}