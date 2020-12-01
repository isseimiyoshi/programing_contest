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
    string S; cin >> S;
    int ans = -1;
    for(int i=0; i<S.size(); i++){
        for(int j=i; j<S.size(); j++){
            int len = 0;
            for(int k=i; k<=j; k++){
                if(S[k] == 'A' || S[k] == 'T' || S[k] == 'C' || S[k] == 'G'){
                    len++;
                }else{
                    break;
                }
            }
            ans = max(ans, len);
        }
    }
    cout << ans << endl;
}