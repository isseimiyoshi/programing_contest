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

int main()
{
    int K, N; cin >> K >> N;
    int A[N];
    rep(i, N){
        int Ai; cin >> Ai;
        A[i] = Ai;
    }
    int max_dis = 0;
    rep(i, N){
        int dis;
        if(i != N-1){
            dis = A[i+1] - A[i];
            if(max_dis < dis) max_dis = dis;
        }else{
            dis = (K-A[i]) + A[0];
            if(max_dis < dis) max_dis = dis;
        }
    }
    cout << K - max_dis << endl;
}