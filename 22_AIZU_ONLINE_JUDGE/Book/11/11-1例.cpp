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

const int MAX_N = 20, MAX_M = 200;
bool dp[MAX_N][MAX_M];
vector<int> A;
int n; 

bool solve(int i, int m){
    if(dp[i][m]) return dp[i][m];

    if(m == 0){
        dp[i][m] = true;
    }else if(i >= n){
        dp[i][m] = false;
    }else if(solve(i+1, m)){
        dp[i][m] = true;
    }else if(solve(i+1, m - A[i])){
        dp[i][m] = true;
    }else{
        dp[i][m] = false;
    }

    return dp[i][m];
}

int main()
{
    cin >> n;
    rep(i,n){
        int Ai; cin >> Ai;
        A.push_back(Ai);
    }
    int m; cin >> m;
    // 初期化
    rep(i,n){
        rep(j,m){
            dp[i][j] = false;
        }
    }
    rep(_, m){
        int mi; cin >> mi;
        if(solve(0,mi)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}