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
    int N; string S;
    cin >> N; cin >> S;
    int count = 0;
    for(int i=1; i<N; i++){
        for(int j=i; j<N; j++){
            char Si = (char)S[i-1]; char Sj = (char)S[j-1];
            if(Si == Sj) continue;
            for(int k=j; k<=N; k++){
                if(j-i != k-j){
                    char Sk = (char)S[k-1];
                    if(Sj == Sk || Sk == Si){
                        // cout << i << j << k << endl;
                        continue;
                    }else{
                        count += 1;
                    }
                }
            }
        }
    }
    cout << count << endl;
}