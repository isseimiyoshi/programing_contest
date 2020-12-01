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
    int n; cin >> n;
    int k; cin >> k;
    bitset<18> T(0);
    rep(i,k){
        int bi; cin >> bi;
        T.set(bi);
    }
    for(ll i=0; i<pow(2,n); i++){
        if(i == 0){
            printf("0:\n");
        }else{
            bitset<18> A(i);
            if((A & T) == A){
                printf("%d:", i);
                rep(j,18){
                    if(A.test(j)) printf(" %d", j);
                }
                cout << endl;
            }
        }
    }
}