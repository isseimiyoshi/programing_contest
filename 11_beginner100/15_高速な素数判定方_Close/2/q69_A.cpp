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
    int max_n = 100000;
    bool isprime[max_n+1];
    rep(i,max_n+1) isprime[i] = true;

    isprime[0] = isprime[1] = false;
    for(int i=4; i<=max_n; i+=2){
        isprime[i] = false;
    }

    // エラトステネスの篩
    for(int i=3; i*i<=max_n; i+=2){
        if(isprime[i]){
            int j=i+i;
            while(j<=max_n){
                isprime[j] = false;
                j += i;
            }
        }
    }

    int prime_num[max_n+1];
    prime_num[0] = prime_num[1] = prime_num[2] = 0;
    for(int i=3; i<=max_n; i++){
        if(i%2 == 1){
            if(isprime[i] && isprime[(i+1)/2]) prime_num[i] = prime_num[i-1]+1;
            else prime_num[i] = prime_num[i-1];
        }
        else prime_num[i] = prime_num[i-1];
    }

    int q; cin >> q;
    rep(_,q){
        int l, r; cin >> l >> r;
        //cout << prime_num[l] << endl;
        //cout << prime_num[r] << endl;
        cout << (prime_num[r] - prime_num[l-1]) << endl;
    }
}