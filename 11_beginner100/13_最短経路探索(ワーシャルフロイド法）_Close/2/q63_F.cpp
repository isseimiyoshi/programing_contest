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

const int INF = 1000100100;

int main()
{
    int n; cin >> n;
    int a[n][n];
    rep(i,n){
        rep(j,n){
            cin >> a[i][j];
        }
    }

    bool exist = true;
    rep(k,n){
        rep(i,n){
            rep(j,n){
                if(a[i][j] > a[i][k]+a[k][j]){
                    exist = false;
                    break;
                }
            }
        }
    }

    if(exist){
        rep(k,n){
            rep(i,n){
                rep(j,n){
                    if(i == j || j == k || k == i) continue;
                    if(a[i][j] == a[i][k]+a[k][j]){
                        a[i][j] = INF;
                    }
                }
            }
        }
        ll ans = 0;
        rep(i,n){
            for(int j=i+1; j<n; j++){
                if(a[i][j] == INF) continue;
                ans += a[i][j];
            }
        }
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }

    
}