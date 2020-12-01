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

const double INF = 1000100100;

double dis(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main()
{
    int n, m; cin >> n >> m;
    int xn[n], yn[n], rn[n];
    int xm[m], ym[m];

    rep(i,n) cin >> xn[i] >> yn[i] >> rn[i];
    rep(i,m) cin >> xm[i] >> ym[i];

    double minr = INF;
    double r = INF;

    if(m == 0){
        rep(j,n){
            minr = min(minr, (double)rn[j]);
        }
    }else{
        rep(i,m){
            rep(j,n){
                r = dis(xm[i], ym[i], xn[j], yn[j]) - (double)rn[j];
                if(minr > r) minr = r;
            }
        }
        rep(i,m){
            for(int j=i+1; j<m; j++){
                r = dis(xm[i], ym[i], xm[j], ym[j]) / 2;
                // if(i == 2 && j == 3) printf("%d %d %d %d : %.6f\n", xm[i], ym[i], xm[j], ym[j], r);
                if(minr > r) minr = r;
            }
        }
    }

    
    printf("%.6f\n", minr);
}