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
    int a[3][3];
    rep(i,3) rep(j,3) cin >> a[i][j];
    int n; cin >> n;
    int b[n];
    rep(i,n) cin >> b[i];

    bool isa[3][3];
    rep(i,3) rep(j,3) isa[i][j] = false;

    rep(k,n){
        rep(i,3){
            rep(j,3){
                if(a[i][j] == b[k]){
                    isa[i][j] = true;
                }
            }
        }
    }
    /*
    rep(i,3){
        rep(j,3){
            cout << isa[i][j] << " ";
        }cout << endl;
    }
    */
    bool isbingo = false;


    rep(i,3){
        int cnt = 0;
        rep(j,3){
            if(isa[i][j] == true){
                cnt++;
            }
        }
        if(cnt == 3) isbingo = true;
    }

    rep(i,3){
        int cnt = 0;
        rep(j,3){
            if(isa[j][i] == true){
                cnt++;
            }
        }
        if(cnt == 3) isbingo = true;
    }

    int cnt1 = 0;
    int cnt2 = 0;
    rep(i,3){
        if(isa[i][i] == true) cnt1++;
        if(isa[3-1-i][i] == true) cnt2++;
    }
    if(cnt1 == 3 || cnt2 == 3) isbingo = true;

    if(isbingo) cout << "Yes" << endl;
    else cout << "No" << endl;
}
