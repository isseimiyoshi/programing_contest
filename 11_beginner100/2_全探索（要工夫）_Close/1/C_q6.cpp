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

const int INF = 30010;

int main()
{   
    int N; string s;
    cin >> N >> s;
    int sum = 0;
    for(char i='0'; i<='9'; i++){
        for(char j='0'; j<='9'; j++){
            for(char k='0'; k<='9'; k++){
                int p1 = INF, p2 = INF;
                rep(l,s.size()){
                    if(s[l] == i && p1 == INF){ p1 = l; continue; }
                    if(s[l] == j && p1 < p2 && p2 == INF){ p2 = l; continue; }
                    if(s[l] == k && p2 < INF){
                        // cout << i << j << k << endl;
                        sum++;
                        break;
                    }
                }
            }
        }
    }
    cout << sum << endl;
}