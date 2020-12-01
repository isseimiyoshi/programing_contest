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
    ll n; cin >> n;

    string S;

    while(true){
        if(n <= 26){
            S += (char)('a'+n-1);
            break;
        }
        if(n%26 == 0){
            S += 'z';
            n -= 26;
        }else{
            S += (char)('a'+(n%26)-1);
            n -= (n%26);
        }
        n /= 26;
    }

    /*
    while(true){
        if(n <= 26){
            // cout << (char)('a'+n-1) << endl;
            S += (char)('a'+n-1);
            break;
        }else{
            // cout << (char)('a'+(n%26)-1);
            if(n%26 == 0){
                S += (char)('a'+25);
            }else{
                S += (char)('a'+(n%26)-1);
            }
            n /= 26;
        }
    }
    */

    int Ss = S.size();
    for(int i=Ss-1; i>=0; i--){
        cout << S[i];
    }cout << endl;
}