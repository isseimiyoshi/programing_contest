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
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    for(char c1 ='0'; c1<='9'; c1++){
        for(char c2 ='0'; c2<='9'; c2++){
            for(char c3 ='0'; c3<='9'; c3++){
                bool isc1 = false, isc2 = false, isc3 = false;
                rep(i,n){
                    if(!isc1 && s[i] == c1){
                        isc1 = true;
                        continue;
                    }
                    if(isc1 && !isc2 && s[i] == c2){
                        isc2 = true;
                        continue;
                    }
                    if(isc2 && !isc3 && s[i] == c3){
                        isc3 = true;
                        break;
                    }
                }
                if(isc1 && isc2 && isc3) ans++;
            }
        }
    }
    cout << ans << endl;
}