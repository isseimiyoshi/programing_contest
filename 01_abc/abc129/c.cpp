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

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

const ll prime = pow(10,9)+7;

int main()
{
    int N,M; cin >> N >> M;
    set<int> A;
    vector<int> A2;
    rep(i,M){
        int a; cin >> a;
        if(a-2 >= 0) A.insert(a-2);
        if(a-1 >= 0) A.insert(a-1);
        A.insert(a);
        A2.push_back(a);
    }
    if(!A.count(N-1)) A.insert(N-1);
    bool isSafe = true; int ori_a2 = -100000;
    rep(i,A2.size()){
        if(A2[i] - ori_a2 == 1) isSafe = false;
        else ori_a2 = A2[i];
    }
    if(isSafe){
        ll beki = N - A.size();
        ll res = 1;
        rep(i,beki){
            res *= 2;
            res %= prime;
        }
        cout << res << endl;
    }else{
        cout << 0 << endl;
    }
}