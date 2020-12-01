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

const int INF = 1000100100;

int round255(int y, int c){
    if(y+c > 255) return 255;
    else if(y+c < 0) return 0;
    else return y+c; 
}

int main()
{
    while(true){
        int n, m; cin >> n >> m;

        if(n == 0 && m == 0) break;

        int c[m];
        rep(i,m) cin >> c[i];

        int x[n];
        rep(i,n) cin >> x[i];

        int dp[m];
        int pre_dp[m];

        int y[m], pre_y[m];

        rep(i,n){
            rep(j,m){
                dp[j] = INF;
                if(i == 0){
                    y[j] = round255(128, c[j]);
                    dp[j] = (x[i]-y[j])*(x[i]-y[j]);
                }else{
                    rep(k,m){
                        if(dp[j] > pre_dp[k]+(x[i]-round255(pre_y[k], c[j]))*(x[i]-round255(pre_y[k], c[j]))){
                            dp[j] = pre_dp[k]+(x[i]-round255(pre_y[k], c[j]))*(x[i]-round255(pre_y[k], c[j]));
                            y[j] = round255(pre_y[k], c[j]);
                        }
                    }
                }
            }

            rep(j,m){
                pre_dp[j] = dp[j];
                pre_y[j] = y[j];
            }
        }

        int ans = INF;
        rep(i,m) ans = min(ans, dp[i]);
        cout << ans << endl;
    }
}

/*

2 7
4
2
1
0
-1
-2
-4
131
137
2 7
4
2
1
0
-1
-2
-4
131
123
10 7
-4
-2
-1
0
1
2
4
132
134
135
134
132
128
124
122
121
122
5 1
255
0
0
0
0
0
4 1
0
255
0
255
0
0 0

*/