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

int main()
{
    int N; cin >> N;
    int cntAC= 0;
    int cntWA= 0;
    int cntTLE= 0;
    int cntRE= 0;
    rep(i,N){
        string S; cin >> S;
        if(S == "AC") cntAC++;
        else if(S == "WA") cntWA++;
        else if(S == "TLE") cntTLE++;
        else cntRE++;
    }
    printf("AC x %d\n", cntAC);
    printf("WA x %d\n", cntWA);
    printf("TLE x %d\n", cntTLE);
    printf("RE x %d\n", cntRE);
}