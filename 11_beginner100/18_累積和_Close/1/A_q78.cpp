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

int main()
{
    int M, N; cin >> M >> N;
    int K; cin >> K;
    int J[M][N], O[M][N], I[M][N];
    rep(i,M){
        string str; cin >> str;
        // cout << str << endl;
        rep(j,N){
            if(j == 0){
                if(str[j] == 'J') J[i][j] = 1, O[i][j] = 0, I[i][j] = 0;
                else if(str[j] == 'O') J[i][j] = 0, O[i][j] = 1, I[i][j] = 0;
                else J[i][j] = 0, O[i][j] = 0, I[i][j] = 1;
            }else{
                if(str[j] == 'J') J[i][j] = J[i][j-1]+1, O[i][j] = O[i][j-1], I[i][j] = I[i][j-1];
                else if(str[j] == 'O') J[i][j] = J[i][j-1], O[i][j] = O[i][j-1]+1, I[i][j] = I[i][j-1];
                else J[i][j] = J[i][j-1], O[i][j] = O[i][j-1], I[i][j] = I[i][j-1]+1;
            }
        }
    }
    /*
    rep(i,M){
        rep(j,N){
            cout << J[i][j] << " ";
        }cout << endl;
    }
    rep(i,M){
        rep(j,N){
            cout << O[i][j] << " ";
        }cout << endl;
    }
    rep(i,M){
        rep(j,N){
            cout << I[i][j] << " ";
        }cout << endl;
    }
    */
    rep(_,K){
        int a, b, c, d; cin >> a >> b >> c >> d;
        --a; --b; --c; --d;
        printf("%d %d %d %d\n", a, b, c, d);
        int sj=0, so=0, si=0;
        for(int i=b; i<=d; i++){
            sj += J[i][c] - J[i][a-1];
            so += O[i][c] - O[i][a-1];
            si += I[i][c] - I[i][a-1];
        }
        printf("%d %d %d\n", sj, so, si);
    }
}