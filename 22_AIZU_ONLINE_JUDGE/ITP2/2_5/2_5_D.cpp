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
    vector<int> A;
    rep(i,n){
        A.push_back(i+1);
    }
    sort(A.begin(), A.end());
    do{
        rep(i,n){
            cout << A[i];
            if(i != n-1) cout << " ";
        }
        cout << endl;
    }while(next_permutation(A.begin(), A.end()));
}