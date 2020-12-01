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

int gcd(int a, int b, int c){
    int gcd_ab = 0;
    if(a<b) swap(a,b);
    for(int i=1; i<=b; i++){
        if(a % i == 0){
            if(b % i == 0) gcd_ab = i;
        }
    }
    int gcd_abc = 0;
    if(gcd_ab>c) swap(gcd_ab, c);
    for(int i=1; i<=gcd_ab; i++){
        if(c % i == 0){
            if(gcd_ab % i == 0){
                gcd_abc = i;
            }
        }
    } 
    return gcd_abc;
}

int main()
{
    int K; cin >> K;
    ll sum = 0;
    for(int i=1; i<=K; i++){
        for(int j=1; j<=K; j++){
            for(int k=1; k<=K; k++){
                sum += gcd(i, j, k);
            }
        }
    }
    cout << sum << endl;
}