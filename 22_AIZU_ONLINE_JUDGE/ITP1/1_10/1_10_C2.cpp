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
    while(true){
        int n; cin >> n;
        double S[n];
        if(n == 0) break;
        int sum = 0;
        for(int i=0; i<n; i++){
            int si; cin >> si;
            sum += si;
            S[i] = si;
        }
        double m = sum / n;
        double sum2 =0.0;
        for(int i=0; i<n; i++) sum2 += (S[i] - m)*(S[i] - m);
        double sigma = sqrt(sum2/n);
        printf("%.5lf\n", sigma);
    }
}