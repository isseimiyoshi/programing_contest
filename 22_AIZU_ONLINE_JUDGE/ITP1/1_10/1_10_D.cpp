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
    int n; cin >> n;
    double x[n], y[n];
    for(int i=0; i<n; i++){
        double xi; cin >> xi;
        x[i] = xi;
    }
    for(int i=0; i<n; i++){
        double yi; cin >> yi;
        y[i] = yi;
    }
    double dim1 = 0, dim2 = 0, dim3 = 0;
    double dimINF = 0;
    for(int i=0; i<n; i++){
        dim1 += fabs(x[i]-y[i]);
        dim2 += fabs(x[i]-y[i])*fabs(x[i]-y[i]);
        dim3 += fabs(x[i]-y[i])*fabs(x[i]-y[i])*fabs(x[i]-y[i]);
        if(dimINF < fabs(x[i]-y[i])) dimINF = fabs(x[i]-y[i]);
    }
    dim2 = sqrt(dim2);
    dim3 = pow(dim3, 1.0/3.0);
    printf("%.5lf\n%.5lf\n%.5lf\n%.5lf\n", dim1, dim2, dim3, dimINF);
}