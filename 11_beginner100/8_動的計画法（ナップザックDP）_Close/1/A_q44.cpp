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

const int MAX_N = 1000000;
const int INF = 1000100100;

int main()
{
    int ans = -1;
    int n = 0;
    int n_odd = 0;
    vector<int> pol;
    vector<int> pol_odd;
    while(true){
        n++;
        ans = n*(n+1)*(n+2)/6;
        if(ans <= 1000000){
            pol.push_back(ans);
            if(ans % 2 == 1){
                pol_odd.push_back(ans);
                n_odd++;
            }
        }else{
            n--;
            break;
        }
    }

    /*
    vector<vector<int> > dp(n, vector<int>(MAX_N+1));
    rep(i,n) rep(j,MAX_N+1) dp[i][j] = INF;
    rep(j,MAX_N+1) dp[0][j] = j;
    */

    vector<int> dp(MAX_N+1);
    rep(i,MAX_N+1) dp[i] = i;

    for(int i=1; i<n; i++){
        rep(j,MAX_N+1){
            if(j<pol[i]) continue;
            else{
                // dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-pol[i]] + 1), dp[i][j-pol[i]]+1);
                dp[j] = min(dp[j-pol[i]]+1, dp[j]);
            }
        }
    }

    /*
    vector<vector<int> > dp_odd(n_odd, vector<int>(MAX_N+1));
    rep(i,n_odd) rep(j,MAX_N+1) dp_odd[i][j] = INF;
    rep(j,MAX_N+1) dp_odd[0][j] = j;
    */

    vector<int> dp_odd(MAX_N+1);
    rep(i,MAX_N+1) dp_odd[i] = i;

    for(int i=1; i<n_odd; i++){
        rep(j,MAX_N+1){
            if(j<pol_odd[i]) continue;
            else{
                dp_odd[j] = min(dp_odd[j-pol_odd[i]]+1, dp_odd[j]);
            }
        }
    }    
    

    
    while(true){
        int N; cin >> N;

        if(N == 0) break;

        printf("%d %d\n", dp[N], dp_odd[N]);
    }
    
}