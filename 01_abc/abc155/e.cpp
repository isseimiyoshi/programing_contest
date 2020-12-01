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
    string s; cin >> s;
    int n = s.size();

    ll res = 0;
    rep(i,n){
        int si = s[i]-'0';
        if(si>5){
            res += 1;
            if(i == n-1){
                res += 10-si;
            }else{
                if((s[i+1]-'0')>=5) res += 10-si-1;
                else{
                    res += 10-si;
                    continue;
                }
            }
        }else{
            res += si;
            if((s[i+1]-'0')>=5 && i != n-1) res += 1;
        }
        if(i != n-1){
            ++i;
            while(i<n){
                if((s[i]-'0') >=5){
                    if(i == n-1){
                        res += 10-(s[i]-'0');
                        break;
                    }else{
                        res += 10-(s[i]-'0')-1;
                        ++i;
                    }
                }else{
                    res += 10-(s[i]-'0');
                    break;
                }

            }
        }
        // cout << si+1 << endl;
    }
    cout << res << endl;
}