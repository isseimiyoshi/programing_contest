#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

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

const double eps = 0.000000000001;
const double INF = 1000100100100100100;

int main()
{
    int n; cin >> n;
    vector<double> A(n),B(n);
    vector<double> A_B(n), minB_A(n);
    rep(i,n){
        cin >> A[i] >> B[i];
        if(B[i] == 0){
            A_B[i] = INF;
        }else{
            A_B[i] = A[i]/B[i];
        }
        if(A[i] == 0){
            minB_A[i] = INF;
        }else{
            minB_A[i] = (-1.0)*B[i]/A[i];
        }
    }
}