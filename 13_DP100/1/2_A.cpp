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

const int MAX_N = 1100000;



int isn(int x){
    int ori_x = x;
    int add = 0;
    while(x>=10){
        add += (x%10);
        x /= 10;
    }
    add += x;
    return (ori_x+add);
}

int main()
{
    int n; cin >> n;

    int dp[MAX_N];
    rep(i,MAX_N) dp[i] = 0;

    for(int i=n-1; i>0; i--){
        int ans = isn(i);
        // cout << ans << endl;
        if(ans == n){
            dp[i] = 1;
            continue;
        }
        if(dp[ans] == 1){
            dp[i] = 1;
        }
    }
    int res = 0;
    for(int i=n-1; i>0; i--) res += dp[i];
    res++;

    cout << res << endl;
}