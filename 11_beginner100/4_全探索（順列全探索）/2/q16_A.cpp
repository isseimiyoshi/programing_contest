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
    int n; cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    vector<int> v(n);
    rep(i,n){
        int pi; cin >> pi; pi--;
        p[i] = pi;
    }
    rep(i,n){
        int qi; cin >> qi; qi--;
        q[i] = qi;
    }
    rep(i,n) v[i] = i;

    int cnt = 0;
    int a, b;
    do{
        if(p == v) a = cnt;
        if(q == v) b = cnt;
        cnt++;
    }while(next_permutation(v.begin(), v.end()));

    cout << abs(a-b) << endl;
}