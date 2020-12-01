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
    vector<int> A;
    int cursor = 0;
    rep(i,q){
        int query; cin >> query;
        if(query == 0){
            int x; cin >> x;
            A.push_back(x);
            swap(A[A.size()-1], A[cursor]);
        }else if(query == 1){
            int d; cin >> d;
            cursor += d;
        }else if(query == 2){
            A.erase(A.begin()+cursor);
        }
    }
    rep(i,A.size()-1) cout << A[i] << endl;
}