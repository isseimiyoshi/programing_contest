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

const double ips = 0.0000001;

int main()
{
    int N, M; cin >> N >> M;
    tuple<double, double, double> T[N+M];
    rep(i,N){
        double xi, yi, ri;
        cin >> xi >> yi >> ri;
        T[i] = make_tuple(xi, yi, ri);
    }
    for(int i=N; i<N+M; i++){
        double xi, yi;
        cin >> xi >> yi;
        T[i] = make_tuple(xi, yi, 0);
    }
    double minr = 1000000;
    rep(i,N+M){
        double xi, yi, ri;
        tie(xi, yi, ri) = T[i];
        for(int j=i+1; j<N+M; j++){
            if(i == j) continue;
            double xj, yj, rj;
            tie(xj, yj, rj) = T[j];
            if(ri > ips && rj > ips){
                double mi = min(ri, rj);
                if(minr > mi) minr = mi;
            }else if(ri < ips && rj < ips){
                double dist = sqrt((xi - xj)*(xi - xj) + (yi - yj)*(yi - yj));
                // printf("%5.6f\n", dist);
                if(minr > (dist/2)) minr = dist/2;
            }else{
                if(ri < rj) swap(ri, rj);   // rjの値を0にする
                double dist = sqrt((xi - xj)*(xi - xj) + (yi - yj)*(yi - yj));
                if(minr > (dist - ri)) minr = (dist - ri);
            }
        }
    }
    printf("%5.6f\n", minr);
}