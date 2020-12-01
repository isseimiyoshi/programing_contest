#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

bool judge(int i, int j, int k){
    if(i>j) swap(i, j);
    if(j>k) swap(j, k);
    if(i>j) swap(i, j);
    if(j-i != k-j) return true;
    else return false;
}

/*

10
RGBGGRBBGR

*/

int main()
{
    int N; string S;
    cin >> N >> S;
    vector<int> R, B, G;
    for(int i=0; i<N; i++){
        char Si = (char)S[i];
        if(Si == 'R') R.push_back(i);
        else if(Si == 'B') B.push_back(i);
        else G.push_back(i);
    }
    int count = 0;
    for(int i: R){
        for(int j: B){
            for(int k: G){
                if(judge(i, j, k)) count += 1;
            }
        }
    }
    cout << count << endl;
}