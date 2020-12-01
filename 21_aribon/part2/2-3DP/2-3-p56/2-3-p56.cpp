#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
string s, t;
const int MAX_N = 1000, MAX_M = 1000;
int dp[MAX_N+1][MAX_M+1];

void LCS(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i] == t[j]){
                dp[i+1][j+1] = max(dp[i][j]+1, max(dp[i][j+1], dp[i+1][j]));
            }else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    printf("%d\n", dp[n][m]);
}

/*
input 

8 10
AUNFIIO
UELFPRTOE

4 4
abcd
becd
*/

int main()
{
    cin >> n >> m;
    cin >> s >> t;
    for(int i=0; i<n; i++) dp[i][0] = 0;
    for(int i=0; i<n; i++) dp[0][i] = 0;
    LCS();
}