#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
using P = pair<ll, ll>;

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



int main()
{
    vector<int> simen;
    int s = 1;
    while(s*(s+1)*(s+2)/6 <= 1000000){
        simen.push_back(s*(s+1)*(s+2)/6);
        s++;
    }
    s--;

    vector<int> simen_odd;
    int s2 = 1;
    while(s2*(s2+1)*(s2+2)/6 <= 1000000){
        if(s2*(s2+1)*(s2+2)/6 % 2 == 1){
            simen_odd.push_back(s2*(s2+1)*(s2+2)/6);
        }
        s2++;
    }
    int s_odd = simen_odd.size();



    int dp[1000001];
    rep(i,1000001) dp[i] = i;
    
    for(int i=2; i<1000001; i++){
        for(int j=1; j<s; j++){
            if(i>=simen[j]) dp[i] = min(dp[i], dp[i-simen[j]]+1);
        }
    }

    int dp_odd[1000001];
    rep(i,1000001) dp_odd[i] = i;
    
    for(int i=2; i<1000001; i++){
        for(int j=1; j<s_odd; j++){
            if(i>=simen_odd[j]) dp_odd[i] = min(dp_odd[i], dp_odd[i-simen_odd[j]]+1);
        }
    }

    while(true){
        int n; cin >> n;
        if(n == 0) break;

        printf("%d %d\n", dp[n], dp_odd[n]);
    }
}