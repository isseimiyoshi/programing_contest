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

int main()
{
    int N;
    ll A[N];
    for(int i=0; i<N; i++){
        ll Ai; cin >> Ai;
        A[i] = Ai;
    }
    if(N % 2 == 0){
        
    }else{
        ll max_sum = (-1)*pow(10, 15);

    }

    cout << max_num << endl;
}