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
    int c[n];
    rep(i,n) cin >> c[i];
    vector<P> goseki;   // Pair<(碁石の色, 連続している数)
    int ind = -1;
    rep(i,n){
        if(i == 0){
            goseki.push_back(make_pair(c[i], 1));
            ind++;
        }else{
            if((i+1) % 2 == 1){
                if(goseki[ind].first == c[i]) goseki[ind].second += 1;
                else goseki.push_back(make_pair(c[i], 1)), ++ind;
            }else{
                if(goseki[ind].first != c[i]){
                    int before2 = goseki[ind-1].second;
                    int before1 = goseki[ind].second;
                    goseki[ind-1].second = 0;
                    goseki[ind].second = 0;
                    // goseki.pop_back();goseki.pop_back();
                    goseki.push_back(make_pair(c[i], 1+before1+before2));
                    ++ind;
                }else{
                    goseki[ind].second += 1;
                }
            }
        }
    }
    int sum = 0;
    rep(i,ind){
        if(goseki[i].first == 0) sum += goseki[i].second;
    }
    cout << sum << endl;
}