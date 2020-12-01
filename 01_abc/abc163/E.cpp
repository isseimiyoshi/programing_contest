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

const int MAX_N = 2020;
ll dp[MAX_N][MAX_N];
ll A[MAX_N];

int main()
{
    int N; cin >> N;
    rep(i, N) scanf("%ld", &A[i]);
    rep(i, N){
        rep(j, N){
            if(i == j) dp[i][j] = 0;
            else dp[i][j] = A[i]*abs(i-j);
        }
    }
    
}