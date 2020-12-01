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

int main()
{
    bitset<64> A(0);
    int q; cin >> q;
    rep(_,q){
        int query; cin >> query;
        if(query == 0){
            int i; cin >> i;
            if(A.test(i)) cout << 1 << endl;
            else cout << 0 << endl;
        }else if(query == 1){
            int i; cin >> i;
            A.set(i);
        }else if(query == 2){
            int i; cin >> i;
            A.set(i,0);
        }else if(query == 3){
            int i; cin >> i;
            A.flip(i);
        }else if(query == 4){
            if(A.all()) cout << 1 << endl;
            else cout << 0 << endl;
        }else if(query == 5){
            if(A.any()) cout << 1 << endl;
            else cout << 0 << endl;
        }else if(query == 6){
            if(!A.any()) cout << 1 << endl;
            else cout << 0 << endl;
        }else if(query == 7){
            cout << A.count() << endl;
        }else if(query == 8){
            cout << (A.to_ullong()) << endl;
        }
    }
}