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

bool is_prime(int n){
    for(int i=2; i*i<=n; i++){
        if(n % i == 0) return false;
    }
    return n != 1;  // n=1のときは例外となる
}

int main()
{
    int n; cin >> n;
    int count = 0;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        if(is_prime(x)) count += 1;
    }
    cout << count << endl;
}