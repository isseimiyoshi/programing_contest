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

int compare(vector<int> A, vector<int> B){
    if(A.size() >= B.size()){
        rep(i,B.size()){
            if(A[i] == B[i]){
                continue;
            }else if(A[i] > B[i]){
                return 0;
            }else{
                return 1;
            }
        }
        return 0;
    }else{
        rep(i,A.size()){
            if(A[i] == B[i]){
                continue;
            }else if(A[i] > B[i]){
                return 0;
            }else{
                return 1;
            }
        }
        return 1;
    }
}

int main()
{
    int n,m; cin >> n;
    vector<int> A(n);
    rep(i,n){
        int Ai; cin >> Ai;
        A[i] = Ai;
    }
    cin >> m;
    vector<int> B(m);
    rep(i,m){
        int Bi; cin >> Bi;
        B[i] = Bi;
    }
    cout << compare(A, B) << endl;
}