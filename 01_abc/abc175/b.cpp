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
    vector<int> l(n);
    rep(i,n) cin >> l[i];

    ll cnt = 0;
    rep(i,n){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(l[i] != l[j] && l[i] != l[k] && l[k] != l[j]){
                    vector<int> sl;
                    sl.push_back(l[i]);
                    sl.push_back(l[j]);
                    sl.push_back(l[k]);
                    sort(sl.begin(), sl.end());
                    if(sl[2] < sl[0]+sl[1]){
                        cnt++;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}