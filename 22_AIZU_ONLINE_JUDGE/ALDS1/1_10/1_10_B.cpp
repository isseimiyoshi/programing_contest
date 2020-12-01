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

const int MAX_N = 110;
int p[MAX_N];
int m[MAX_N][MAX_N];
int n;
const int INFTY = pow(10, 8);

void matrixChainMultiplication(){
    for(int i=0; i<=n; i++){
        m[i][i] = 0;
    }
    for(int l=1; l<=n; l++){ // lは対象とする行列の数
        for(int i=0; i<n-l+1; i++){ //iの上限値は、対象とする行列の個数によって変化する
            int j = i+l-1;
            m[i][j] = INFTY;
            for(int k=i; k = i<j-1; k++){
                m[i][j] = min(m[i][j], m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
            }
        }
    }
}

int main()
{
    cin >> n;
    rep(i, n){
        int p1, p2;
        cin >> p1 >> p2;
        p[i] = p1;
        if(i == n-1) p[i+1] = p2;
    }
    matrixChainMultiplication();
    cout << m[1][n] << endl;
}