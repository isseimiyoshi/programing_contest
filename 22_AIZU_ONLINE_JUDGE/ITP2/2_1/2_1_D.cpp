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
    vector<int> A[n];
    int q; cin >> q;
    rep(i,q){
        int query; cin >> query;
        if(query == 0){
            int t, x; cin >> t >> x;
            A[t].push_back(x);
        }else if(query == 1){
            int t; cin >> t;
            rep(j,A[t].size()){
                cout << A[t][j];
                if(j != A[t].size()-1) cout << " ";
            }
            cout << endl;
        }else{
            int t; cin >> t;
            A[t].clear();
        } 
    }
}