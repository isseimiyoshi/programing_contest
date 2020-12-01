#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

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

const double lam = 0.000001;

int main()
{
    int X; cin >> X;
    double an = 0, bn = 0;
    int K = 0;
    double theta = M_PI/2;
    while(true){
        /*
        double an_1 = an*cos(M_PI*X/180) - bn*sin(M_PI*X/180) + an;
        double bn_1 = an*sin(M_PI*X/180) + bn*cos(M_PI*X/180) + bn;
        */
        theta += M_PI*X/180;
        double an_1 = cos(theta) + an;
        double bn_1 = sin(theta) + bn;
        K += 1;
        if(abs(an_1)<lam && abs(bn_1)<lam){
            break;
        }else{
            an = an_1;
            bn = bn_1;
        }
    }
    cout << K << endl;
}