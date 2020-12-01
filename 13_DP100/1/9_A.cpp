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

const int MAX_N = 1005;

int n;
string s;

int dp[MAX_N];

void init(){
    rep(i,MAX_N) dp[i] = INF;
}

void solve(string L, string R){
    dp[0] = 1;
    for(int i=1; i<n; i++){
        string prev = "";
        prev += s[i-1];
        prev += s[i];
        if(L == prev || R == prev){
            if(i == 1) dp[1] = 1;
            else{
                dp[i] = min(dp[i-2]+1, min(dp[i-1]+1, dp[i]));
            }
        }else{
            dp[i] = min(dp[i-1]+1, dp[i]);
        }
    }
}

int main()
{
    cin >> n;
    cin >> s;

    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<char> moji = {'A', 'B', 'X', 'Y'};

    int res = INF;

    do{
        string L = "", R = "";
        L += moji[v[0]%4];
        L += moji[v[1]%4];
        R += moji[v[2]%4];
        R += moji[v[3]%4];

        // cout << L << " " << R << " " << endl;

        init();

        solve(L, R);

        res = min(res, dp[n-1]);
    } while(next_permutation(v.begin(), v.end()));

    cout << res << endl;
}