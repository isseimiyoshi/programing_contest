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

void rotate(vector<int> &A, int b, int m, int e){
    for(int k=0; k<e-b; k++){
        int in_Ai = A[b+k];
        int pos = b + ((k+e-m) % (e-b));
        auto itr = A.begin();
        rep(i,pos) itr++;
        A.insert(itr, in_Ai);
    }
}

void rotate2(vector<int> &A, int b, int m, int e){
    for(int k=0; k<e-b; k++){
        // int in_Ai = A[b+k];
        int pos = b + ((k+e-m) % (e-b));
        swap(A[b+k], A[pos]);
    }
}

int main()
{
    int n; cin >> n;
    vector<int> A(n);
    rep(i,n){
        int Ai; cin >> Ai;
        A[i] = Ai;
    }
    int q; cin >> q;
    rep(i,q){
        int b, m, e; cin >> b >> m >> e;
        rotate2(A, b, m, e);
    }
    rep(i,n){
        cout << A[i];
        if(i != n-1) cout << " ";
    }
    cout << endl;
}