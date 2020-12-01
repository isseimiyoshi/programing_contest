#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;
const int INF = 1000100100;

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

const int MAX_N = 305;
int n;

double dp[MAX_N][MAX_N][MAX_N];

void init(){
    rep(i,MAX_N){
        rep(j,MAX_N){
            rep(k,MAX_N){
                dp[i][j][k] = -1.0;
            }
        }
    }
}

double solve(int n1, int n2, int n3){
    if(dp[n1][n2][n3]>=0) return dp[n1][n2][n3];
    double res = 1/(1-(double)(n-n1-n2-n3)/n);
    if(n1>0) res += solve(n1-1,n2,n3)*n1/n/(1-(double)(n-n1-n2-n3)/n);
    if(n2>0) res += solve(n1+1,n2-1,n3)*n2/n/(1-(double)(n-n1-n2-n3)/n);
    if(n3>0) res += solve(n1,n2+1,n3-1)*n3/n/(1-(double)(n-n1-n2-n3)/n);
    return dp[n1][n2][n3] = res;
}

int main()
{
    cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];

    int n1 = 0, n2 = 0, n3 = 0;
    rep(i,n){
        if(a[i] == 1) n1++;
        else if(a[i] == 2) n2++;
        else n3++;
    }

    init();
    double res = solve(n1,n2,n3);
    cout << res << endl;
    
}