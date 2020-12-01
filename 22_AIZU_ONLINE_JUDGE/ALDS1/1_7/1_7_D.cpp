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

struct Node { int parent, left, right; };
const int MAX = pow(10, 7);
const int NIL = -1;

void make_T(Node &T[], int Pre[], int In[], int n){
    int r = Pre[0];
}

int main()
{
    Node T[MAX];    // 節点のノード情報を格納する
    int n; cin >> n;
    vector<int> Pre(n), In(n);
    rep(i, n){
        int Prei; cin >> Prei;
        Pre[i] = Prei;
    }
    rep(i, n){
        int Ini; cin >> Ini;
        In[i] = Ini;
    }
}