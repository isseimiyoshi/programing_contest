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
    int m, n; cin >> m >> n;
    int k; cin >> k;

    int c[m][n];
    rep(i,m){
        rep(j,n){
            char moji; cin >> moji;
            if(moji == 'J') c[i][j] = 1;
            else if(moji == 'O') c[i][j] = 2;
            else c[i][j] = 3;
        }
    }

    int numJ[m][n];
    int numO[m][n];
    int numI[m][n];
    rep(i,m) rep(j,n){
        numJ[i][j] = 0;
        numO[i][j] = 0;
        numI[i][j] = 0;
    }

    rep(i,m){
        rep(j,n){
            if(j == 0){
                if(i == 0){
                    if(c[i][j] == 1) numJ[i][j] = 1;
                    else if(c[i][j] == 2) numO[i][j] = 1;
                    else numI[i][j] = 1;
                }else{
                    numJ[i][j] = numJ[i-1][j], numO[i][j] = numO[i-1][j], numI[i][j] = numI[i-1][j];
                    if(c[i][j] == 1) numJ[i][j] += 1;
                    else if(c[i][j] == 2) numO[i][j] += 1;
                    else numI[i][j] += 1;
                }
            }else{
                if(i == 0){
                    numJ[i][j] = numJ[i][j-1], numO[i][j] = numO[i][j-1], numI[i][j] = numI[i][j-1];
                    if(c[i][j] == 1) numJ[i][j] += 1;
                    else if(c[i][j] == 2) numO[i][j] += 1;
                    else numI[i][j] += 1;
                }else{
                    numJ[i][j] = numJ[i-1][j] + numJ[i][j-1] - numJ[i-1][j-1];
                    numO[i][j] = numO[i-1][j] + numO[i][j-1] - numO[i-1][j-1];
                    numI[i][j] = numI[i-1][j] + numI[i][j-1] - numI[i-1][j-1];
                    if(c[i][j] == 1) numJ[i][j] += 1;
                    else if(c[i][j] == 2) numO[i][j] += 1;
                    else numI[i][j] += 1;
                }
            }
        }
    }

    rep(i,k){
        int a, b, c, d; cin >> a >> b >> c >> d;
        --a, --b, --c, --d;
        if(a == 0 && b == 0){
            printf("%d %d %d\n", numJ[c][d], numO[c][d], numI[c][d]);
        }else if(a == 0){
            printf("%d %d %d\n", numJ[c][d]-numJ[c][b-1], numO[c][d]-numO[c][b-1], numI[c][d]-numI[c][b-1]);
        }else if(b == 0){
            printf("%d %d %d\n", numJ[c][d]-numJ[a-1][d], numO[c][d]-numO[a-1][d], numI[c][d]-numI[a-1][d]);
        }else{
            printf("%d %d %d\n", numJ[c][d]-numJ[a-1][d]-numJ[c][b-1]+numJ[a-1][b-1], numO[c][d]-numO[a-1][d]-numO[c][b-1]+numO[a-1][b-1], numI[c][d]-numI[a-1][d]-numI[c][b-1]+numI[a-1][b-1]);
        }
    }
}